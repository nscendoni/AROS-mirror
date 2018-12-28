=============================
Wprowadzenie do komend AROS'a
=============================

:Authors:   Matthias Rustler 
:Copyright: Copyright � 2006, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Draft

-----------------

`Indeks <index>`_

-----------------

AROS posiada konsole 'Shell'. 
Mo�esz j� uruchomi� z menu Wanderer>Shell. Okno z aktualnym katalogiem zostanie
otworzone. Okno polece� b�dzie zawiera�o numer CLI oraz aktualn� �cie�k�.

Shell posiada histori�. Mo�esz mie� do niej dost�p poprzez kursor w g�r� i w 
d�.

Jest tutaj wiele udogodnie�. Je�li wpiszesz pierwsze litery komendy 
lub obiektu i wci�niesz tabulator, Shell szuka pasuj�cego wyrazu. Je�li jednak 
b�dzie wi�cej mo�liwo�ci to pojawi si� lista ASL z mo�liwo�ci� wyboru.

W AROS komendy i nazwy plik�w mog� by� pisane mieszanymi [wielkimi/ma�ymi] 
literami.

AROS szuka komend w aktualnym katalogu i �cie�kach wyszukiwania.
Mo�esz podgl�da� i zmienia� �cie�ki dzi�ki komendzie `path <path>`_


Niekt�re potrzebne komendy
--------------------------
+ `CD <cd>`_		-- zmienia katalog
+ `DIR <dir>`_		-- pokazuje zawarto�� katalogu
+ `COPY <copy>`_	-- kopiuje pliki i katalogi
+ `DELETE <delete>`_	-- usuwa pliki i katalogi
+ `INFO <info>`_	-- pokazuje dostepne dyski
+ `MAKEDIR <makedir>`_	-- tworzy katalogi
+ `RENAME <rename>`_	-- zmienia nazwe plikom i katalogom
+ `TYPE <type>`_	-- pokazuje zawarto�� plik�w tekstowych

�cie�ka
-------
G��wna �cie�ka rozpoczyna si� od nazwy i dwukropka (:),
katalogi s� oddzielone uko�nikiem (/).
Nazwa dysku mo�e by� nazw� urz�dzenia (dh0:), woluminem (workbench:) lub
logicznym dyskiem (zobacz `assign <assign>`_ komenda)

::
  
	Przyk�ad: dh0:dir1/dir2/file.dat

Je�li chcesz doda� aktualny katalog do �cie�ek wyszukiwania to mo�esz to zrobi� 
po prostu pisz�c path "".

::

	Przyk�ad: copy from ram:x to ""


Sam dwukropek oznacza katalog aktualnej �cie�ki.
Gdy �cie�ka zaczyna si� od dwukropka wtedy wskazuje na g��wny katalog podanej 
�cie�ki.

Jeden uko�nik (/) oznacza przej�cie do katalogu wy�ej, dwa oznaczaj� dwa wy�ej,
i tak analogicznie.

Gdy nazwa zawiera spacje, nazwy musz� by� uj�te w nawiasy.

::

	Przyk�ad: type "nazwa z odst�pami"

Szablon komend
--------------
Znak zapytania po komendzie pokazuje jej dost�pne opcje. Nast�pnie komenda jest w
trybie, w kt�rym czeka na podanie parametr�w.

::

	Przyk�ad: copy ?
	FROM/M,TO/A,ALL/S,QUIET/S,BUF=BUFFER/K/N,CLONE/S,DATES/S,NOPRO/S,COM/S,NOREQ/S

S�owa kluczowe mog� posiada� nast�puj�ce opcje::

	/A -- argument musi by� podany
	/K -- s�owo kluczowe musi by� wpisane, gdy jest podany argument
	/S -- prze��cznik; tylko s�owo kluczowe jest potrzebne
	/N -- argument numeryczny
	/M -- wi�cej ni� jeden argument musi by� podany
	/F -- reszta linii komend
	=  -- skr�t; opcjonalnie mo�esz u�y� skr�tu

Gdy wywo�ujesz komend� mo�esz u�y� nast�puj�cej formy::

	Przyk�ad: copy from=a.dat to=b.dat
  
Wzorce
------
Niekt�re komendy zezwalaj� na u�ycie wzorc�w::

	?  -- jeden znak
	#? -- zero lub wi�cej znak�w
	#x -- zero lub wi�cej x
	~  -- zaprzeczenie
	|  -- lub
	() -- grupa
	[] -- zasi�g

	Przyk�ad::

	dir #?.info
	dir #?~(.info)
	dir a(b|c)d
	dir [a-c]e

Przekierowania
--------------

::

	>	przekierowuje do pliku
	>>	przekierowuje do pliku, do��czaj�c
	<	przekierowuje z pliku, b�d� urz�dzenia
	
	Przyk�ad: dir >ram:a 

Potok
-----
Je�li chcesz przekierowa� wyj�cie jednej komendy do drugiej, mo�esz u�y� potoku.
Musisz po��czy� komendy takim znakiem \| . Musi by� przynajmniej jedna spacja
przed i po \|::

	Przyk�ad: dir | innakomenda
	
	
Lecz co je�li druga komenda chce odzczyta� wej�cie z pliku? Rozwi�zanie polega
na u�yciu nieistniej�cego urz�dzenia 'in:'::
  
	Przyk�ad: dir | more in:  

Urz�dzenia specjalne
--------------------
+ ram:	mo�esz u�ywa� RamDysku jak twardego dysku. Lecz po ponownym uruchomieniu
	zawarto�� jest wyczyszczona. 
+ nil:	je�li nie chcesz aby wyj�cie z komendy zostawa�o wy�wietlane, mo�esz
	u�y� urz�dzenia 'nil:'. Przyk�ad Dir >nil:

Uruchamianie w nowym procesie
-----------------------------
Normalnie komenda blokuje Shell, a� do jej zako�czenia. Mo�esz uruchomi� komendy
w nowych procesach dzi�ki 'Run <run>'_ .

::

	Przyk�ad: run dir #?

Pliki .info
-----------
Pliki z rozszerzeniem '.info' odgrywaj� wa�n� rol� w Wanderer. Zawieraj�
obrazek do ikony i kilka dodatkowych informacji. Gdy korzystasz z komend Shell
musisz pliki '.info' wzi�� pod uwag�.
