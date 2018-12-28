===============================
Zune - podr�cznik programowania
===============================

:Authors:   David Le Corfec, Camelek.AmigaRulez@wp.pl [ AROS Polska Team ]
:Copyright: Copyright � 2004, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Unfinished;
:ToDo:      All


.. Contents::


------------
Wprowadzenie
------------

Czym jest Zune?
===============

Zune jest zorientowanym obiektowo zestawem narz�dzi GUI ( Graficznego Interfejsu U�ytkownika ).
Jest klonem ( w API, i wygl�dzie ) MUI, bardzo dobrze znanym shereware'owym produktem Stenan'a Stuntz'a.
Wi�c programi�ci MUI b�d� si� czuli jak w domu; pozostali odkryj� koncepcj� i cechy szczeg�lne, kt�re Zune
dzieli z MUI.

+ Programista ma �atwiejsze zadanie w projektowaniu swojego GUI:
  nie ma potrzeby dla stosowania sta�ych warto�ci, Zune automatycznie wybiera czcionk�,
  i dostosowuje j� do konkretnego rozmiaru okna, dzi�ki swojej budowie.
  Musi tylko poda� schemat swojego GUI dla Zune, kt�re
  dostosuje nisko-poziomowe szczeg�y za niego automatycznie.

+ Efektem ubocznym jest to, �e u�ytkownik musi kontrolowa� wygl�d i zachowanie ( Look&Feel ) GUI:
  to on decyduje poszczeg�lnymi ustawieniami, kt�re Zune b�dzie u�ywa�,
  aby pokaza� GUI, kt�re zaprojektowa� programista.

Zune jest oparte o BOOPSI, budowa jest wzi�ta z AmigaOS,
dla zorientowanego-obiektowo programowania w C. Klasy Zune nie pochodz� od istniej�cych
gad�et�w klas BOOPSI; zamiast tego, klasa notyfikacji ( g��wna klasa
hierarchi Zune ) pochodzi od g��wnej klasy BOOPSI.

Pomoce
======

Pewna wiedza o OO ( zorientowanym-obiektowo ) programowaniu, jest wi�cej, ni� mile widziana.
Je�li nie, to Google mo�e pom�c Ci znale�� informacje z tego zakresu.

Znajomo�� AROS'a ( lub AmigaOS ) API i koncepcji jak listy Tag oraz BOOPSI
jest niezb�dna. Posiadanie Amiga Reference Manual ( RKM - podr�cznik Amigi ) jest bardzo przydatna.

Jako, �e Zune jest klonem MUI, ca�a dokumentacja dotycz�ca MUI, dotyczy
tak�e Zune. W szczeg�lno�ci ostatni dost�pny pakiet programistyczny, kt�ry
znajduje si� tutaj__. W tym archiwum, 2 dokumenty s� szczeg�lnie zalecane:

+ 'MUIdev.guide', dokumentacja dla programist�w dot. MUI.
+ `PSI.c`, �r�d�a aplikacji demonstruj�cej wszystkie nowe 
  cz�ci MUI, jak zorientowan�-obiektowo budow�, i dynamiczne tworzenie obiekt�w.

__ http://main.aminet.net/dev/mui/mui38dev.lha

Dodatkowo, to archiwum zawiera opisy funkcji ( autodocs ) MUI, kt�re nawi�zuj�
do wszystkich klas Zune.


---------------
BOOPSI Podstawy
---------------

Koncepcja
=========

Klasa
-----

Klasa m�wi sama za siebie, jest nadrz�dn� klas� i dyspozytorem ( dispatcher ).

+ nazwa: nazwa w postaci string dla klas publicznych, wi�c te mog� by� u�yte przez
  ka�dy program w systemie lub �adna ( nazwa ) je�li jest to prywatna klasa u�yta tylko
  w pojedy�czej aplikacji.

