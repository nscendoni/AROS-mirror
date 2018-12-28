/*  $Id: lha.c 30794 2009-03-08 02:19:07Z neil $
    lha module for DropArc

    XAD library system for archive handling
    Copyright (C) 1998 and later by Dirk St�cker <soft@dstoecker.de>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <string.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/xadmaster.h>

/************************************************************************/

#define MAXMATCH			256	/* formerly F (not more than UCHAR_MAX + 1) */
#define DICSIZ				(1 << 15)
#define TXTSIZ				(DICSIZ * 2 + MAXMATCH)
#define HSHSIZ				(1 << 15)
#define THRESHOLD			3	/* choose optimal value */
#define LIMIT				0x100
#define UCHAR_MAX			((1<<(sizeof(UBYTE)*8))-1)
#define USHRT_MAX			((1<<(sizeof(UWORD)*8))-1)
#define NC 				(UCHAR_MAX + MAXMATCH + 2 - THRESHOLD)
#define	MAX_DICBIT			15
#define NP				(MAX_DICBIT + 1)
#define CHAR_BIT  			8
#define NT				(USHRT_BIT + 3)
#define USHRT_BIT			16	/* (CHAR_BIT * sizeof(ushort)) */
#define NPT				0x80
#define CBIT				9	/* $\lfloor \log_2 NC \rfloor + 1$ */
#define TBIT 				5	/* smallest integer such that (1 << TBIT) > * NT */

static STRPTR  lh5_inmem;
static STRPTR  lh5_outmem;
static ULONG   origsize;
static ULONG   inpos;
static ULONG   compsize;
static ULONG   dicsiz;
static ULONG   txtsiz;
static UWORD   dicbit;
static UWORD   maxmatch;
static UWORD * hash;
static UWORD * prev;
static STRPTR  text;
static STRPTR  too_flag;
static STRPTR  buf;
static UWORD   bufsiz;
static LONG    unpackable;
static ULONG   count;
static ULONG   loc;
static ULONG   encoded_origsize;
static LONG    matchlen;
static ULONG   pos;
static ULONG   remainder;
static ULONG   hval;
static ULONG   matchpos;
static UWORD   cpos;
static UWORD   left[2 * NC - 1];
static UWORD   right[2 * NC - 1];
static UWORD   c_freq[2 * NC - 1];
static UWORD   p_freq[2 * NP - 1];
static UWORD   t_freq[2 * NT - 1];
static UWORD   pt_code[NPT];
static UWORD   c_code[NC];
static UWORD   output_pos;
static UWORD	  output_mask;
static UBYTE   pt_len[NPT];
static UBYTE   c_len[NC];
static LONG	  pbit;
static LONG	  np;
static UBYTE   depth;
static UWORD   len_cnt[17];
static WORD	  n;
static UWORD * sort;
static WORD    heapsize;
static WORD    heap[NC + 1];
static UWORD * freq;
static STRPTR  len;
static UBYTE   subbitbuf;
static UBYTE   bitcount;

/************************************************************************/

static ULONG getbytes(APTR mem, ULONG size)
{
  if(inpos+size > origsize)
    size = origsize-inpos;
  if(size)
  {
    CopyMem(lh5_inmem + inpos, mem, size);
    inpos += size;
  }
  return size;
}

static void putcode(UBYTE n, UWORD x)		/* Write rightmost n bits of x */
{
  while(n >= bitcount)
  {
    n -= bitcount;
    subbitbuf += x >> (USHRT_BIT - bitcount);
    x <<= bitcount;
    if(compsize < origsize)
      lh5_outmem[compsize++] = subbitbuf;
    else
      unpackable = 1;
    subbitbuf = 0;
    bitcount = CHAR_BIT;
  }
  subbitbuf += x >> (USHRT_BIT - bitcount);
  bitcount -= n;
}

static void putbits(UBYTE n, UWORD x)		/* Write rightmost n bits of x */
{
  x <<= USHRT_BIT - n;
  while(n >= bitcount)
  {
    n -= bitcount;
    subbitbuf += x >> (USHRT_BIT - bitcount);
    x <<= bitcount;
    if(compsize < origsize)
      lh5_outmem[compsize++] = subbitbuf;
    else
      unpackable = 1;
    subbitbuf = 0;
    bitcount = CHAR_BIT;
  }
  subbitbuf += x >> (USHRT_BIT - bitcount);
  bitcount -= n;
}

