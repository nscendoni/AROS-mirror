===========================
Kort introduktion till AROS
===========================

:Authors:   Aaron Digulla, Stefan Rieken, Matt Parsons, Adam Chodorowski 
:Copyright: Copyright � 1995-2009, The AROS Development Team
:Version:   $Revision: 46175 $
:Date:      $Date: 2012-12-31 17:08:20 +0100 (Mon, 31 Dec 2012) $
:Status:    Almost finished, I think...


.. Include:: index-abstract.sv


M�l
===

AROS-projektets m�l �r att skapa ett operativsystem som:

1. �r s� kompatibelt med AmigaOS 3.1 som m�jligt.

2. Kan portas till olika former av h�rdvaruarkitekturer och processorer, s�som
   x86, PowerPC, Alpha, Sparc, HPPA och andra.

3. Vara kompatibel p� bin�r niv� n�r man k�r den p� Amiga-h�rdvara och
   k�llkodskompatibel p� annan h�rdvara.
  
4. Kan k�ras som en frist�ende version som startar direkt fr�n h�rddisk eller
   som en emulerad version som �ppnar ett f�nster, vilket till�ter att man kan
   k�ra Amiga och �vriga applikationer samtidigt.

5. F�rb�ttrar funktionaliteten hos AmigaOS.

F�r att n� dessa m�l anv�nder vi ett antal olika arbetss�tt. Allra fr�mst
anv�nder vi oss av Internet. Du kan vara med i v�rat projekt �ven om bara kan
skriva en enda funktion i operativsystemet. Den mest uppdaterade versionen av
k�llkoden finns tillg�nglig dygnet runt och patchar kan integreras n�r som
helst. En liten databas med �ppna jobb s�kerst�ller att samma jobb inte utf�rs
av flera personer samtidigt.


Historia
========

Runt 1993 s�g situationen f�r Amiga v�rre ut �n n�gonsin och h�ngivna
supportrar samlades f�r att diskutera vad som kunde g�ras f�r att r�dda v�r
�lskade maskin. Vissa ans�g att det var viktigt att Amigan blev mer accepterad
i vidare kretsar och att dess framg�ngsl�shet berodde p� dess begr�nsade
spridning. Planer utvecklades f�r att uppn� detta m�l. En av dessa planer var
att �tg�rda buggarna i AmigaOS, en annan var att utveckla AmigaOS till ett
modernt operativsystem. Dessa var n�gra av anledningarna till att
AROS-projektet startades.

N�r Amigan gick i graven verkade det vettigast att k�pa ut AmigaOS k�llkod.
Tills dess fokuserade man p� vad som faktiskt beh�vde g�ras. Som vad som
egentligen skulle r�knas som buggar och vad var det b�sta s�ttet att fixa dem?
Vad ska ett s� kallat modernt OS ha f�r funktioner? Och hur skulle de
implementeras i OSet?

Tv� �r senare s� var debatten fortfarande inte avslutad och eftersom k�llkoden
fortfarande inte var tillg�nglig s� hade inte en enda rad kod skapats.
Diskussionerna tenderade att upprepas och urarta till br�k kring vad som var
och inte var genomf�rbart.

Vintern 1995 tr�ttnade Aaron Digulla p� situationen och postade en RFC
("Request for comments") till AOS e-postlista och fr�gade vad som var det
minsta gemensamma kravet p� OS:et skulle kunna vara. Flera alternativ
presenterades och slutsatsen blev att n�stan alla ville ha ett �ppet
operativsystem som var kompatibelt med AmigaOS 3.1 (Kickstart 40.68).
Alla fortsatta diskussioner om vad som kunde g�ras var nu baserat p� detta m�l
i �tanke.

Arbetet med AROS tog sin b�rjan.