+ klasa nadrz�dna: wszystkie klasy BOOPSI tworz� hierarchi� po��czon� z
  g��wn� klas�, trafnie nazwan� rootclass ( klasa g��wna ). Pozwala to ka�dej podklasie na
  implementacj� swoich w�asnych wersji specyficznych operacji klas nadrz�dnych lub cofn��
  jedn� implementowan� przez jej nadrz�dn�. Znan� jako klas� podstawow� lub super klas�.

+ dyspozytor: daje dost�p do wszystkich operacji ( zwanych metodami ) dostarczanych
  przez t� klas�, upewniaj�c si�, �e ka�da operacja jest obs�ugiwana przez odpowiedni
  kod lub przesz�a do swojej super klasy.


Typ BOOPSI dla klasy to ``Class *`` znana jako ``IClass``.

Obiekt
------

Obiekt ma zawarto�� klasy: ka�dy obiekt ma w�asne specyficzne dane, ale wszystkie
obiekty tej samej klasy dziel� to samo zachowanie.
Obiekt ma kilka klas, je�li policzymy nadrz�dne jego prawdziwych klas,
( najbardziej pochodne ) a� do g��wnej klasy.

Typ BOOPSI dla obiektu to ``Object *``. Nie ma pola, do kt�rego mia�by�
bezpo�redni dost�p.

Atrybut
-------

Atrybut jest powi�zany z danymi ka�dego obiektu: nie mo�esz
mie� dost�pu do tych danych bezpo�rednio, mo�esz tylko ustawi�, b�d� pobra� atrybuty
dostarczane poprzez obiekt do zmodyfikowania jego wewn�trznego stanu. Atrybut jest
za��czony jako Tag (warto�� ``ULONG`` lub edytuj z ``TAG_USER``).

``GetAttr()`` i ``SetAttrs()`` s� u�ywane do modyfikowania atrybut�w obiektu.

Atrybuty mog� mie� jedn� lub wi�cej flag:

+ Rozpoczynaj�cy-ustawialny (``I``) :
  ten atrybut mo�e by� podany jak parameter, podczas tworzenia obiektu.
+ Ustawialny (``S``) :
  Mo�esz ustawi� ten atrybut kiedy tylko chcesz ( albo ostatecznie, nie tylko tworzenia).
+ Pobieralny (``G``) :
  Mo�esz pobra� warto�� tego atrybutu.

Metoda
------

Metoda BOOPSI jest funkcj�, kt�ra odbiera obiekt, klas� i wiadomo�� ( message ) jako parametery:

+ obiekt: obiekt, kt�rego potrzebujesz
+ klasa: rozwa�ana klasa dla tego obiektu
+ wiadomo��: zawiera ID metody, kt�re okre�la funkcj� do wywo�ania
  w obr�bie dyspozytora, i jest poprzedzona jego parametrami.

Aby wys�a� wiadomo�� do obiektu, u�ywaj ``DoMethod()``. U�yje najpierw prawdziwej
klasy. Je�li klasa zawiera t� metod�, wtedy jej u�yje.
W przeciwnym razie b�dzie pr�bowa� jej nadrz�dnej klasy, dop�ki wiadomo�� jest obs�ugiwana lub
g��wna klasa zosta�a osi�gni�ta ( w tym przypadku, nieznana wiadomo�� jest niewidocznie
odrzucana ).

Przyk�ady
=========

Zobaczmy proste przyk�ady tej budowy OOP:

Pobieranie atrybutu
-------------------

B�dziemy pobiera� zawarto�� String MUI::

    void f(Object *string)
    {
        IPTR result;
        
        GetAttr(string, MUIA_String_Contents, &result);
        printf("Zawarto�� String to: %s\n", (STRPTR)result);
    }

+ ``Object *`` jest obiektem BOOPSI.
+ ``IPTR`` musi by� u�ywany dla wyniku, kt�ry mo�e by� liczb� ca�kowit� ( int )
  lub wska�nikiem. `IPTR` jest zawsze zapisywany w pami�ci, wi�c u�ywanie mniejszego
  typu mo�e prowadzi� do uszkodzenia pami�ci ( programowej )!