static void init_putbits(void)
{
  bitcount = CHAR_BIT;
  subbitbuf = 0;
}

static void make_code(LONG n, UBYTE len[], UWORD code[])
{
  UWORD weight[17];	/* 0x10000ul >> bitlen */
  UWORD start[17];	/* start code */
  UWORD j, k;
  LONG i;

  j = 0;
  k = 1 << (16 - 1);
  for(i = 1; i <= 16; i++)
  {
    start[i] = j;
    j += (weight[i] = k) * len_cnt[i];
    k >>= 1;
  }
  for(i = 0; i < n; i++)
  {
    j = len[i];
    code[i] = start[j];
    start[j] += weight[j];
  }
}

static void count_len(LONG i)		/* call with i = root */
{
  if(i < n)
    len_cnt[depth < 16 ? depth : 16]++;
  else
  {
    depth++;
    count_len(left[i]);
    count_len(right[i]);
    depth--;
  }
}

static void make_len(LONG root)
{
  LONG i, k;
  ULONG cum;

  for(i = 0; i <= 16; i++)
    len_cnt[i] = 0;
  count_len(root);
  cum = 0;
  for(i = 16; i > 0; i--)
  {
    cum += len_cnt[i] << (16 - i);
  }
  cum &= 0xffff;
  /* adjust len */
  if(cum)
  {
    len_cnt[16] -= cum;	/* always len_cnt[16] > cum */
    do
    {
      for(i = 15; i > 0; i--)
      {
	if(len_cnt[i])
	{
	  len_cnt[i]--;
	  len_cnt[i + 1] += 2;
	  break;
	}
      }
    } while(--cum);
  }
  /* make len */
  for(i = 16; i > 0; i--)
  {
    k = len_cnt[i];
    while(k > 0)
    {
      len[*sort++] = i;
      k--;
    }
  }
}

static void downheap(LONG i) /* priority queue; send i-th entry down heap */
{
  WORD j, k;

  k = heap[i];
  while((j = 2 * i) <= heapsize)
  {
    if(j < heapsize && freq[heap[j]] > freq[heap[j + 1]])
      j++;
    if(freq[k] <= freq[heap[j]])
      break;
    heap[i] = heap[j];
      i = j;
  }
  heap[i] = k;
}

static WORD make_tree(LONG nparm, UWORD freqparm[], UBYTE lenparm[], UWORD codeparm[]) /* make tree, calculate len[], return root */
{
  WORD i, j, k, avail;

  n = nparm;
  freq = freqparm;
  len = lenparm;
  avail = n;
  heapsize = 0;
  heap[1] = 0;
  for(i = 0; i < n; i++)
  {
    len[i] = 0;
    if(freq[i])
      heap[++heapsize] = i;
  }
  if(heapsize < 2)
  {
    codeparm[heap[1]] = 0;
    return heap[1];
  }
  for(i = heapsize / 2; i >= 1; i--)
    downheap(i);	/* make priority queue */
  sort = codeparm;
  do
  {			/* while queue has at least two entries */
    i = heap[1];	/* take out least-freq entry */
    if(i < n)
      *sort++ = i;
    heap[1] = heap[heapsize--];
    downheap(1);
    j = heap[1];	/* next least-freq entry */
    if(j < n)
      *sort++ = j;
    k = avail++;	/* generate new node */
    freq[k] = freq[i] + freq[j];
    heap[1] = k;
    downheap(1);	/* put into queue */
    left[k] = i;
    right[k] = j;
  } while (heapsize > 1);
  sort = codeparm;
  make_len(k);
  make_code(nparm, lenparm, codeparm);
  return k;		/* return root */
}

static void encode_c(WORD c)
{
  putcode(c_len[c], c_code[c]);
}

static void encode_p(UWORD p)
{
  UWORD c, q;

  c = 0;
  q = p;
  while(q)
  {
    q >>= 1;
    c++;
  }
  putcode(pt_len[c], pt_code[c]);
  if(c > 1)
    putbits(c - 1, p);
}

