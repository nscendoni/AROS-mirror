==================================================
Manual para el Desarrollo de Aplicaciones con Zune
==================================================

:Authors:   David Le Corfec
:Copyright: Copyright � 2004, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Unfinished;
:ToDo:      All


.. Contents::


------------
Introducci�n
------------

�Qu� es Zune?
=============

Zune es una biblioteca de elementos para la GUI (Interfaz
Gr�fica de Usuario) orientada a objetos. Es un clon cercano 
(a nivel de API y de Aspecto&Sensaci�n) de MUI, un producto shareware bien 
conocido del Amiga de Stefan Stuntz. Por eso los desarrolladores de 
MUI aqu� se sentir�n en casa; los otros descubrir�n los conceptos 
y las cualidades que Zune comparte con MUI.

+ El programador tiene a much easier time para dise�ar su
  GUI: no necesita de los valores hardcoded, Zune es 
  sensible a los cambios de las fuentes, y se adapta a cualquier tama�o de
  ventana gracias a su sistema de disposici�n de los elementos.
  En su mayor�a tiene que darle a Zune la sem�ntica de su GUI,
  y Zune le acomodar� los detalles de bajo nivel de manera 
  autom�tica.

+ Como un efecto lateral, el usuario tiene m�s control del Aspecto&Sensaci�n
  de la GUI: es �l quien decide los ajustes particulares que Zune
  usar� para presentar la GUI dise�ada por el programador.

Zune se basa en el sistema BOOPSI,  el entorno de trabajo heredado del AmigaOS
para la programaci�n orientada a objetos en C. Las clases de Zune no derivan
de las existentes clases de gadget BOOPSI; en su lugar, la clase
Notify (Notificar) (la clase base de la jerarqu�a de Zune) deriva de la
clase ra�z de BOOPSI.


Requisitos previos
==================

Es bienvenido algo de conocimiento en la programaci�n OO (orientada a 
objetos). Si no lo tienes, Google puede ayudarte a encontrar buenos 
documentos introductorios sobre este tema.

Es esencial conocer las APIs y conceptos de AROS (o de AmigaOS) como 
las taglists (listas de etiquetas) y BOOPSI. Tener los Amiga Reference
Manuals (Manuales de Referencia del Amiga) (tambi�n conocidos como RKM)
es muy pr�ctico.

Como Zune es un clon de MUI, toda la documentaci�n pertinente a MUI se
aplica a Zune. En particular, los m�s recientes kits del desarrollador
de MUI que est�n disponibles se pueden encontrar aqu�__. En este archivo LHA,
son c�lidamente recomendados dos documentos:

+ `MUIdev.guide`, la documentaci�n del programador de MUI.
+ `PSI.c`, el c�digo fuente de una aplicaci�n que demuestra todas las modernas
  pr�cticas de MUI como el dise�o orientado a objeto y la creaci�n 
  din�mica de objetos.

__ http://main.aminet.net/dev/mui/mui38dev.lha

Adicionalmente, este archivo contiene los autodocs de MUI, que son
los documentos de referencia para todas las clases de Zune.


-------------
BOOPSI Primer
-------------

Conceptos
=========

Clase
-----

Una clase se define por su nombre, su clase antecesora y un dispatcher.

+ el nombre: una cadena para las clases p�blicas, as� puedan ser usadas por
  cualquier programa en el sistema, o nada si es una clase privada usada
  �nicamente por una aplicaci�n.

+ la clase antecesora: todas las clases BOOPSI forman una jerarqu�a con ra�z
  en la clase con el apropiado nombre de rootclass (clasera�z). Esto 
  permite que cada subclase implemente su propia versi�n de una operaci�n
  espec�fica del padre, o fall back vuelvan a una proporcionada por su padre.
  Tambi�n se la conoce como clase base o s�per clase.

+ el dispatcher: da acceso a todas las operaciones (llamadas m�todos)
  proporcionadas por esta clase, asegurando que cada operaci�n sea
  manejada por el c�digo apropiado o sea pasada a su s�per clase.

El tipo BOOPSI para una clase es ``Class *`` tambi�n conocida como
``IClass``.

Objeto
------