+ Tutaj pytamy o obiekt MUI String dla jego zawarto�ci: ``MUIA_String_Contents``,
  jak ka�dy inny atrybut, jest to ``ULONG`` (to jest Tag)

Aplikacje Zune cz�ciej u�ywaj� makr ``get()`` i ``XGET()`` zamiast::

    get(string, MUIA_String_Contents, &result);
    
    result = XGET(string, MUIA_String_Contents);


Ustawianie atrybutu
-------------------

Zmie�my zawarto�� naszego String::

    SetAttrs(string, MUIA_String_Contents, (IPTR)"witaj", TAG_DONE);

+ Parametry wska�nik�w musz� by� przypisane do `IPTR`, tak aby unikn�� ostrzerze�.
+ Po parametrze obiektu, lista Tag jest przekierowana do `SetAttrs` i
  musi si� ko�czy� `TAG_DONE`.

Odkryjesz u�yteczno�� makra ``set()``::

    set(string, MUIA_String_Contents, (IPTR)"hello");

Lecz tylko z ``SetAttrs()`` mo�esz ustawi� kilka atrybut�w naraz::

    SetAttrs(string,
             MUIA_Disabled, TRUE,
             MUIA_String_Contents, (IPTR)"hmmm...",
             TAG_DONE);


Wywo�ywanie metody
------------------

Zobaczmy najcz�ciej wywo�ywan� metod� w Zune, metod� procesu zdarze�
wywo�ywan� w Twojej p�tli g��wnej::

    result = DoMethod(obj, MUIM_Application_NewInput, (IPTR)&sigs);

+ Parametry nie s� list� Tag, i nie ko�cz� si� ``TAG_DONE``.
+ Musisz przypisa� wska�niki do ``IPTR``, aby unikn�� ostrzerze�.

-------------
Witaj �wiecie
-------------

.. Figure:: zune/images/hello.png

    Proste rzeczy najpierw! Wiem, �e to si� Wam spodoba.


�r�d�o
======

