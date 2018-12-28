============
Contribuci�n
============

:Authors:   Adam Chodorowski 
:Copyright: Copyright � 1995-2007, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done. 

.. Contents::

.. Include:: contribute-abstract.es


Tareas disponibles
==================

Esta es una lista de algunas tareas con las que necesitamos ayuda y en las
que nadie est� trabajando ahora. No es una lista completa, simplemente contiene
las cosas m�s destacadas con las que necesitamos ayuda en AROS.


Programaci�n
------------

+ Implementar las bibliotecas, recursos, dispositivos faltantes o partes de �stas.
  Vea el informe de estado detallado para tener m�s informaci�n sobre lo que falta.

+ Implementar o mejorar los controladores de los dispositivos de hardware:
  
  - AROS/m68k-pp:
    
    + Graphics
    + Input (touchscreen, buttons)
    + Sound
    + Gr�ficos
    + Entrada (pantalla tactil, botones)
    + Sonido

     
  - AROS/i386-pc:
    
    + Specific graphic card drivers (we only have general, not very well
      accelerated ones). A short wishlist:
    + Los controladores de tarjetas gr�ficas espec�ficas (solamente tenemos unas
      generales, no muy bien aceleradas. Una breve lista de deseos:
      
      - nVidia TNT/TNT2/GeForce (started, but incomplete) 
      - S3 Virge
      - Matrox Millenium
    
    + missing USB classes
    + SCSI
    + Specific IDE chipsets
    + Sound
    + ...anything else you can think of.
    + las clases USB faltantes
    + SCSI
    + los chipsets IDE espec�ficos
    + Sonido

  - Un soporte gen�rico de la impresora.
 
+ Adaptar a otras arquitecturas. Algunos ejemplos de hardware para el cual no
  hay puertos de AROS mantenidos o iniciados:

  - Amiga, m68k y PPC.
  - Atari.
  - HP 300 series.
  - SUN Sparc.
  - iPaq.
  - Macintosh, m68k y PPC.

+ Implementar los editores de Preferencias faltantes:

  - Overscan
  - Palette
  - Pointer
  - Printer
 
+ Mejorar la biblioteca de enlace de C

  Esto significa implementar las funciones ANSI (y algunas POSIX) en la clib,
  para hacer m�s f�cil llevar software UNIX (eg. GCC, make y binutils). La cosa
  m�s grande que falta es el soporte para el se�alamiento de estilo POSIX, pero
  tambi�n otras funciones.

+ Implementar m�s datatypes y mejorar los existentes

  El n�mero de datatypes disponibles en AROS es bastante peque�o. Algunos
  ejemplos de datatypes que necesitar mejorar para convertirse en usables
  o necesitan ser implementados desde cero son:

  - amigaguide.datatype
  - sound.datatype
    
    + 8svx.datatype

  - animation.datatype
    
    + anim.datatype
    + cdxl.datatype
    
  
+ Adaptar programas de terceros:

  - Los editores de texto como ViM y Emacs.
  - La cadena de herramientas de desarrollo, que incluye GCC, make, binutils y
    las otras herramientas GNU.
  - El software de fuente abierta para el AmigaOS como SimpleMail, YAM, Jabbwerwocky.


Documentaci�n
-------------

+ Escribir la documentaci�n del usuario. Esto consiste en escribir una
  Gu�a de Usuario general para los novicios y los expertos, y tambi�n la 
  documentaci�n de referencia para todos los programas standard de AROS.

+ Escribir la documentaci�n del desarrollador. Aunque esto est� un poco 
  mejor que la documentaci�n del usuario, todav�a hay bastante trabajo
  para hacer. Por ejemplo, todav�a no hay un tutorial para los programadores
  novicios realmente bueno. Ser�a agradable tener el equivalente de los Manuales 
  del N�cleo de la ROM.

Traducci�n
----------

+ Traducir AROS a m�s idiomas. Actualmente, s�lo los siguientes
  lenguajes tienen un soporte m�s o menos completo:

  - English
  - Deutsch
  - Svenska
  - Norsk
  - Italiano
  - French
  - Russian

+ Traducir la documentaci�n y el sitio web a m�s idiomas. Actualmente, est�
  disponible por completo en ingl�s. Se han traducido partes a otros lenguajes,
  pero todav�a queda mucho por hacer.


Otras
-----

+ Coordinar el dise�o de la GUI para los programas AROS, como el programa Prefs,
  las herramientas y las utilidades.


Unirse al equipo
================

�Quieres unirte al esfuerzo de desarrollo? �Fant�stico! Entonces �nete a las
`development mailing lists`__ en las que est�s interesado (al menos se 
recomienda *mucho* unirse a la lista de desarrollo principal) y pide acceso
al dep�sito de Subversion. Eso es todo. :)

Escribe un breve mensaje a la lista de desarrollo que contenga una presentaci�n
de t� mismo y con qu� est�s animado para ayudar. Si tienes problemas, por favor
no dudes en enviar un mensaje a la lista o pregunta en los `IRC channels`__.
Tambi�n, antes de empezar en algo espec�fico, por favor escribe un mensaje a la
lista afirmando lo que est�s por hacer para actualizar la base de datos de tareas.
De esta manera podemos asegurar a la gente que no trabaje en la misma cosa por
error...

__ ../../contact#mailing-lists
__ ../../contact#irc-channels


El dep�sito de Subversi�n
-------------------------

El dep�sito de AROS est� funcionando en un servidor Subversion protegido con contrase�a,
lo que significa que necesitas pedir acceso a �l para poder colaborar en el desarrollo.
Las contrase�as est�n encriptadas; la puedes generar con nuestra `online password
encryption tool`__.

Por favor env�a la contrase�a encriptada junto tu nombre de usuario preferido y
tu nombre real a `Aaron Digulla`__ y espera una respuesta. Para facilitar una
r�pida respuesta, por favor pon en el campo asunto "Acces to the AROS SVN server"
y en el cuerpo "Please add <nombre de usuario> <contrase�a>", por ej.::

    Please add digulla xx1LtbDbOY4/E

Podr�a tardar un par de d�as porque Aaron est� bastante ocupado, as� que s� paciente.

Para informaci�n sobre c�mo usar el servidor SVN de AROS, por favor lee "`Working with
SVN`__". Incluso si ya sabes c�mo usar SVN es �til que lo mires pues contiene 
informaci�n y consejos espec�ficos para el dep�sito de AROS (por ej. sobre c�mo ingresar.

__ http://aros.sourceforge.net/tools/password.html 
__ mailto:digulla@aros.org?subject=[Access%20to%20the%20AROS%20SVN%20server]
__ svn
 
