===============================================
Spou�t�n� klasick�ch Amiga aplikac� z Wandereru
===============================================

:Authors:   Matthias Rustler
:Copyright: Copyright � 2007, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done.

.. Contents::

�vod
----

E-UAE um� emulovat klasick� Amiga hardware a umo��uje spou�t�t aplikace
pod modern�m hardwarem a modern�mi opera�n�mi syst�my. Dokonce je mo�n�
spustit E-UAE pomoc� ikony z Wandereru takov�m zp�sobem, �e nahraje p��mo
i tebou zvolenou aplikaci. Trik je v tom, �e pou�ijeme skript, kter� spust�
E-UAE s ur�it�mi parametry. Skript dostane ikonu "iconx" s obecn�m
(default tool) n�strojem.


P��prava E-UAE
--------------

Program E-UAE pro AROS najde� v contrib archivu v no�n�ch buildech a cesta je
*System:Extras/Emu/E-UAE*.

Pro spu�t�n� E-UAE pot�ebuje� soubor ROM. Leg�ln� zp�sob jak jej z�skat je
koupit si Cloanto Amiga Forever nebo Amiga Classix CD-Roms. Nebo jej m��e�
vykop�rovat ze skute�n� Amigy pomoc� n�stroje zvan�ho "TransRom". Zkop�ruj
image soubory n�kam na pevn� disk, kde m� ulo�en� AROS. N�sleduj�c� p��klad
p�edpokl�d�, �e jsi vytvo�il adres�� s n�zvem "uae" na disk "work:". (Tip:
obrazy (images) z Cloanto CD jsou kryptov�ny. Bude� pot�ebovat
je�t� soubor rom.key.)

V editoru uprav st�vaj�c� konfigura�n� soubor *System:Extras/Emu/E-UAE/.uaerc*
Minim�ln� by jsi m�l ur�it cesty k ROM obraz�m. P��klad::

    amiga.rom_path     = work:uae
    amiga.use_dither   = false
    cpu_type           = 68020
    chipset            = ecs
    chipmem_size       = 4
    cachesize          = 4096
    fastmem_size       = 8
    gfx_linemode       = double
    kickstart_rom_file = $(FILE_PATH)/kick13.rom
    #kickstart_key_file = $(FILE_PATH)/rom.key
    sound_output       = none

A te� si ud�l�me test. Otev�i shell pro cestu *System:Extras/Emu/E-UAE*
a napi� *i386-aros-uae*. Pokud se po chv�li objev� Workbench disketa,
(nap�. ruka u Kickstartu 1.3 nebo zaj�d�j�c� disketa u Kickstartu 3.1)
tak jsi zdolal prvn� p�ek�ku. I kdy� u� to takto b��, tak p�esto v�nuj
pozornost chybov�m hl�k�m a sna� se je opravit.


Nastaven�
---------

E-UAE m� hodn� konfigurovateln�ch mo�nost�, kter� se ukl�daj� do konfigura�n�ch
soubor� a tak� m� n�kolik mo�nost� v p��kazov� ��dce. Pod�vej se na dokumentaci
pro E-UAE. Kdy� spust� E-UAE takto: ``i386-aros-uae -f config1 -option1
-option2``, nejprve se nahraje soubor *.uaerc*. Pak se nahraje soubor
s parametrem -f a p�ep�e se p�ede�l� nastaven�. Pot� se pou�ij� mo�nosti
dan� p��kazov�m ��dkem, a znovu se p�ep�ou mo�nosti nastaven� p�edt�m.

Doporu�ujeme, aby jsi vytvo�il konfigura�n� soubory, kter� emuluj�
skute�n� po��ta�e:

* a500-13.uaerc: 68000 processor, ecs, kick1.3, no acceleration
* a1200-31.uaerc: 68020, aga, kick 3.1, additional memory
* a4000-31.uaerc: no limits

Tady je p��klad pro *a500-13.uaerc*::

    cpu_type=68000
    cpu_speed=real
    kickstart_rom_file=$(FILE_PATH)/kick13.rom