Un objeto es una instancia de una clase: cada objeto tiene sus
datos espec�ficos pero entre objetos de una misma clase se comparte el
comportamiento.
Un objeto tiene varias clases si contamos los antecesores de su clase 
verdadera (la m�s derivada, o sea la clase del objeto) hasta la clase ra�z.

El tipo BOOPSI para un objeto es ``Object *``. No tiene un campo al que
puedas acceder directamente.

Atributo
--------

Un atributo est� relacionado a los datos de la instancia de cada objeto:
no puedes acceder a los datos directamente, solamente puedes establecer (set)
u obtener (get) los atributos proporcionados por un objeto para
modificar su estado interno. Un atributo est� implementado como un
Tag (etiqueta) (un valor ``ULONG`` o con ``TAG_USER``).

``GetAttr()`` y ``SetAttrs()`` se usan para modificar los atributos de
un objeto.

Los atributos puede ser uno o m�s de los siguientes:

+ Initialization-settable (``I``) :
  el atributo puede ser pasado como un par�metro en la creaci�n del objeto.
+ Settable (``S``) :
  Puedes establecer este atributo en cualquier momento (o al menos, tambi�n
  despu�s de la creaci�n del objeto).
+ Gettable (``G``) :
  Puedes obtener el valor de este atributo.

M�todo
------

Un m�todo BOOPSI es una funci�n que recibe como par�metros un objeto,
una clase y un mensaje:

+ el objecto: es el objeto sobre el que act�as.
+ la clase: es la clase considerada para este objeto.
+ el mensaje: contiene un ID (identificador) de m�todo que determina
  la funci�n a invocar dentro de un dispatcher, seguido por sus 
  par�metros.

Para enviar un mensaje a un objeto, usa ``DoMethod()``. Usar� primero la
clase verdadera. Si la clase implementa este m�todo, lo manejar�.
Sino probar� con su clase antecesora, hasta que el mensaje sea manejado o
se alcance la clase ra�z (en este caso, el mensaje desconocido es
silenciosamente descartado).

Ejemplos
========

Veamos unos ejemplos b�sicos de este entorno de trabajo OOP:

Obtener un atributo
-------------------

Consultaremos el contenido de un objeto Cadena MUI::

    void f(Object *string)
    {
        IPTR result;
        
        GetAttr(string, MUIA_String_Contents, &result);
        printf("String content is: %s\n", (STRPTR)result);
    }

+ ``Object *`` es el tipo de los objetos BOOPSI.
+ ``IPTR`` se debe usar para el tipo de resultado, que puede ser un entero
  o un puntero. Un IPTR siempre se escribe en la memoria, �por eso usar
  un tipo m�s peque�o llevar�a a una corrupci�n de la memoria!
+ Aqu� consultamos a un objeto MUI String sobre su contenido: 
  ``MUIA_String_Contents``, como cualquier atributo, es un ``ULONG``
  (o sea, es un Tag).

Las aplicaciones Zune usan m�s a menudo las macros ``get()`` y ``XGET`` en vez de::

    get(string, MUIA_String_Contents, &result);
    
    result = XGET(string, MUIA_String_Contents);


Estableciendo un atributo
-------------------------

Cambiemos es contenido de nuestra cadena::

    SetAttrs(string, MUIA_String_Contents, (IPTR)"hello", TAG_DONE);

+ Los par�metros puntero deben ser convertidos a `IPTR` para evitar
  las advertencias.
+ Despu�s del par�metro de objeto, se pasa una taglist a `SetAttrs`
  y as� debe terminar con `TAG_DONE`.

Encontrar�s �til la macro ``set()``::

    set(string, MUIA_String_Contents, (IPTR)"hello");

Pero solamente con SetAttrs() puedes poner varios atributos a la vez::

    SetAttrs(string,
             MUIA_Disabled, TRUE,
             MUIA_String_Contents, (IPTR)"hmmm...",
             TAG_DONE);


Invocando un m�todo
-------------------

Veamos al m�todo m�s llamado en un programa Zune, el m�todo de 
procesamiento de eventos invocado en el bucle principal::

    result = DoMethod(obj, MUIM_Application_NewInput, (IPTR)&sigs);

