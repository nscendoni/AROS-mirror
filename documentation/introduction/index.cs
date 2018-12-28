=================
Kr�tk� �vod AROSu
=================

:Authors:   Aaron Digulla, Stefan Rieken, Matt Parsons, Adam Chodorowski 
:Copyright: Copyright � 1995-2009, The AROS Development Team
:Version:   $Revision: 31438 $
:Date:      $Date: 2009-06-19 17:02:24 +0200 (Fri, 19 Jun 2009) $
:Status:    T�m�� hotovo, mysl�m...


.. Include:: index-abstract.cs


C�le
====

C�lem AROS projektu je vytvo�it OS, kter�:

1. Je co mo�n� nejv�ce kompatibiln� se opera�n�m syst�mem AmigaOS 3.1.

2. M��e b�t portov�n na r�zn� druhy hardwarov�ch architektur a
   procesor�, jako jsou x86, PowerPC, Alpha, Sparc, HPPA a dal��.

3. By m�l b�t kompatibiln� bin�rn� na Amize a zdrojov� na jak�mkoli jin�m
   hardwaru.

4. M��e b�et jako samostatn� verze, kter� bootuje p��mo z pevn�ho disku, i
   jako emulace, kter� otev�e okno ve st�vaj�c�m OS pro v�voj softwaru a
   b�h Amigy a nativn�ch aplikac� z�rove�.

5. Vylep�� funk�nost syst�mu AmigaOS.

Pro dosa�en� tohoto c�le pou��v�me �adu technik. V prv� �ad� ve velk� m��e
vyu��v�me internet. Na na�em projektu se m��e� pod�let, i kdy� um� napsat
pouze jednu jedinou funkci 0S. Posledn� verze zdrojov�ch k�d�
je dostupn� 24 hodin denn� a opravy v nich mohou b�t kdykoli mergnuty.
Mal� datab�ze s otev�en�mi �koly (open tasks) zaji��uje, �e pr�ce nen� duplikov�na.


Historie
========

N�jak� �as zp�tky (v roce 1993) vypadala situace pro Amigu pon�kud h��
ne� obvykle a n�kte�� fanou�ci Amigy se spojili a za�ali diskutovat, co by
se m�lo ud�lat, aby se zv��ilo p�ijet� na�eho milovan�ho stroje. Hlavn� d�vod
pro chyb�j�c� �sp�ch Amigy byl ihned jasn�: byla to propagace,
tedy sp�e jej� nedostatek. Amiga by m�la z�skat �ir�� z�kladnu, aby
se stala atraktivn�j�� pro v�echny - u�ivatele i v�voj��e. Proto byly
vytvo�eny pl�ny k dosa�en� tohoto c�le. Jedn�m z pl�n� bylo opravit chyby AmigaOS,
dal��m bylo u�init z n�j modern� opera�n� syst�m. Zrodil se projekt AOS.

Ale co p�esn� jsou chyby? A jak by tyto chyby m�ly b�t opraveny? Jak� funkce
mus� takzvan� *modern�* OS m�t? A jak by m�ly b�t implementov�ny
do AmigaOS?

O dva roky pozd�ji se o tom st�le dohadovali a nebyl naps�n
jedin� ��dek k�du (nebo alespo� nikdo nikdy ��dn� nevid�l). Diskuze
byly st�le o tom, �e n�kdo �ekl "mus�me m�t..." a
jin� odpov�d�l "p�e�ti si star� maily" nebo "nejde to ud�lat, proto�e...",
co� bylo kr�tce pot� n�sledov�no "plete� se, proto�e...", a tak d�le.

V zim� roku 1995 byl u� Aaron Digulla z t�to situace unaven a poslal
RFC (��dost o koment��e) do AOS mailing listu, ve kter� se ptal, jak�
by m�lo b�t z�kladn� spole�n� v�chodisko. K dispozici bylo n�kolik variant a z�v�r
byl, �e t�m�� v�ichni by cht�li vid�t otev�en� OS, kter� je kompatibiln� s
AmigaOS 3.1 (Kickstart 40.68). Na tomto z�klad� se mohly stav�t dal�� diskuze,
aby se zjistilo, co je mo�n� a co ne.

A tak za�ala pr�ce a AROS se narodil.
