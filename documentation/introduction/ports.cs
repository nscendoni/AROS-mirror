=====
Porty
=====

:Authors:   Adam Chodorowski, Matthias Rustler 
:Copyright: Copyright � 1995-2006, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done.

.. Contents::


�vod
====

Vzhledem k tomu, �e AROS je p�enosn� opera�n� syst�m, je k dispozici pro n�kolik
r�zn�ch platforem. "Port" AROSu je p�esn� to, co znamen�, to jest verze
AROSu upraven� pro ur�itou platformu.


P��chut� - flavors
------------------

Porty jsou rozd�leny na dv� hlavn� varianty, v terminologii AROSu tak� "flavors",
jmenovit� "nativn�" a "hostovan�".

Nativn� porty b�� p��mo na hardwaru a maj� absolutn� kontrolu nad
po��ta�em. V budoucnu se stanou doporu�ovan�m zp�sobem pro b�h AROSu,
proto�e poskytuj� lep�� ��innost i v�kon, ale v sou�asn� dob� jsou p��li�
ne�pln�, aby mohly b�t pou��v�ny (p�inejmen��m pro v�voj).

Hostovan� porty b�� na jin�m opera�n�m syst�mu a k hardwaru nep�istupuj�
p��mo, ale pou��vaj� prost�edky poskytovan� hostitelsk�m OS.
V�hodou hostovan�ch port� je jejich jednodu��� programov�n�, proto�e nen�
nutn� ps�t low-level ovlada�e. A vzhledem k tomu, �e v�voj AROSu je�t�
nen� self-hosted (sebehostitelsk� - nelze kompilovat AROS z AROSu), v�razn� urychluj�
programov�n�, proto�e vedle sebe m��e b�et v�vojov� prost�ed� i AROS
a pro vyzkou�en� nov�ho k�du nen� t�eba ztr�cet �as neust�l�m restartov�n�m.


Pojmenov�n�
-----------

R�zn� porty AROSu jsou pojmenov�ny ve tvaru <procesor>-<platforma>, kde <procesor> je
procesor architektury a <platforma> je symbolick� n�zev platformy.
Platforma portu m��e b�t bu� hardwarov�, jako nap�. "pc" nebo "amiga",
u nativn�ch port�, nebo opera�n� syst�m, jako nap�. "linux" nebo "freebsd",
u hostovan�ch port�. V p��padech, kdy nen� z�ejm�, �e se jedn� o AROS, p�id�
se na za��tek n�zvu portu "AROS/", nap��klad "AROS/i386-pc".


P�enositelnost
--------------

AROS spustiteln� soubory pro konkr�tn� procesor jsou p�enosn� na v�echny porty,
kter� tento procesor pou��vaj�, co� znamen�, �e spustiteln� soubory kompilovan� pro
"i386-pc" budou v pohod� pracovat na "i386-linux" i "i386-freebsd".


Sou�asn� porty
==============

N�e je uveden seznam v�ech port� AROSu, kter� jsou v provozuschopn�m stavu
a/nebo aktivn� vyv�jeny. Ne v�echny z nich jsou dostupn� ke sta�en�, proto�e nemus�
b�t bu� dostate�n� kompletn� nebo maj� kompila�n� po�adavky, kter� nem��eme
v�dy splnit kv�li omezen�m zdroj�m.


AROS/i386-pc a x86-64
---------------------

:Varianta:  Nativn�
:Stav:      Funk�n�, ne�pln� podpora ovlada��
:Udr�ov�na: Ano

AROS/i386-pc je nativn� port AROSu na b�n� IBM PC AT po��ta�e a
kompatibiln� pou��vaj�c� x86 (nebo x86-64) rodinu procesor�. N�zev je tak trochu
zav�d�j�c�, proto�e AROS/i386-pc ve skute�nosti vy�aduje t��du procesoru alespo� 486
kv�li pou�it� n�jak�ch instrukc�, kter� na 386 nejsou dostupn�. Tento stroj mus� b�t
t� zalo�en na PCI sb�rnici.