static void count_t_freq(void)
{
  WORD i, k, n, count;

  for(i = 0; i < NT; i++)
    t_freq[i] = 0;
  n = NC;
  while(n > 0 && c_len[n - 1] == 0)
    n--;
  i = 0;
  while(i < n)
  {
    k = c_len[i++];
    if(k == 0)
    {
      count = 1;
      while(i < n && c_len[i] == 0)
      {
        i++;
        count++;
      }
      if(count <= 2)
        t_freq[0] += count;
      else if(count <= 18)
        t_freq[1]++;
      else if(count == 19)
      {
        t_freq[0]++;
        t_freq[1]++;
      }
      else
        t_freq[2]++;
    }
    else
      t_freq[k + 2]++;
  }
}

static void write_pt_len(WORD n, WORD nbit, WORD i_special)
{
  WORD i, k;

  while(n > 0 && pt_len[n - 1] == 0)
    n--;
  putbits(nbit, n);
  i = 0;
  while(i < n)
  {
    k = pt_len[i++];
    if(k <= 6)
      putbits(3, k);
    else
      putbits(k - 3, (UWORD) (USHRT_MAX << 1));
    if(i == i_special)
    {
      while(i < 6 && pt_len[i] == 0)
	i++;
      putbits(2, i - 3);
    }
  }
}

static void write_c_len(void)
{
  WORD i, k, n, count;

  n = NC;
  while(n > 0 && c_len[n - 1] == 0)
    n--;
  putbits(CBIT, n);
  i = 0;
  while(i < n)
  {
    k = c_len[i++];
    if(k == 0)
    {
      count = 1;
      while(i < n && c_len[i] == 0)
      {
        i++;
	count++;
      }
      if(count <= 2)
      {
	for(k = 0; k < count; k++)
	  putcode(pt_len[0], pt_code[0]);
      }
      else if(count <= 18)
      {
	putcode(pt_len[1], pt_code[1]);
	putbits(4, count - 3);
      }
      else if(count == 19)
      {
	putcode(pt_len[0], pt_code[0]);
	putcode(pt_len[1], pt_code[1]);
	putbits(4, 15);
      }
      else
      {
	putcode(pt_len[2], pt_code[2]);
	putbits(CBIT, count - 20);
      }
    }
    else
      putcode(pt_len[k + 2], pt_code[k + 2]);
  }
}

static void send_block(void)
{
  UBYTE flags = 0;
  UWORD i, k, root, pos, size;

  root = make_tree(NC, c_freq, c_len, c_code);
  size = c_freq[root];
  putbits(16, size);
  if(root >= NC)
  {
    count_t_freq();
    root = make_tree(NT, t_freq, pt_len, pt_code);
    if(root >= NT)
    {
      write_pt_len(NT, TBIT, 3);
    }
    else
    {
      putbits(TBIT, 0);
      putbits(TBIT, root);
    }
    write_c_len();
  }
  else
  {
    putbits(TBIT, 0);
    putbits(TBIT, 0);
    putbits(CBIT, 0);
    putbits(CBIT, root);
  }
  root = make_tree(np, p_freq, pt_len, pt_code);
  if(root >= np)
  {
    write_pt_len(np, pbit, -1);
  }
  else
  {
    putbits(pbit, 0);
    putbits(pbit, root);
  }
  pos = 0;
  for(i = 0; i < size; i++)
  {
    if(i % CHAR_BIT == 0)
      flags = buf[pos++];
    else
      flags <<= 1;
    if(flags & (1 << (CHAR_BIT - 1)))
    {
      encode_c(buf[pos++] + (1 << CHAR_BIT));
      k = buf[pos++] << CHAR_BIT;
      k += buf[pos++];
      encode_p(k);
    }
    else
      encode_c(buf[pos++]);
    if(unpackable)
      return;
  }
  for(i = 0; i < NC; i++)
    c_freq[i] = 0;
  for(i = 0; i < np; i++)
    p_freq[i] = 0;
}

