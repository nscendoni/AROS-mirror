==========
Portningar
==========

:Authors:   Adam Chodorowski, Matthias Rustler 
:Copyright: Copyright � 1995-2006, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done.

.. Contents::


Introduktion
============

Eftersom AROS �r ett portabelt operativsystem, s� �r det tillg�ngligt f�r flera
olika plattformar. En "portning" av AROS �r precis som det l�ter, en version av
AROS portad till en specifik plattform.


Smaker
------

Portningar �r uppdelade i tv� st�rre grupper, eller "smaker" inom AROS termioligi,
dessa �r "native" och "hosted".

Native-portningar k�rs direkt p� h�rdvaran och har total kontroll �ver datorn.
Dom kommer att vara det rekommenderade s�ttet att k�ra AROS i framtiden eftersom
det ger �verl�gsen prestanda och effektivitet, men dom �r f�r n�rvarande f�r
inkompletta f�r att vara anv�ndbara (�tminstone f�r utveckling). 

Hosted-portningar k�rs ovanp� ett annat operativsystem och har inte tillg�ng till
h�rdvaran direkt, de anv�nder faciliteterna som operativsystemet ger dom. F�rdelarna
med hosted-portningar �r att dom �r enklare att skriva, eftersom det inte �r 
n�dv�ndigt att skriva l�g-niv� drivrutiner. Eftersom AROS uveckling �ven inte �r 
sj�lv-hosted �nnu (Vi kan inte kompilera AROS inifr�n AROS) s� snabbar det upp
programmeringen, eftersom vi kan k�ra utvecklingsmilj�n och AROS sida-vid-sida utan
att �dsla tid p� konstanta omstarter f�r att testa ny kod. 

Namngivning
-----------

De olika AROS-portningarna �r namngivna i formen <cpu>-<platform>, d�r <cpu> �r
CPU-arkitekturen och <platform> �r ett symboliskt namn av plattformen. Plattformen
av en portning kan antingen vara en h�rdvara f�r native-portningar, som "pc" eller
"amiga", eller ett operativsystem f�r hosted-portningar, som "linux" eller
"freebsd". I fall d�r det inte �r uppenbart att �mnet i fr�ga handlar om
AROS s� �r det vanligt med att anv�nda ett prefix "AROS/" till portnings-namnet,
vilket t.ex. kan ge namnet "AROS/i386-pc".


Portnings-kompabilitet
----------------------

AROS exekverbara filer f�r en specifik CPU �r kompatibla �ver alla portningar
som anv�nder den CPU:n, vilket betyder att exekverbara filer f�r "i386-pc" kommer
att fungera p� "i386-linux" och "i386-freebsd".

Existerande portningar
======================

Nedan finns en lista p� alla AROS portningar som fungerar och/eller aktivt
utvecklas. Alla av dessa �r inte tillg�ngliga f�r nerladdning, eftersom dom
eventuellt inte �r tillr�ckligt kompletta eller har kompileringskrav som vi
inte alltid kan uppn� pga. ej tillr�ckliga resurser.


AROS/i386-pc
------------

:Flavour:    Native
:Status:     Fungerande, ej komplett drivrutinsupport
:Maintained: Ja

AROS/i386-pc �r en native-portning av AROS till vanliga IBM PC AT datorer och
kompatibla som anv�nder x86-processorfamiljen. Namnet �r faktiskt en smula
vilseledande eftersom AROS/i386-pc faktiskt kr�ver �tminstone en 486 CPU,
eftersom anv�ndandet av en del instruktioner inte finns tillg�ngliga p� en 386 CPU.

Denna portning fungerar ganska bra, men vi har endast v�ldigt grundl�ggande
drivrutinfunktioner. En av de st�rsta begr�nsningarna �r att vi f�r
tillf�llet endast har st�d f�r "accelerated graphics" p� nVidia och
ATI-grafikkort. Andra grafikkort m�ste anv�ndas med "generic (non accelerated)
VGA och VBE grafikdrivrutiner. Det utvecklas drivrutiner f�r fler grafikkort,
men utvecklingen g�r relativt tr�gt eftersom vi endast har omkring 2,5 
h�rdvaruutvecklare.
Denna portning �r tillg�nglig f�r nerladdning.


AROS/m68k-pp
------------

:Flavour:    Native 
:Status:     Delvis fungerande (i en emulator), ej komplett drivrutinsst�d.
:Maintained: Ja

AROS/m68k-pp �r native-portningen av AROS f�r Palm-serien av handdatorer och
kompatibla ("pp" st�r f�r "palm pilot", vilket var namnet p� de f�rsta handdatorerna
i denna serie). Detta betyder att du eventuellt kan ta med dig AROS i din ficka
n�r du reser i framtiden...

Denna portning �r f�r tillf�lligt v�ldigt "r�". Oftast fungerar den (Om man k�r den
i en emulator, eftersom ingen v�gar ta risken att f�rst�ra deras dyra h�rdvara
f�r tillf�llet) men det �r fortfarande mycket arbete kvar. Det finns en 
grafikrutin, men inga f�r input.
Denna portning �r inte tillg�nglig f�r nerladdning f�r tillf�llet.


AROS/i386-linux
---------------

:Flavour:    Hosted
:Status:     Fungerande
:Maintained: Ja

AROS/i386-linux �r den hostade portningen av AROS till operativsystemet Linux
[#]_ som k�rs p� x86-processorer.

Detta �r den mest kompletta portningen av AROS funktionsm�ssigt, eftersom
de flesta utvecklarna anv�nder Linux n�r de utvecklar AROS och det �r
mycket f�rre drivrutiner att skriva.
Denna portning finns tillg�nglig f�r nerladdning.

AROS/i386-freebsd
-----------------

:Flavour:    Hosted
:Status:     Fungerande
:Maintained: Ja (5.x)

AROS/i386-freebsd �r den hostade portningen av AROS till operativsystemet FreeBSD
som k�rs p� x86-processorer.

Denna portning �r relativt komplett eftersom den delar den mesta av koden
med AROS/i386-linux, men eftersom det inte finns s� m�nga utvecklare som anv�nder
FreeBSD s� ligger utvecklingen lite efter. Vi f�rs�ker att kompilera AROS/i386-freebsd
n�r vi g�r snapshots, men det �r inte alltid m�jligt, d� det kanske inte alltid finns
tillg�ngligt f�r nerladdning.

AROS/ppc-linux
---------------

:Flavour:    Hosted
:Status:     Fungerande
:Maintained: Ja

AROS/ppc-linux �r den hostade portningen av AROS till operativsystemet Linux
som k�rs p� PPC-processorer.

En f�rkompilerad version kan laddas ner fr�n `Sourceforge`__.
Omkompilering kr�ver en patchad gcc3.4.3. Diff-filen finns i contrib/gnu/gcc.

__ http://sourceforge.net/project/showfiles.php?group_id=43586&package_id=194077

Fotnot
======

.. [#] Ja, vi vet att Linux bara �r en k�rna och inte ett helt OS, men det �r mycket
       kortare att skriva �n "operativsystem baserat p� Linux-k�rnan, en del av
       de vanligare GNU-verktygen och X f�nsterhanterarsystemen". Denna optimering
       av utrymme g�r naturligtvis att bestrida av de mest pedantiska l�sarna, men men...