Tento port funguje pom�rn� dob�e, ale m�me pouze nejz�kladn�j�� podporu
ovlada��. Jedn�m z nejv�t��ch omezen� je, �e v sou�asn� dob� m��eme
nab�dnout grafickou akceleraci pouze kart�m s �ipem nVidia a ATI. Ostatn�
grafick� adapt�ry mus� b�t pou��v�ny s generick�mi VGA a VBE grafick�mi
ovlada�i (bez akcelerace). Pracuje se na v�ce ovlada��ch, ale jejich
v�voj je pon�kud pomalej��, proto�e m�me jen asi 2.5 hardwarov�ch specialist�.
Tento port je k dispozici ke sta�en�.


AROS/m68k-pp
------------

:Variatna:  Nativn�
:Stav:      ��ste�n� funk�n� (v emul�toru), ne�pln� podpora ovlada��
:Udr�ov�na: Ano

AROS/m68k-pp je nativn� port AROSu pro kapesn� po��ta�e �ady Palm
a kompatiblin� ("pp" znamen� "palm pilot", co� bylo jm�no prvn�ho
handheldu t�to �ady). To znamen�, �e v budoucnu bude mo�n�
nosit AROS s sebou v kapse...

Tento port je v sou�asn� dob� velmi nedod�lan�. V�t�inou funguje (b�� v emul�toru,
proto�e nikdo zat�m je�t� nechce riskovat po�kozen� drah�ho hardwaru), ale st�le
je na n�m spousta pr�ce. M� grafick� ovlada�, ale ��dn� pro vstup.
Tento port nen� v sou�asn� dob� k dispozici ke sta�en�.


AROS/i386-linux
---------------

:Varianta:  Hostovan�
:Stav:      Funk�n�
:Udr�ov�na: Ano

AROS/i386-linux je hostovan� port AROSu pro opera�n� syst�m Linux [#]_
b��c� na procesorech rodiny x86.

Je to rozhodn� nejkompletn�j�� port, proto�e v�t�ina v�voj���
v sou�asn� dob� k v�voji AROSu pou��v� Linux a je daleko m�n�
ovlada��, kter� se pro n�j mus� ps�t. Tento port je k dispozici ke sta�en�.


AROS/i386-freebsd
-----------------

:Varianta:  Hostovan�
:Stav:      Funk�n�
:Udr�ov�na: Ano (5.x)

AROS/i386-freebsd je hostovan� port AROSu pro opera�n� syst�m FreeBSD
b��c� na procesorech rodiny x86.

Tento port je pom�rn� kompletn�, proto�e sd�l� v�t�inu k�d� s portem AROS/i386-linux,
ale vzhledem k tomu, �e nen� mnoho v�voj���, kte�� pou��vaj� FreeBSD,
z�st�v� trochu pozadu. Sna��me se sestavovat AROS/i386-freebsd, kdy� d�l�me
snapshoty, ale ne v�dy je to mo�n�, tak�e nemus� b�t poka�d� k dispozici
ke sta�en�.


AROS/ppc-linux
--------------

:Varianta:  Hostovan�
:Stav:      Funk�n�
:Udr�ov�na: Ano

AROS/ppc-linux je hostovan� port AROSu pro opera�n� syst�m Linux
b��c� na procesorech rodiny PPC.

P�edkompilovan� verze m��e b�t sta�ena ze `Sourceforge`__.
P�estaven� vy�aduje opravenou verzi gcc3.4.3. Diff soubor se nach�z� v contrib/gnu/gcc.

__ http://sourceforge.net/project/showfiles.php?group_id=43586&package_id=194077


Dodatek
=======

.. [#] Ano, v�me, �e Linux je vlastn� jen j�dro a ne cel� 0S, ale
       je mnohem krat�� napsat Linux, ne� "opera�n� syst�m zalo�en� na
       linuxov�m j�d�e, n�kter� b�n� GNU n�stroje a X window
       system". Tato optimalizace rozsahu je ov�em negov�na t�m, �e se mus� ps�t
       toto vysv�tlen� pro pedantsk� �ten��e, ale stejn�...