static void output_st1(UWORD c, UWORD p)
{
  output_mask >>= 1;
  if(output_mask == 0)
  {
    output_mask = 1 << (CHAR_BIT - 1);
    if(output_pos >= bufsiz - 3 * CHAR_BIT)
    {
      send_block();
      if(unpackable)
        return;
      output_pos = 0;
    }
    cpos = output_pos++;
    buf[cpos] = 0;
  }
  buf[output_pos++] = (unsigned char) c;
  c_freq[c]++;
  if(c >= (1 << CHAR_BIT))
  {
    buf[cpos] |= output_mask;
    buf[output_pos++] = (unsigned char) (p >> CHAR_BIT);
    buf[output_pos++] = (unsigned char) p;
    c = 0;
    while(p)
    {
      p >>= 1;
      c++;
    }
    p_freq[c]++;
  }
}

static void init_slide(void)
{
  ULONG i;

  for(i = 0; i < HSHSIZ; i++)
  {
    hash[i] = 0;
    too_flag[i] = 0;
  }
}

static void insert(void)
{
  prev[pos & (dicsiz - 1)] = hash[hval];
  hash[hval] = pos;
}

static void update(void)
{
  ULONG i, j;
  LONG n, m;

  i = 0;
  j = dicsiz;
  m = txtsiz-dicsiz;
  while(m-- > 0)
    text[i++] = text[j++];

  n = getbytes(&text[txtsiz - dicsiz], (ULONG) dicsiz);

  remainder += n;
  encoded_origsize += n;

  pos -= dicsiz;
  for(i = 0; i < HSHSIZ; i++)
  {
    j = hash[i];
    hash[i] = (j > dicsiz) ? j - dicsiz : 0;
    too_flag[i] = 0;
  }
  for(i = 0; i < dicsiz; i++)
  {
    j = prev[i];
    prev[i] = (j > dicsiz) ? j - dicsiz : 0;
  }
}

static void get_next(void)
{
  remainder--;
  if(++pos >= txtsiz - maxmatch)
  {
    update();
  }
  hval = ((hval << 5) ^ text[pos + 2]) & (ULONG)(HSHSIZ - 1);
}

static void match_insert(void)
{
  ULONG scan_pos, scan_end, len;
  STRPTR a, b;
  ULONG chain, off, h, max;

  max = maxmatch; /* MAXMATCH; */
  if(matchlen < THRESHOLD - 1)
    matchlen = THRESHOLD - 1;
  matchpos = pos;

  off = 0;
  for(h = hval; too_flag[h] && off < maxmatch - THRESHOLD;)
  {
    h = ((h << 5) ^ text[pos + (++off) + 2]) & (ULONG)(HSHSIZ - 1);
  }
  if(off == maxmatch - THRESHOLD)
    off = 0;
  for(;;)
  {
    chain = 0;
    scan_pos = hash[h];
    scan_end = (pos > dicsiz) ? pos + off - dicsiz : off;
    while(scan_pos > scan_end)
    {
      chain++;
      if(text[scan_pos + matchlen - off] == text[pos + matchlen])
      {
        a = text + scan_pos - off;
        b = text + pos;
        for(len = 0; len < max && *a++ == *b++; len++)
          ;
        if(len > matchlen)
        {
	  matchpos = scan_pos - off;
	  if((matchlen = len) == max)
	  {
	    break;
          }
	}
      }
      scan_pos = prev[scan_pos & (dicsiz - 1)];
    }
    if(chain >= LIMIT)
      too_flag[h] = 1;

    if(matchlen > off + 2 || off == 0)
      break;
    max = off + 2;
    off = 0;
    h = hval;
  }
  prev[pos & (dicsiz - 1)] = hash[hval];
  hash[hval] = pos;
}

static void encode_start_st1(void)
{
  LONG i;

  if(dicbit <= (MAX_DICBIT - 2))
  {
     pbit = 4;	/* lh4,5 etc. */
     np = 14;
  }
  else
  {
    pbit = 5;	/* lh6 */
    np = 16;
  }

  for(i = 0; i < NC; i++)
    c_freq[i] = 0;
  for(i = 0; i < np; i++)
    p_freq[i] = 0;
  output_pos = output_mask = 0;
  init_putbits();
  buf[0] = 0;
}

static void encode_end_st1(void)
{
  if(!unpackable)
  {
    send_block();
    putbits(CHAR_BIT - 1, 0);	/* flush remaining bits */
  }
}