+ Los par�metros no tienen una taglist, y as� no terminan con ``TAG_DONE``.
+ Tienes que hacer la conversi�n de los punteros a ``IPTR`` para evitar las
  advertencias.

-----------
Hola, mundo
-----------

.. Figure:: zune/images/hello.png

    First things first! I knew you would be all excited.
    �Primero lo primero! S� que estar�s exitado.


Fuente
======

Estudiemos nuestro primero ejemplo de la vida real::

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
    
        // GUI creation
    	app = ApplicationObject,
    	    SubWindow, wnd = WindowObject,
    		MUIA_Window_Title, "Hello world!",
    		WindowContents, VGroup,
    		    Child, TextObject,
    			MUIA_Text_Contents, "\33cHello world!\nHow are you?",
    			End,
    		    Child, but = SimpleButton("_Ok"),
    		    End,
    		End,
    	    End;
    
    	if (app != NULL)
    	{
    	    ULONG sigs = 0;
    
            // Click Close gadget or hit Escape to quit
    	    DoMethod(wnd, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
                     (IPTR)app, 2,
                     MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
    
            // Click the button to quit
    	    DoMethod(but, MUIM_Notify, MUIA_Pressed, FALSE,
                     (IPTR)app, 2,
                     MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
    
            // Open the window
    	    set(wnd, MUIA_Window_Open, TRUE);

            // Check that the window opened
    	    if (XGET(wnd, MUIA_Window_Open))
    	    {
                // Main loop
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
	    // Destroy our application and all its objects
    	    MUI_DisposeObject(app);
    	}
    	
    	return 0;
    }


Observaciones
=============

General
-------

No abrimos a mano las bibliotecas, se hace autom�ticamente para nosotros.

Creaci�n de la GUI
------------------

Usamos un lenguaje basado en macros para facilitar la construcci�n
de nuestra GUI.
Una aplicaci�n Zune tiene siempre 1 y solamente 1 objeto Application::

    :	app = ApplicationObject,

Una aplicaci�n puede tener 0, 1 o m�s objetos Window. Lo m�s com�n es 
uno solo::

    :	    SubWindow, wnd = WindowObject,

S� bueno, dale un t�tulo a la ventana::

    :		MUIA_Window_Title, "Hello world!",

Una ventana debe tener 1 y s�lo 1 hijo, lo usual es un grupo. �ste es vertical,
lo que significa que sus hijos estar�n acomodados verticalmente::

    :		WindowContents, VGroup,

Un grupo al menos debe tener 1 hijo, aqu� es s�lo un texto::

    :		    Child, TextObject,

Zune acepta varios c�digos de escape (aqu�, para centrar el texto)
y los saltos de rengl�n::

    :			MUIA_Text_Contents, "\33cHello world!\nHow are you?",

Y una macro ``End`` debe corresponder a cada macro ``xxxObject``
(aqu�, TextObject)::

    :			End,

Agreguemos un segundo hijo a nuestro grupo,�un bot�n! Con un atajo de 
teclado ``o`` indicado por un subrayado::

    :		    Child, but = SimpleButton("_Ok"),

Terminar el grupo::

    :		    End,

Terminar la ventana::

    :		End,

Terminar la aplicaci�n::

    :	    End;

Entonces, �qui�n necesita todav�a un constructor de GUI? :-)


Manejo de errores
-----------------

Si alguno de los objetos en el �rbol de la aplicaci�n no se puede crear,
Zune destruye todos los objetos ya creados y la creaci�n de la aplicaci�n
falla. Si no, tienes una aplicaci�n totalmente en funcionamiento::

    :	if (app != NULL)
    :	{
    :	    ...

Cuando est�s listo, s�lo invoca ``MUI_DisposeObject()`` sobre tu objeto
aplicaci�n para destruir todos los objetos actuales en la aplicaci�n,
y libera todos los recursos::

    :       ...
    :	    MUI_DisposeObject(app);
    :	}


Notificaciones
--------------

Las notificaciones son la manera m�s simple para reaccionar a los
eventos. �El principio? Queremos ser notificados cuando cierto atributo
de cierto objeto sea puesto a un cierto valor::

    :        DoMethod(wnd, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,

Aqu� escucharemos al ``MUIA_Window_CloseRequest`` de nuestro objeto
Window y seremos notificados cuando este atributo sea puesto a ``TRUE``.
�Qu� pasa cuando se dispara una notificaci�n? Se env�a un mensaje a un
objeto, aqu� le diremos a nuestra Application que salga
``MUIV_Application_ReturnID_Quit`` en la siguiente vuelta del bucle
de eventos::

    :                 (IPTR)app, 2,
    :                 MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

Puesto que podamos especificar cualquier cosa que queramos aqu�, tenemos
que decir el n�mero de par�metros extra que estamos suministrando a
MUIM_Notify: aqu�, 2 par�metros.

Para el bot�n, escuchamos a su atributo ``MUIA_Pressed``: es puesto a 
``FALSE`` cuando el bot�n es *soltado* (reaccionar cuando es apretado es
una mala pr�ctica, podr�as querer liberar el rat�n afuera del bot�n para
cancelar tu acci�n - adem�s queremos ver c�mo se ve cuando es apretado).
La acci�n es la misma que la anterior, env�a un mensaje a la aplicaci�n::

    :        DoMethod(but, MUIM_Notify, MUIA_Pressed, FALSE,
    :                 (IPTR)app, 2,
    :                 MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);


Abrir la ventana
----------------

Las ventanas no se abren hasta que t� se lo pides::

    :        set(wnd, MUIA_Window_Open, TRUE);

Si todo va bien, tu ventana deber�a mostrarse en este punto. �Pero puede
fallar! As� que no olvides revisar eso consultando el atributo, que 
deber�a ser TRUE::

    :        if (XGET(wnd, MUIA_Window_Open))


El bucle principal
------------------

D�jame presentarte a mi leal amigo, el bucle de eventos ideal de Zune::

    :        ULONG sigs = 0;

No olvides inicializar las se�ales a 0 ...
La prueba del bucle es el m�todo MUIM_Application_NewInput::

    :        ...
    :        while((LONG) DoMethod(app, MUIM_Application_NewInput, (IPTR)&sigs)
    :              != MUIV_Application_ReturnID_Quit)

Toma como entradas las se�ales de los eventos que tiene que procesar
(el resultado de ``Wait()`` o 0), modificar� este valor para ubicar las
se�ales que Zune est� esperando (para el siguiente ``Wait()``) y 
devolver� un valor. Este mecanismo de valor devuelto hist�ricamente
era la �nica manera para reaccionar a los eventos, pero era feo 
y ha quedado obsoleto favor de las clases custom y el dise�o OO.

El cuerpo del bucle est� casi vac�o, solamente esperamos se�ales y 
manejamos Ctrl-C para salir del bucle::

    :        {
    :            if (sigs)
    :            {
    :                sigs = Wait(sigs | SIGBREAKF_CTRL_C);
    :                if (sigs & SIGBREAKF_CTRL_C)
    :                    break;
    :            }
    :        }


Conclusi�n
----------

Este programa te inicia con Zune, y te permite jugar con el dise�o
de la GUI, pero nada m�s.


------------------------
Acciones de notificaci�n
------------------------

Como vimos en hello.c, usas MUIM_Notify para invocar un m�todo si ocurre
cierta condici�n.
Si quieres que tu aplicaci�n reaccione de una manera espec�fica a los
eventos, puedes usar uno de estos planes:

+ MUIM_Application_ReturnID: puedes pedirle a tu aplicaci�n que devuelva
  un ID arbitrario en la siguiente iteraci�n del bucle, y revisar el
  valor en el bucle. Es la vieja y sucia manera de hacer las cosas.
+ MUIM_CallHook, para llamar al standard callback hook del Amiga: esta
  es la elecci�n promedio, no OO pero tampoco fea.
+ un m�todo custom: el m�todo pertenece a una de tus clases custom.
  �sta es la mejor soluci�n que soporta el dise�o OO en la aplicaciones.
  Requiere que crees las clases custom, puede que no sea lo m�s f�cil
  para los principiantes o para la gente apurada.
