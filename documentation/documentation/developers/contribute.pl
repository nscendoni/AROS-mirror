==========
Wsp�praca
==========

:Authors:   Adam Chodorowski 
:Copyright: Copyright (C) 1995-2002, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done. 

.. Contents::

.. Include:: contribute-abstract.pl


Dost�pne zdania
===============

To jest lista zada�, przy kt�rych potrzebujemy pomocy i nad kt�rymi nikt 
aktualnie nie pracuje. To nie jest pe�na lista, zawiera jednak najwa�niejsze
rzeczy, przy kt�rych potrzebna jest pomoc.


Programowanie
-------------

+ Implementacja brakuj�cych bibliotek, zasob�w, urz�dze� lub ich cz�ci. 
  Obejrzyj szczeg�lowy raport o statusie, by uzyska� wi�cej informacji czego brakuje.

+ Implementacja lub poprawienie sterownik�w sprz�tu:
  
  - AROS/m68k-pp:
    
    + Grafika
    + Urz�dzenia wej�cia (touchscreen, buttons)
    + D�wi�k
 
  - AROS/i386-pc:
    
    + specyficzne sterowniki kart graficznych (mamy tylko og�lne, niezbyt
      dobrze akcelerowane). Kr�tka lista �ycze�:
      
      - nVidia TNT/TNT2/GeForce (rozpocz�ta, lecz niekompletna) 
      - S3 Virge
      - Matrox Millenium
    
    + USB
    + SCSI
    + specyficzne chipsety IDE
    + ...Co� jeszcze, co Ci przychodzi na my�l.

  - Og�lna obs�uga drukarki.
 

+ Portowanie na inne architektury. Kilka przyk�ad�w sprz�tu, na kt�ry nie 
  ma jeszcze portu AROSa lub prace dopiero si� rozpocz�y:

  - Amiga m68k i PPC.
  - Atari.
  - HP 300 series.
  - SUN Sparc.
  - iPaq.
  - Macintosh m68k i PPC.

+ Implementacja brakuj�cych edytor�w preferencji:

  - IControl
  - Overscan
  - Palette
  - Pointer
  - Printer
  - ScreenMode
  - Sound
  - WBPattern
  - Workbench 
 
+ Poprawienie biblioteki C link 

  Implementacja brakuj�cych funkcji ANSI (i kilku POSIX) w clib, by u�atwi�
  portowanie program�w UNIXowych (np. GCC, make i binutils). Najwi�ksz� 
  brakuj�c� rzecz� jest wsparcie dla POSIX style signaling, lecz jest tak�e
  kilka innych funkcji.

+ Implementacja wi�kszej ilo�ci datatyp�w i poprawienie istniej�cych

  Liczba dost�pnych w systemie AROS datatyp�w jest niewielka. Poni�ej kilka 
  przyk�ad�w datatyp�w, kt�re wymagaj� poprawienia by by�y u�ywalne lub 
  musz� by� napisane:

  - amigaguide.datatype
  - sound.datatype
    
    + 8svx.datatype

  - animation.datatype
    
    + anim.datatype
    + cdxl.datatype
    
  
+ Portowanie program�w:

  - Wdytory tekstu jak ViM i Emacs.
  - La�cuch narz�dzi developerskich, zawieraj�cy GCC, make, binutils i inne
    narz�dzia programistyczne GNU.
  

Dokumentacja
-------------

+ Pisanie dokumentacji u�ytkownika. Polega to na tworzeniu og�lnej Instrukcji 
  U�ytkownika dla nowicjuszy i ekspert�w, a tak�e dokumentacji referencyjnej 
  dla wszystkich standardowych program�w AROSa.

+ Pisanie dokumentacji programisty. Chocia� jest to w nieco lepszym stanie
  ni� dokumentacja u�ytkownika, nadal jest du�o do zrobienia. Na przyk�ad,
  nie ma jeszcze dobrego tutoriala dla pocz�tkuj�cych programist�w. 
  Odpowiednik 'ROM Kernel Manuals for AROS' by�by naprawd� potrzebny.


T�umaczenie
-----------

+ T�umaczenie AROSa na inne j�zyki. Obecnie w mniejszym lub wi�kszym stopniu
  obs�ugiwane s� nast�puj�ce j�zyki:

  - angielski
  - niemiecki
  - szwedzki
  - norweski
  - w�oski


+ T�umaczenie dokumentacji i strony internetowej na inne j�zyki. Obecnie 
  kompletna strona jest dost�pna jedynie po angielsku. Cz�� zosta�a 
  przet�umaczona na norweski, niemiecki, rosyjski i w�oski, lecz nadal jest 
  du�o do zrobienia.


Inne
-----

+ Kierowanie projektami GUI dla program�w AROSa, takich jak prefs,
  tools i utilities.

Do��cz do zespo�u
=================

Chcesz si� przy��czy� do developer�w? Wspaniale! Do��cz zatem do `listy 
dyskusyjnej`__, kt�ra Ci� interesuje (przynajmniej zapisanie si� na 
g��wn� list� aros-dev jest *wysoce* wskazane) i popro� o dost�p do
repozytorium SVN.
To wszystko. :)

Napisanie kr�tkiego maila na list� dyskusyjn� zawieraj�c� informacje o sobie, 
o tym w czym chce si� pom�c jest mile widziane. Je�li masz jakie� problemy, 
nie kr�puj si�, wy�lij maila na list� lub spytaj na `kanale IRC`__.
Zatem zanim rozpoczniesz pracowa� nad czym� konkretnym, napisz prosz� maila na 
list�, informuj�c co chcesz robi� lub popraw baz� zada�. Tym sposobem 
uchronisz innych przed prac� nad tym samym przez pomy�k�...

__ ../../contact#mailing-lists
__ ../../contact#irc-channels


Repozytorium SVN
----------------

Repozytorium AROSa pracuje na chronioym has�em serwerze subwersji, co oznacza,
�e musisz poprosi� o dost�p do niego, by wsp�pracowa� w rozwoju. Has�a s� 
zaszyfrowane, mo�esz je wygenerowa� naszym `narz�dziem szyfruj�cym`__.

Napisz maila ze swoim zaszyfrowanym has�em razem z wybran� nazw� u�ytkownika
i nazwiskiem do `Aaron Digulla`__ i czekaj na odpowied�. By przy�pieszy� odpowied�,
wpisz w temacie maila "Access to the AROS SVN server" a w tre�ci "Please add 
<u�ytkownik> <has�o>", np.::

    Please add digulla xx1LtbDbOY4/E

To mo�e potrwa� kilka dni, bo Aaron jest bardzo zaj�ty, prosz� b�d� cierpliwy. 

Aby uzyska� informacje jak u�ywa� serwera SVN, przeczytaj prosz� "`Praca z SVN`__".
Nawet je�li ju� wiesz jak u�ywa� SVN to warto tam zajrze�, poniewa� znajdziesz
tam informacje i porady specyficzne dla repozytorium AROSa (takie jak si� do 
niego zalogowa�).

__ http://aros.sourceforge.net/tools/password.html 
__ mailto:digulla@aros.org?subject=[Access%20to%20the%20AROS%20SVN%20server]
__ svn
 