static void encode(void)
{
  LONG lastmatchlen, i;
  ULONG lastmatchoffset;

  compsize = count = 0;
  unpackable = 0;

  init_slide();  

  encode_start_st1();

  for(i = 0; i < TXTSIZ; ++i)
    text[i] = ' ';

  remainder = getbytes(&text[dicsiz], txtsiz-dicsiz);
  encoded_origsize = remainder;
  matchlen = THRESHOLD - 1;
  pos = dicsiz;

  if(matchlen > remainder)
    matchlen = remainder;
  hval = ((((text[dicsiz] << 5) ^ text[dicsiz + 1]) << 5) ^ text[dicsiz + 2]) & (ULONG)(HSHSIZ - 1);

  insert();
  while(remainder > 0 && !unpackable)
  {
    lastmatchlen = matchlen;  lastmatchoffset = pos - matchpos - 1;
    --matchlen;
    get_next();
    match_insert();
    if(matchlen > remainder)
      matchlen = remainder;
    if(matchlen > lastmatchlen || lastmatchlen < THRESHOLD)
    {
      output_st1(text[pos - 1], 0);
      count++;
    }
    else
    {
      output_st1(lastmatchlen + (UCHAR_MAX + 1 - THRESHOLD), (lastmatchoffset) & (dicsiz-1) );
      --lastmatchlen;

      while(--lastmatchlen > 0)
      {
        get_next();
        insert();
        count++;
      }
      get_next();
      matchlen = THRESHOLD - 1;
      match_insert();
      if(matchlen > remainder)
        matchlen = remainder;
    }
  }
  encode_end_st1();
}

static STRPTR alloc_buf(void)
{
  bufsiz = 16 * 1024 * 2;	/* 65408U; */
  while(!(buf = (STRPTR) AllocMem(bufsiz, MEMF_ANY)))
  {
    bufsiz = (bufsiz / 10) * 9;
    if(bufsiz < 4 * 1024)
      break;
  }
  return buf;
}

/************************************************************************/

static void Store32(STRPTR s, ULONG v)
{
  ULONG i;

  for(i = 0; i < 4; ++i)
  {
    *(s++) = v;
    v >>= 8;
  }
}

static void Store16(STRPTR s, ULONG v)
{
  *(s++) = v;
  *s = v >> 8;
}

#define TM_UREAD  	00400 /* Read by owner */
#define TM_UWRITE 	00200 /* Write by owner */
#define TM_UEXEC  	00100 /* Execute/search by owner */
#define TM_GREAD  	00040 /* Read by group */
#define TM_GWRITE 	00020 /* Write by group */
#define TM_GEXEC  	00010 /* Execute/search by group */
#define TM_OREAD  	00004 /* Read by other */
#define TM_OWRITE 	00002 /* Write by other */
#define TM_OEXEC 	00001 /* Execute/search by other */

/* Header structure!
  UWORD	   TotalHeaderSize		 0  *
  UBYTE*5  HeaderID			 2  *
  ULONG    CompSize			 7  *
  ULONG    Size				11  *
  ULONG	   Time				15  *
  UBYTE    Attribute			19  *
  UBYTE	   Level (2)			20  *
  UWORD    CRC			        21  *
  UBYTE    SystemID ('A')		23  *
  UWORD    FirstExtHeaderSize		24
  extended headers
  data
*/

static UBYTE tmp[10240];
LONG CreateFileLHA(struct xadArchiveInfo *inai, struct xadFileInfo *fi,
struct xadArchiveInfo *outai)
{
  ULONG headersize = 26, i, j, k, opos, ipos, size;
  LONG err;
  STRPTR mem2;

  if(fi->xfi_Flags & XADFIF_LINK)
    return 
    -1;

  size = fi->xfi_Size;
  if(fi->xfi_Flags & XADFIF_DIRECTORY)
    size = 0;
  tmp[2] = tmp[6] = '-';
  tmp[3] = 'l';
  tmp[4] = 'h';
  Store32(tmp+7, size);
  Store32(tmp+11, size);
  tmp[19] = fi->xfi_Protection;
  tmp[20] = 2;
  tmp[21] = tmp[22] = 0;
  tmp[23] = 'A';

  xadConvertDates(XAD_DATEXADDATE, &fi->xfi_Date, XAD_GETDATEMSDOS, &k, TAG_DONE);
  Store32(tmp+15, k);

