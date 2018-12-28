=============================
Kr�tkie wprowadzenie do AROSa
=============================

:Autorzy:   Aaron Digulla, Stefan Rieken, Matt Parsons, Adam Chodorowski 
:Prawa autorskie: Copyright (C) 1995-2002, The AROS Development Team
:Wersja:   $Revision: 30800 $
:Data:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Prawie sko�czony, jak s�dz�...


.. Include:: index-abstract.pl


Cele
====

Celem projektu AROS jest stworzenie systemu operacyjnego, kt�ry:

1. Jest najbardziej jak to mo�liwe kompatybilny z AmigaOS 3.1.

2. Mo�e by� portowany na r�ne architektury sprz�towe i procesory, 
   takie jak x86, PowerPC, Alpha, Sparc, HPPA i inne.

3. Powinien by� kompatybilny na poziomie binari�w z Amig� i na poziomie �r�de�
   kompatybilny z ka�dym innym sprz�tem.
  
4. Mo�e dzia�a� jako samodzielny system, uruchamiaj�cy si� bezpo�rednio z dysku twardego
   i jako emulacja, otwieraj�ca okno w systemie gospodarza by umo�liwi� programowanie i
   uruchamianie natywnych amigowych program�w w tym samym czasie.

5. Ma funkcjonalno�� ulepszon� w stosunku do AmigaOS.

By osi�gn�� te cele, zastosowali�my szereg technik. Przede wszystkim intensywnie wykorzystujemy 
Internet. Mo�esz wzi�� udzia� w naszym projekcie nawet je�li chcesz napisa� jedn� 
funkcj� systemu operacyjnego. Najbardziej aktualna wersja �r�de� jest dost�pna 24 godziny na dob�
a zmiany w nich mog� by� wprowadzane w dowolnym czasie.  Niewielka baza danych z otwartymi zadaniami 
pozwala unikn�� dublowania pracy.


Historia
========

Jaki� czas temu w roku 1993, sytuacja Amigi pogorszy�a si� i niekt�rzy z jej
fan�w zacz�li si� zastanawia� nad tym, co nale�a�oby zrobi�, by podnie�� presti� 
ich ukochanego komputera. Nagle g��wny pow�d braku sukcesu Amigi sta� si� jasny: 
to by�o rozpowszechnienie a w�a�ciwie jego brak. Amiga powinna by� bardziej powszechna 
by sta� si� bardziej atrakcyjn� dla u�ytkownik�w i developer�w. Zaplanowano osi�gni�cie 
tego celu. Jednym z plan�w by�o naprawienie bug�w AmigaOS, innym stworzenie z niego 
nowoczesnego systemu operacyjnego. Narodzi� si� projekt AOS.

Lecz w�a�ciwie co by�o bugiem? I jak nale�y te bugi naprawi�? Jakie cechy powinien 
posiada� tak zwany *nowoczesny* system operacyjny? I jak powinny by� one 
zaimplementowane do AmigaOS?

Dwa lata p�niej, ludzie nadal spierali si� w tym temacie i nie napisano ani  
jednej linii kodu (w ka�dym razie nikt nie zobaczy� tego kodu). Dyskusje 
zaczyna�y si� od "musimy mie� ..." nast�pnie kto� odpowiada� "przeczytaj stare maile" 
lub "to jest niemo�liwe do zrobienia poniewa� ..." po czym nast�powa�o "mylisz si� bo ..." 
itp. 

Zim� 1995 roku, Aaron Digulla mia� ju� do�� tej sytuacji i wys�a� RFC (request for comments) 
na list� dyskusyjn� AOS, w kt�rym zapyta� jakie powinny by� wymagania minimalne. 
Zaproponowano szereg wariant�w i w rezultacie okaza�o si�, �� praktycznie wszyscy
chcieliby zobaczy� otwarty system operacyjny, kompatybilny z AmigaOS 3.1 (Kickstart 40.68). 
Na tej bazie mia�y si� opiera� wszystkie dalsze dyskusje by ustali� co jest mo�liwe a co nie.


Tak rozpocz�y si� prace i narodzi� si� AROS.