Psan� konfigura�n�ch soubor� je nejslo�it�j�� ��st t�to p��ru�ky.
Pokud m� Amiga Classix CDRom m��e� na n�m vyhledat p�r rad ohledn� psan�
konfigura�n�ch soubor�. Nebo m��e� napsat ``i386-aros-uae -h >uaecommands``
a dostane� se ke startovn�mu bodu se v�emi mo�n�mi volbami.


Instalov�n� aplikac�
--------------------

Pot�ebuje� soubory s obrazy (images) disk� aplikac�, kter� bude� cht�t spustit.
Tyto obrazy maj� p��ponu *.adf*. M��e� si je ulo�it na libovoln� m�sto.
Nap��klad my pou��v�me *work:uae*.


Vytv��en� a spou�t�n� skript� z ikony
-------------------------------------

V dal��m kroku si vytvo�� pomoc� textov�ho editoru skript, kter�m bude�
spou�t�t E-UAE. Tento p��klad u hry Zarathrusta m� 2 diskety:


    cd system:emu/e-uae
    i386-aros-uae -f work:uae/a500-13.uaerc -0 work:uae/Zarathrusta1.adf -1 work:uae/Zarathrusta2.adf

Prvn� ��dek ur�uje aktu�ln� adres�� pro E-UAE. Potom spust� E-UAE pomoc�
konfigura�n�ho souboru *a500-13.uaerc* a vlo�� obraz disku do mechaniky 0 a 1.

Ulo�� soubor jako *Zarathrusta* ve *work:uae*.

A nakonec p�id� ikonu ke skriptu. Pot� co otev�e� adres�� *work:uae*
ve Wandereru, klikni na ikonu skriptu a zvol si *Icon/Information*
v menu. Napi� *c:iconx* jako default tool. (IconX tool spou�t� textov� soubory
jako DOSov� skripty). Na str�nce Tooltypes information o ikon� napi�
*WINDOW=con:0/20//600/Zarathrusta/AUTO*. Toto m� za n�sledek vytvo�en�
v�t��ho v�stupn�ho okna, tak�e nebude probl�m se �ten�m chybov�ch hl�ek.

Dvojklikem na ikonu spust� E-UAE s danou aplikac�.


Pevn� disky
-----------

E-UAE umo��uje pou��vat adres��e hostovan�ho syst�mu bu� jako hardfiles nebo
jako pevn� disky. Podrobn�j�� informace nalezne� v souboru
*Extras/Emu/E-UAE/docs/configuration.txt*. N�sleduj�c� p��klad ti uk�e,
*jak�m zp�sobem m��e� pou��vat adres��e *work:uae/workbench*
*a *work:uae/programs* jako pevn� disk::

    filesystem2=rw,:Workbench:work:uae/workbench,0
    filesystem2=rw,:Programs:work:uae/programs,-1

Na takov� disk dokonce m��e� i nainstalovat AmigaOS a nabootovat z n�j.
Disk, ze kter�ho by m�l syst�m bootnout mus� m�t nejvy��� bootovac� prioritu
(je to ten posledn� parametr v mo�nostech filesystem2).


Grafika
-------

Bohu�el, AROS E-UAE nem� emulaci Picasso, tzn. �e jsi omezen� na 256
barev na obrazovce.

N�kolik rad, jak z�skat lep�� rozli�en� a v�kon:

+ V konfiguraci pou��vej volbu *chipmem_size = 16*. To poskytne 16*512 = 8 MB Chip Ram.
+ D�le pou��vej volbu *z3mem_size=x* kde *x* mus� b�t n�co z �ady 1,2,4,6,8,16,32.
+ Zvol si High Res Laced v nastaven� Screenmodu v Prefs.
+ Pou��vej nejvy��� mo�n� nastaven� v Overscanu v Prefs.
+ Nainstaluj si n�stroj *FBlit*. kter� vyu��v� ur�it� patche k tomu,
  aby se pou��vala Fast Ram nam�sto Chip RAM.