  if(fi->xfi_Flags & XADFIF_DIRECTORY)
  {
    tmp[5] = 'd';
    i = strlen(fi->xfi_FileName);
    Store16(tmp + headersize-2, i+3); /* set header size */
    tmp[headersize++] = 0x02;
    for(j = 0; j < i; ++j)
      tmp[headersize++] = fi->xfi_FileName[j] == '/' ? 0xFF : fi->xfi_FileName[j];
    headersize += 2;
  }
  else
  {
    STRPTR m;

    tmp[5] = '0';
    m = FilePart(fi->xfi_FileName);

    i = strlen(m);
    Store16(tmp + headersize-2, i+3); /* set header size */
    tmp[headersize] = 0x01;
    CopyMem(m, tmp+headersize+1, i);
    headersize += i+3;
    if(m != fi->xfi_FileName)
    {
      i = m-fi->xfi_FileName-1;
      Store16(tmp + headersize-2, i+3); /* set header size */
      tmp[headersize++] = 0x02;
      for(j = 0; j < i; ++j)
        tmp[headersize++] = fi->xfi_FileName[j] == '/' ? 0xFF :
        fi->xfi_FileName[j];
      headersize += 2;
    }
  }

  if(fi->xfi_Protection & 0xFFFFFF00)
  {
    /* store UNIX protection */
    Store16(tmp + headersize-2, 5); /* set header size */
    i = fi->xfi_Protection;
    j = 0;

    if(!(i & FIBF_READ))	j |= TM_UREAD;
    if(!(i & FIBF_WRITE)) 	j |= TM_UWRITE;
    if(!(i & FIBF_EXECUTE))	j |= TM_UEXEC;
    if(i & FIBF_GRP_READ) 	j |= TM_GREAD;
    if(i & FIBF_GRP_WRITE)	j |= TM_GWRITE;
    if(i & FIBF_GRP_EXECUTE)	j |= TM_GEXEC;
    if(i & FIBF_OTR_READ) 	j |= TM_OREAD;
    if(i & FIBF_OTR_WRITE)	j |= TM_OWRITE;
    if(i & FIBF_OTR_EXECUTE)	j |= TM_OEXEC;

    tmp[headersize] = 0x50;
    Store16(tmp+headersize+1, j);
    headersize += 5;
  }

  /* store ID's */
  if(fi->xfi_OwnerUID || fi->xfi_OwnerGID)
  {
    Store16(tmp + headersize-2, 7); /* set header size */
    tmp[headersize] = 0x51;
    Store16(tmp + headersize+1, fi->xfi_OwnerGID);
    Store16(tmp + headersize+3, fi->xfi_OwnerUID);
    headersize += 7;
  }

  /* store group name */
  if(fi->xfi_GroupName)
  {
    i = strlen(fi->xfi_GroupName);
    Store16(tmp + headersize-2, i+3); /* set header size */
    tmp[headersize] = 0x52;
    CopyMem(fi->xfi_GroupName, tmp+headersize+1, i);
    headersize += i+3;
  }

  /* store user name */
  if(fi->xfi_UserName)
  {
    i = strlen(fi->xfi_UserName);
    Store16(tmp + headersize-2, i+3); /* set header size */
    tmp[headersize] = 0x53;
    CopyMem(fi->xfi_UserName, tmp+headersize+1, i);
    headersize += i+3;
  }

  if(!(fi->xfi_Flags & XADFIF_NODATE))
  {
    /* store UNIX time stamp */
    Store16(tmp + headersize-2, 7); /* set header size */
    xadConvertDates(XAD_DATEXADDATE, &fi->xfi_Date, XAD_GETDATEUNIX, &k,
    TAG_DONE);
    tmp[headersize] = 0x54;
    Store32(tmp+headersize+1, k);
    headersize += 7;
  }

  /* store comment */
  if(fi->xfi_Comment)
  {
    i = strlen(fi->xfi_Comment);
    Store16(tmp + headersize-2, i+3); /* set header size */
    tmp[headersize] = 0x71;
    CopyMem(fi->xfi_Comment, tmp+headersize+1, i);
    headersize += i+3;
  }
  /* save the stuff */
  Store16(tmp + headersize-2, 5);
  tmp[headersize] = 0x00;
  Store16(tmp + headersize+1, 0); /* clear CRC */
  headersize += 5;
  Store16(tmp + headersize-2, 0); /* clear last header size */
  Store16(tmp, headersize);
  Store16(tmp + headersize-4, xadCalcCRC16(XADCRC16_ID1, 0, headersize, tmp));

