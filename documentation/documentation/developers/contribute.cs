==========
Contribute
==========

:Authors:   Adam Chodorowski 
:Copyright: Copyright � 1995-2007, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done. 

.. Contents::

.. Include:: contribute-abstract.cs


Aktu�ln� �koly
==============

Zde je seznam n�kter�ch �kol�, se kter�mi pot�ebujeme pomoci, a na kter�ch
moment�ln� nikdo ned�l�. Nejedn� se o kompletn� seznam v�ech �kol�, ale
obsahuje ty �koly, kter� pova�ujeme za d�le�it�.


Programov�n�
------------

+ Implementace chyb�j�c�ch knihoven, zdroj�, za��zen� nebo jejich sou��st�.
  Pod�vej se na detailn� zpr�vu o v�voji, aby jsi zjistil v�ce informac�
  o ��stech, kter� chyb�.


+ Implementace nebo zdokonalen� ovlada�� hardware za��zen�:
  
  - AROS/m68k-pp:
    
    + Grafika
    + Vstup (dotykov� obrazovka, tla��tka)
    + Zvuk
 
  - AROS/i386-pc:

    + Konkr�tn� ovlada�e grafick�ch karet (m�me pouze obecn�, ne zrovna
      p��li� akcelerovan�). Kr�tk� seznam p��n�:
      
      - nVidia TNT/TNT2/GeForce (za�lo se, ale nedokon�ilo) 
      - S3 Virge
      - Matrox Millenium
    
    + chyb� USB classes
    + SCSI
    + Konkr�tn� IDE �ipsety
    + Zvuk
    + ... cokoliv, na co bys mohl p�ij�t.

  - V�eobecn� podpora tisk�ren.
 
+ Portov�n� na dal�� architektury. N�kolik p��klad� hardwaru, pro
  kter� AROS je�t� nem� port nebo za�al b�t portov�n:

  - Amiga, m68k i PPC.
  - Atari.
  - HP 300 series.
  - SUN Sparc.
  - iPaq.
  - Macintosh, m68k i PPC.

+ Implementace chyb�j�c�ch editor� nastaven�:

  - Overscan
  - Paleta
  - Pointer
  - Tisk�rna
 
+ Zdokonalov�n� knihovny C link

  Tedy implementace chyb�j�c�ch ANSI (a n�kter�ch POSIX) funkc� v clib,
  aby se usnadnilo portov�n� UNIX softwaru (nap�. GCC, make a binutils).
  Nejd�le�it�j�� v�c, kter� chyb�, je podpora POSIX style signaling,
  ale i jin� funkce.

+ Implementace v�ce datatyp� a vylep�en� t�ch st�vaj�c�ch

  Po�et datatyp� obsa�en�ch v AROSu je pom�rn� mal�. N�kter� datatypy,
  kter� pot�ebuj� vylep�en�, aby byly pou�iteln� nebo pot�ebuj�
  implementaci �pln� od z�kladu:

  - amigaguide.datatype
  - sound.datatype
    
    + 8svx.datatype

  - animation.datatype
    
    + anim.datatype
    + cdxl.datatype
    
  
+ Portov�n� program� t�et�ch stran:

  - Textov� editory jako jsou ViM a Emacs.
  - Bal�k v�vojov�ch n�stroj�, kter� zahrnuj� GCC, make, binutils a dal��
    GNU v�voj��sk� n�stroje.
  - AmigaOS Open Source software jako je SimpleMail, YAM, Jabbwerwocky


Dokumentace
-----------

+ Psan� u�ivatelsk� dokumentace. T�k� se psan� hlavn�ch U�ivatelsk�ch
  p��ru�ek pro za��te�n�ky a experty, a tak� dokumentace na v�echny
  standardn� AROS programy.

+ Psan� v�voj��sk� dokumentace. T�eba�e je tato pr�ce v pokro�ilej��m
  st�diu ne� u�ivatelsk� dokumentace, st�le je toho je�t� hodn� zpracov�vat.
  Pro p��klad, zat�m nem�me ��dnou dobrou p��ru�ku pro za��naj�c� program�tory.
  Bylo by taky hezk� m�t ekvivalent k ROM Kernel manu�l�m pro AROS.


P�eklad
-------

+ P�ekl�d�n� samotn�ho AROSu do v�ce jazyk�. Nyn� jsou v�ce �i m�n� kompletn�
  podporov�ny pouze tyto jazyky:

  - Angli�tina
  - N�m�ina
  - �v�d�tina
  - Nor�tina
  - Ital�tina
  - Francouz�tina
  - Ru�tina

+ P�eklad dokumentace a internetov�ch str�nek do v�ce jazyk�. Aktu�ln� je
  web kompletn� pouze v angli�tin�. P�ekl�d� se pozvolna i do dal��ch jazyk�,
  ale zb�v� je�t� hodn� pr�ce.


Ostatn�
-------

+ Koordinace GUI designu pro AROS programy, jako jsou prefs programy,
  n�stroje a utility.


P�ipoj se k t�mu
================

Chce� se p�ipojit k v�voj��sk�mu t�mu? Skv�le! V tom p��pad� se p�ihla� k
`v�voj��sk�mu mailing listu`__, o kter� se zaj�m� (*v�ele* doporu�ujeme p�ipojit
se alespo� k hlavn�mu v�voj��sk�mu listu) a po��dej o p��stup k Subversion
repozit��i. A je to. :)

Napi� kr�tk� mejl�k na v�voj��sk� list, n�co o sob�, co d�l� a jak�m zp�sobem
bys r�d pomohl. Pokud bude� m�t n�jak� probl�m, nev�hej poslat email do listu
nebo se zeptej na n�kter�m z `IRC kan�l�`__. Tak�, ne� za�ne� d�lat na n��em
konkr�tn�m, napi� email do listu s t�m, co bude� d�lat, nebo aktualizuj
datab�zi �kol�. Takto se d� p�edej�t tomu, aby n�kolik lid� d�lalo
nedopat�en�m na jednom a tom sam�m �kolu...


__ ../../contact#mailing-lists
__ ../../contact#irc-channels


Subversion repozit��
--------------------

AROS repozit�� b�� na Subversion serveru, kter� je chr�n�n� heslem,
co� znamen�, �e mus� po��dat o p��stup, aby jsi se mohl pod�let na v�voji.
Hesla jsou kryptov�na, kryptovan� heslo si m��e� vytvo�it pomoc� na�eho
`online kryptovac�ho n�stroje hesla`__.

Po�li pros�m kryptovan� heslo spole�n� s tv�m vlastn�m u�ivatelsk�m jm�nem
a skute�n�m jm�nem na adresu `Aarona Digully`__ a po�kej na odezvu. Aby jsi
urychlil proces p��stupu, napi� do p�edm�tu zpr�vy toto "Access to the
AROS SVN server" a do t�la napi� "Please add <username> <password>", nap�.::

    Please add digulla xx1LtbDbOY4/E

M��e to trvat n�kolik dn�, jeliko� Aaron je hodn� vyt�en�, tak�e m�j trp�livost. 

Abys v�d�l, jak pou��vat AROS SVN server, p�e�ti si pros�m "`Pr�ce s
SVN`__". I pokud u� v� jak pou��vat SVN, je st�le u�ite�n� jej prostudovat,
proto�e obsahuje informace a rady ur�en� pro AROS repozit��
(nap�. jak se do n�j zalogovat).

__ http://aros.sourceforge.net/tools/password.html 
__ mailto:digulla@aros.org?subject=[Access%20to%20the%20AROS%20SVN%20server]
__ svn
 