Przestudiujmy nasz pierwszy prawdziwy przyk�ad::

    // gcc hello.c -lmui
    #include <exec/types.h>
    #include <libraries/mui.h>
    
    #include <proto/exec.h>
    #include <proto/intuition.h>
    #include <proto/muimaster.h>
    #include <clib/alib_protos.h>
    
    int main(void)
    {
        Object *wnd, *app, *but;
    
        // Tworzenie GUI
    	app = ApplicationObject,
    	    SubWindow, wnd = WindowObject,
    		MUIA_Window_Title, "Witaj �wiecie!",
    		WindowContents, VGroup,
    		    Child, TextObject,
    			MUIA_Text_Contents, "\33cWitaj �wiecie!\nJak si� masz?",
    			End,
    		    Child, but = SimpleButton("_W porz�dku"),
    		    End,
    		End,
    	    End;
    
    	if (app != NULL)
    	{
    	    ULONG sigs = 0;
    
            // Wci�nij gad�et zamykania, b�d� ESC, aby wyj��
    	    DoMethod(wnd, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
                     (IPTR)app, 2,
                     MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
    
            // Wci�nij przycisk, aby wyj��
    	    DoMethod(but, MUIM_Notify, MUIA_Pressed, FALSE,
                     (IPTR)app, 2,
                     MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
    
            // Otw�rz okno
    	    set(wnd, MUIA_Window_Open, TRUE);

            // Sprawd�, czy okno zosta�o otwarte
    	    if (XGET(wnd, MUIA_Window_Open))
    	    {
                // P�tla g��wna
    		while((LONG)DoMethod(app, MUIM_Application_NewInput, (IPTR)&sigs)
    		      != MUIV_Application_ReturnID_Quit)
    		{
    		    if (sigs)
    		    {
    			sigs = Wait(sigs | SIGBREAKF_CTRL_C);
    			if (sigs & SIGBREAKF_CTRL_C)
    			    break;
    		    }
    		}
    	    }
	    // Zamknij aplikacj� i wszystkie jej obiekty
    	    MUI_DisposeObject(app);
    	}
    	
    	return(0);
    }


Uwagi
=====

Og�lne
------

Nie b�dziemy r�cznie otwiera� bibliotek, to jest automatycznie robione za nas.

Tworzenie GUI
-------------

U�ywamy j�zyka opartego o makra, aby w prosty spos�b zbudowa� nasze GUI.
Aplikacje Zune posiadaj� jeden, i tylko jeden obiekt Application::

    :	app = ApplicationObject,

Aplikacja mo�e mie� 0, 1 lub wi�cej obiekt�w Window ( czyli okien ). Najcz�ciej pojedy�cze::

    :	    SubWindow, wnd = WindowObject,

B�d� mi�y, podaj tytu� okna::

    :		MUIA_Window_Title, "Witaj �wiecie!",

Okno musi mie� jedno, i tylko jedno dziecko ( child ), zwykle grup�. Ta jest pionowa,
a to oznacza, �e jej dzieci b�d� ustawione pionowo::

    :		WindowContents, VGroup,

Grupa musi mie� conajmniej 1 dziecko, a tutaj jest po prostu text::

    :		    Child, TextObject,

Zune akceptuje r�ne rodzaje kod�w ESC ( tutaj, aby wyr�wna� tekst ) i nowe linie::

    :			MUIA_Text_Contents, "\33cWitaj �wiecie!\nJak si� masz?",

Makro ``End`` ko�czy ka�de rozpocz�te makro ``xxxObject`` ( tutaj, TextObject)::

    :			End,

Dodajmy drugie dziecko do naszej grupy, przycisk! Wraz ze skr�tem klawiaturowym ``w``
rozpocz�te poprzez podkre�lnik::

    :		    Child, but = SimpleButton("_Ok"),

Zako�cz grup�::

    :		    End,

Zako�cz okno::

    :		End,

Zako�cz aplikacj�::

    :	    End;

Kto wi�c jeszcze potrzebuje programu do tworzenia GUI? :]


Kontrola b��d�w
---------------

Je�li kt�ry� z obiekt�w w drzewie aplikacji nie mo�e zosta� utworzony, wtedy Zune zamyka
wszystkie obiekty dotychczas stworzone, i tworzenie aplikacji zostaje przerwane. Je�li nie,
to masz w pe�ni dzia�aj�c� aplikacj�::

    :	if (app != NULL)
    :	{
    :	    ...

Gdy ju� sko�czy�e�, po prostu wywo�aj ``MUI_DisposeObject()`` na swoim
obiekcie aplikacji, aby zamkn�� wszystkie obiekty z Twojej aplikacji,
i uwolnij wszystkie zasoby::

    :       ...
    :	    MUI_DisposeObject(app);
    :	}


Powiadomienia
-------------

Powiadomienia s� najprostsz� drog� do odpowiedzi na zdarzenia. Zasada?
Chcemy by� powiadamiani, gdy pewne atrybuty okre�lonego obiektu
s� ustawione do wybranej warto�ci::

    :        DoMethod(wnd, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,

Tutaj nas�uchujemy ``MUIA_Window_CloseRequest`` naszego obiektu Window
i b�dziemy powiadamiani, gdy tylko atrybut b�dzie mia� warto�� ``TRUE``.
Wi�c co si� dzieje, gdy powiadomienie wyst�pi? Wtedy wiadomo�� jest wysy�ana
do obiektu, i to tutaj m�wimy naszej aplikacji o tym, aby zwr�ci�a 
``MUIV_Application_ReturnID_Quit``, przy kolejnej iteracji p�tli::

    :                 (IPTR)app, 2,
    :                 MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

Jak ju� okre�limy wszystko, czego nam potrzeba, tak teraz musimy poda� liczb�
dodatkowych parameter�w, kt�re dostarczamy do MUIM_Notify: tutaj, 2 parametery.

Dla przycisku, nas�uchujemy jego ``MUIA_Pressed`` atrybutu: jest ustawiony na ``FALSE``
gdy tylko przycisk zostaje *uwolniony* ( odpowiadanie gdy przycisk zostaje wci�ni�ty
jest z�ym nawykiem, bo przecie� b�dziesz chcia� anulowa� wyb�r, poprzez przesuni�cie
kursora poza przycisk - i chcemy przecie� zobaczy� jak wyg�da, gdy jest wci�ni�ty ).
Zadanie jest to samo co poprzednio, wy�lij wiadomo�� do aplikacji::

    :        DoMethod(but, MUIM_Notify, MUIA_Pressed, FALSE,
    :                 (IPTR)app, 2,
    :                 MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);


Otwieranie okna
---------------

Okna nie s� otwarte, a� do momentu, w kt�rym je o to nie poprosimy::

    :        set(wnd, MUIA_Window_Open, TRUE);

Je�li wszystko idzie dobrze, Twoje okno powinno by� wy�wietlone w tym momencie. Ale mo�e
co� p�j�� nie tak! Wi�c nie zapomnij sprawdzi�, poprzez zapytanie atrybutu, czy zwraca `TRUE`::

    :        if (XGET(wnd, MUIA_Window_Open))


P�tla g��wna
------------

Pozw�l, �e zapoznam Ci� - m�j ma�y przyjacielu - z idealn� p�tl� zdarze�::

    :        ULONG sigs = 0;

Nie zapomnij zinicjowa� `signals` do `0` ... test p�tli jest metod� `MUIM_Application_NewInput`::

    :        ...
    :        while((LONG) DoMethod(app, MUIM_Application_NewInput, (IPTR)&sigs)
    :              != MUIV_Application_ReturnID_Quit)

Jako wej�cie pobiera `signals` ze zdarze�, kt�re musi przetworzy� ( wynik z ``Wait()`` lub `0` ),
zmodyfikuje t� warto�� do miejsca, gdzie sygna�y Zune czekaj� na ( do nast�pnego ``Wait()``)
i zwr�c� warto��. Ten mechanizm zwracania warto�ci, by� historycznie jedn� drog� do 
odpowiedzi na zdarzenia, ale by� brzydki i zosta� zarzucony w wizji wspania�ych 
zaawansowanych klasach i obiektowo-zorientowanej budowie.

Ca�o�� tej p�tli jest ca�kiem pusta, my tylko czekamy na sygna�y
Ctrl-C aby przerwa� p�tl�::

    :        {
    :            if (sigs)
    :            {
    :                sigs = Wait(sigs | SIGBREAKF_CTRL_C);
    :                if (sigs & SIGBREAKF_CTRL_C)
    :                    break;
    :            }
    :        }


Wniosek
-------

Ten program pozwala Ci na rozpocz�cie zabawy z GUI Zune, lecz na nic wi�cej.

-------------------
Zadania powiadomie�
-------------------

Jak widzisz w `hello.c`, u�ywasz `MUIM_Notify` do wywo�ania metody je�li zostanie
spe�niony okre�lony warunek.
Je�li chcesz aby Twoja aplikacja oddzia�ywa�a w okre�lony spos�b na zdarzenia, to
mo�esz u�y� jednego z poni�szych schemat�w:

+ `MUIM_Application_ReturnID`: mo�esz zapyta� swoj� aplikacj�, aby zwr�ci�a ID
  przy nast�pnej iteracji, i sprawdzi�a warto�� w p�tli. To jest paskudna stara
  metoda robienia takich rzeczy.
+ `MUIM_CallHook`, do wywo�ania standardowych Hook AmigaOS: to jest �rednie rozwi�zanie,
  nie jest zorientowane-obiektowo, ale nie tak paskudne.
+ klasy zaawansowane: ta metoda polega na jednej z Twoich klas. To jest najlepsze rozwi�zanie
  jako, �e obs�uguje zorientowan�-obiektowo budow� w aplikacjach.
  Zmusza Ci� do stworzenia w�asnej klasy, wi�c mo�e nie by� takie �atwe dla
  pocz�tkuj�cych lub ludzi, kt�rzy nie maj� na to czasu.