  /* store header */
  err = xadHookAccess(XADAC_WRITE, headersize, tmp, outai);

  opos = outai->xai_OutPos;
  ipos = inai->xai_InPos;
  if(!err && size && !(fi->xfi_Flags & XADFIF_DIRECTORY)) /* Compressable ? */
  {
    i = 0;
    if((mem2 = (STRPTR) AllocVec(size*2, MEMF_CLEAR)))
    {
      lh5_inmem = mem2+size;
      lh5_outmem = mem2;
      origsize = size;
      compsize = 0;
      depth = 0;
      inpos = 0;

      maxmatch = MAXMATCH;
      dicbit = 13;
      dicsiz = (1 << dicbit);
      txtsiz = dicsiz*2+maxmatch;

      /* modify to use shorter buffer !!! */
      if(!(err = xadHookAccess(XADAC_READ, size, lh5_inmem, inai)))
      {
        Store16(tmp+21, size ? xadCalcCRC16(XADCRC16_ID1, 0, size, lh5_inmem) : 0);
        if(alloc_buf())
        {
          if((hash = (UWORD *) AllocVec(HSHSIZ * 2, MEMF_CLEAR)))
          {
	    if((prev = (UWORD *) AllocVec(DICSIZ * 2, MEMF_CLEAR)))
            {
	      if((text = (STRPTR) AllocVec(TXTSIZ, MEMF_CLEAR)))
	      {
	        if((too_flag = (STRPTR) AllocVec(HSHSIZ, MEMF_CLEAR)))
	        {
	          encode();
	          if(compsize < size && !unpackable)
	          {
                    err = xadHookAccess(XADAC_WRITE, compsize, lh5_outmem, outai);
	            i = compsize;
	          }
	          FreeVec(too_flag);
	        }
	        FreeVec(text);
	      }
	      FreeVec(prev);
	    }
	    FreeVec(hash);
          }
          FreeMem(buf, bufsiz);
        }
      }
      FreeVec(mem2);
    }

    if(!err)
    {
      if(i)
      {
        tmp[5] = '5';
        Store32(tmp+7, i);
        Store16(tmp + headersize-4, xadCalcCRC16(XADCRC16_ID1, 0, headersize,
        tmp)); /* store CRC again */
        if(!(err = xadHookAccess(XADAC_OUTPUTSEEK, -(i+headersize), 0, outai)))
        {
          err = xadHookAccess(XADAC_WRITE, headersize, tmp, outai);
        }
      }
      else
      {
        UWORD crc = 0;
        if(ipos != inai->xai_InPos)
          err = xadHookAccess(XADAC_INPUTSEEK, ipos-inai->xai_InPos, 0, inai);
        if(!err && opos != outai->xai_OutPos)
          err = xadHookAccess(XADAC_OUTPUTSEEK, opos-outai->xai_OutPos, 0,
          outai);
        while(!err && size)
        {
          if((i = size) > sizeof(tmp)-headersize)
            i = sizeof(tmp)-headersize;
          if(!(err = xadHookAccess(XADAC_READ, i, tmp+headersize, inai)))
          {
            crc = xadCalcCRC16(XADCRC16_ID1, crc, i, tmp+headersize);
            err = xadHookAccess(XADAC_WRITE, i, tmp+headersize, outai);
          }
          size -= i;
        }
        if(!err)
        {
          if(!(err = xadHookAccess(XADAC_OUTPUTSEEK, opos-headersize
          - outai->xai_OutPos, 0, outai)))
          {
            /* store CRC, recalc header crc, store header */
            Store16(tmp+21, crc);
            Store16(tmp + headersize-4, xadCalcCRC16(XADCRC16_ID1, 0,
            headersize, tmp)); /* store CRC again */
            err = xadHookAccess(XADAC_WRITE, headersize, tmp, outai);
          }
        }
      }
      if(!err)
      {
        err = xadHookAccess(XADAC_OUTPUTSEEK, outai->xai_OutSize
        - outai->xai_OutPos, 0, outai);
      }
    }
  }
  return err;
}
