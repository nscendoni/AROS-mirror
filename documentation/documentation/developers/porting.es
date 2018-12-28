=============
PORTING GUIDE
=============

:Authors:   Johann Samuellson, Matthias Rustler
:Copyright: Copyright � 2006, The AROS Development Team
:Version:   $Revision: 46215 $
:Date:      $Date: 2013-01-05 18:36:13 +0100 (Sat, 05 Jan 2013) $
:Status:    Beta
:ToDo:      Some real world examples


.. Contents::


Introducti�n
============

Esta gu�a es sobre la transferencia del software que viene con guionees 
configure o make a AROS.
Esto es verdad para la mayor�a del software de fuente abierta del mundo Linux.
Se basa en un `documento`__ escrito por Johan Samuellson para el AmigaOS4.

__ http://www.os4depot.net/index.php?function=showfile&file=document/manual/spots-pfd.lha

�Qu� transferir?
----------------

* El lenguaje con mejor soporte es C. A C++ le faltan algunas caracter�sticas.

* Mira qu� paquetes adicionales se necesitan para el software que quieres
  transferir. No puedes simplemente transferir cuando se necesitan bibliotecas
  de GUI como GTK o QT. �nicamente se puede transferir de modo directo el
  software que se ejecuta en modo consola.

* Cuando quieras trasferir juegos, mira si usan la `libSDL`__. Evita el
  software que requiera OpenGL.  
  
__ http://www.libsdl.org

Conseguir el SDK reciente
-------------------------

La manera m�s f�cil de transferir para AROS es desde una caja Linux,
porque en general tiene todas las herramientas necesarias. Mira en la
`Gu�a de Desarrollo`__ para la informaci�n sobre la instalaci�n del SDK.

__ app-dev/introduction.php#compiling-on-linux-with-gcc


Los fundamentos
---------------

Lo primero que debes hacer es revisar c�mo compilar tu proyecto.
Si hay un archivo llamado *configure* en el directorio ra�z del archive,
eso significa que tendr�s que configurarlo para tu plataforma. Mira en la
descripci�n del siguiente cap�tulo sobre c�mo hacer eso.

Luego de que el proyecto est� apropiadamente configurado es el momento
de hacer rodar al compilador.
Empieza a compilar tu proyecto tipeando ``make``.

Empero, si no hay un archivo llamado *configure*, busca uno llamado
*Makefile*. Ed�talo para que se ajuste con AROS y compila el proyecto
con ``make``.

Si todo est� compilado y enlazado ya est�s listo para probar tu puerto.
Un problema muy com�n es que no encuentre sus archivos de datos, y se
cuelgue. Corrige las rutas como se describe en el cap�tulo corregir-las-rutas,
y ejecuta de nuevo. 

Luego quita la informaci�n de depuraci�n de los binarios para hacerlos 
m�s peque�os.

�Listo! Ya tienes el puerto. �Ahora c�rgalo en http://archives.aros-exec.org
y en http://www.aminet.net!


C�mo configurar
===============

En Linux, los paquetes que tienen un gui�n configure por lo general se
instalan con tres pasos::

    ./configure
    make
    sudo make install

Lo que hace que la configuraci�n de AROS sea m�s dif�cil que, por ej. para 
AmigaOS4 es el hecho que estamos usando un compilador cruzado.

Tipea ``./configure --help`` para ver las opciones que est�n disponibles.
Si falla la configuraci�n podemos intentar deshabilitar algunas caracter�sticas.

Un ejemplo simple
-----------------

::

    ./configure CC=i386-aros-gcc \
    --build=local --host=i686-aros
    --disable-nls --without-x --without-pic --disable-shared

.. Hint::

    Tiene sentido escribir un comando de configure en un archivo de texto. De
    esta manera podemos f�cilmente ejecutarlo de nuevo escribiendo ``sh build.sh``.
    Pero antes que ejecutemos de nuevo al gui�n tenemos que hacer ``rm -f config.cache``
    para volver al estado inicial el proceso de configuraci�n.


Aqu� est� la explicaci�n de las opciones que usamos arriba:

``CC=i386-aros-gcc``
    Queremos usar el compilador para AROS. De otro modo obtendremos un binario para Linux.

``--build=local --host=i686-aros``
    Indica al gui�n configure que haga una compilaci�n cruzada para i686-aros.

``--disable-nls --without-x --without-pic --disable-shared``
    Deshabilita algunas caracter�sticas que no est�n soportadas por AROS.


.. Warning::

    No hagas ``sudo make install`` porque esto instalar� tu aplicaci�n en alguna
    ruta de Linux como */usr/local*.


Ejemplo de SDL (instalaci�n manual)
-----------------------------------

El siguiente ejemplo es para `Ltris`__, pero deber�a ser similar para las otras
aplicaciones SDL::

    ./configure CC=i386-aros-gcc  LDFLAGS="-nix" \
    --prefix=/PROGDIR \
    --build=local --host=i686-aros \
    --disable-nls --without-x --without-pic --disable-shared \
    --with-sdl-prefix=/usr/local/aros-sdk/i386-aros

``LDLAGS="-nix"``
    This enables Linux semantics for paths. Linux applications often use absolute paths to
    their data files. But an absolute Linux path like */usr/local/app* means for AROS: go one
    level up, then go into the *usr* directory.

``--prefix=/PROGDIR``
    Prefixes all paths with */PROGDIR*. Together with the *-nix* option this allows to use
    Linux paths during compiling and AROS paths during running.

``--with-sdl-prefix=/usr/local/aros-sdk/i386-aros``
    The configure script calls *sdl_config* to find out the required CFLAGS and LDFLAGS for SDL
    applications. Without this option it would call the Linux version of *sdl_config*, which
    would give wrong results.

Despu�s de una ejecuci�n exitosa del gui�n configure y de *make* tenemos que
copiar el binario de ltris y los archivos de datos de modo que el binario
encuentre a �stos::

    ltris
        ltris (binary)
        share
	    ltris
	        gfx
		sounds


__ http://lgames.sourceforge.net/index.php?project=LTris


Ejemplo de SDL (instalaci�n semiautom�tica)
-------------------------------------------

Podemos usar casi las mismas opciones de arriba::

    ./configure CC=i386-aros-gcc  LDFLAGS="-nix" \
    --prefix=/PROGDIR --bindir=/PROGDIR \
    --build=local --host=i686-aros \
    --disable-nls --without-x --without-pic --disable-shared \
    --with-sdl-prefix=/usr/local/aros-sdk/i386-aros

``--bindir=/PROGDIR`` 
    Evita se cree un subdiretorio *bin*.

No olvides la opci�n *--prefix* o sino instalar� los archivos de AROS en alguna 
de las rutas de Linux.

Ahora puedes recompilar tu proyecto (``make distclean``, ejecuta el gui�n
configure, ``make``). Ahora podremos invocar ``sudo make install``. Pero es
mejor dar primero los siguientes pasos:

+ sudo mkdir /PROGDIR
+ sudo chmod a+rwx /PROGDIR

Esto tiene la ventaja que podemos acceder a */PROGDIR* sin los derechos de root.
Ahora finalmente podemos hacer ``make install``, que instalar� el juego en 
*/PROGDIR*. Como �ste no es un buen lugar tenemos que copiarlo a un lugar en
donde AROS pueda alcanzarlo (por ej. cp -r /PROGDIR ~/AROS/games/ltris).

Recuerda hacer ``rm -rf /PROGDIR/*`` antes de compilar otro proyecto.


Errores comunes que pueden ocurrir cuando configures
----------------------------------------------------

Obtengo errores como target or host i686-aros isn't available.

Soluci�n:
  El gui�n *config.sub* probablemente sea viejo o no est�. Ejecuta ``autoconf``
  en el directorio ra�z del paquete. Si eso no ayuda, copia una versi�n reciente
  del archivo *config.sub* de por ej. */usr/share/automake*.

.. _autoconf: http://ftp.gnu.org/gnu/autoconf/

Obtengo errores como �ste:
  checking for IMG_Load in -lSDL_image... no

Soluci�n:
  Estamos enlazando con bibliotecas est�ticas, y necesitamos decir con
  exactitud con qu� enlazar. Ubica este rengl�n en el gui�n configure::

    LIBS="-lSDL_image $LIBS"

  SDL_image depende de algunas bibliotecas para que funcione correctamente,
  agr�galas de este modo::

    LIBS="-lSDL_image -lpng -ljpeg -lz $LIBS"


Obtengo errores como �ste:
  checking for Mix_OpenAudio in -lSDL_mixer... no

Solution:
  Estamos enlazando con bibliotecas est�ticas, y necesitamos decir con
  exactitud con qu� enlazar. Ubica este rengl�n en el gui�n configure::

    LIBS="-lSDL_mixer $LIBS"

  SDL_mixer depende de algunas bibliotecas para que funcione correctamente,
  agr�galas de este modo::

    LIBS="-lSDL_mixer -lvorbisfile -lvorbis -logg $LIBS"


Lo mismo sucede cuando configure est� buscando SDL_ttf, y ahora sabes
por qu�. Necesitamos especificar algunas bibliotecas m�s en las que
depende SDL_ttf. Necsita -lfreetype y -lz. Dejar� el resto para t� 
como un ejercicio.

Si has agregado las dependencias necesarias al gui�n configure, y 
todav�a no funciona puede deberse a archivos faltantes en el SDK.
Por ej. no est�n incluidas las bibliotecas SDL.

This is not recommended, but if there is no other way...
Si todav�a no funciona, y est� seguro que tienes la biblioteca
instalada, prueba con quitar toda la secci�n donde revisa la
biblioteca que falla en el archivo configure.

Ahora deber�as estar listo para build tu proyecto. Cuando transfieras
apps de unix siempre tipea ``make``.


Crear un makefile a mano
========================

Este makefile se podr�a usar is el build system es un mess y quieres 
simplificarlo un poco, alterarlo para que se ajuste a tus necesidades.
Lo usual es que solamente necesites modificar un makefile existente, cambia
el nombre del compilador de C (de otro modo crear�a binarios para Linux) y
agrega algunas bibliotecas de enlazado.

Aqu� est� la explicaci�n de lo que significan las banderas.
 
CC
    El nombre del ejecutable del compilador de C.

RM
    El nombre del comando delete.

STRIP
    The name of the strip command (used to remove debug data from exe files).

CFLAGS
    Tells the compiler where to find the includes (-I) etc.
    Indica al compilador d�nde hallar los includes (-I) etc.

LDFLAGS
    Indica al enlazador qu� bibliotecas incluir (-l) y d�nde
    hallarlas (-L).

OBJS
    El compilador (GCC/G++) compila a archivos objeto (#?.o) de tus
    archivos .c que despu�s son enlazados juntos para convertirse en
    un archivo ejecutable. Especifica aqu� los nombres de los archivos
    objeto.

OUTPUT
    El nombre del archivo ejecutable final.

::

  CC      = i386-aros-gcc
  RM      = rm
  STRIP   = i386-aros-strip --strip-unneeded --remove-section .comment
  CFLAGS  = -Wall -O2 
  LDFLAGS = -nix -lsmpeg -lSDL_gfx -lSDL_net -lSDL_image -lpng -ljpeg -lz -lSDL_mixer \
            -lvorbisfile -lvorbis -logg -lSDL_ttf -lfreetype -lz -lsdl -lauto -lpthread -lm
  OBJS    = a.o b.o c.o
  OUTPUT  = test.exe

  all: $(OBJS)
          $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(OUTPUT) 

  main.o: main.cpp main.h 
          $(CC) $(CFLAGS) -c main.cpp

  strip:
          $(STRIP) $(OUTPUT)
        
  clean:
          $(RM) -f $(OBJS) $(OUTPUT)

Recuerda que tienes que usar caracteres tabulador antes del comando.


Usar el build system
====================

El build system contiene algunos guiones para configurar los paquetes. La gran 
ventaja de usar el build system es que puedes transferir f�cilmente a diferentes 
sabores de AROS.

+ %build_with_configure
+ %fetch_and_build
+ %fetch_and_build_gnu_development

Mira en el archivo $(TOP/config/make.tmpl para una explicaci�n de los argumentos. En
*$(TOP)/contrib/gnu* ahora puedes hallar muchos paquetes GNU.


Misc
====

Convertir las rutas unix a rutas AROS
-------------------------------------

�C�mo convierto las rutas Unix en rutas AROS? Intercambia *getenv("HOME")* por *"/PROGDIR/"*

Ejemplos::

    old: strcpy(path, getenv("HOME"));
    new: strcpy(path, "/PROGDIR/");

    old: strcpy(home,getenv("HOME"));
    new: strcpy(home,"/PROGDIR/");

    old: sprintf(rc_dir, "%s/.gngeo/romrc.d", getenv("HOME"));
    new: sprintf(rc_dir, "%sgngeo/romrc.d", "/PROGDIR/");

F�jate que quit� "/." en el �ltimo ejemplo.

Las rutas a los directorios de los datos a menudo se establecen durante 
el proceso de configure haciendo *-DDATADIR=*. Si �ste es el caso establece a
*-DDATADIR=/PROGDIR/*. Tambi�n es com�n que el directorio de los datos 
se establezca en los makefiles. Ubica *DATADIR=* y c�mbialo a *DDATADIR=/PROGDIR/*


Defines
-------

Los defines se establecen en general en *config.h*, si algo est� mal configurado,
puedes cambiarlo ah� usando *#define* y *#undef*.

Un ejemplo de define que considera todos los sabores de AmigaOS::

  #ifdef __AMIGA__
	  blah blah blah
  #else 
          blah blah blah
  #endif

Un ejemplo de define que s�lo considera a AROS::

  #ifdef __AROS__
	  blah blah blah
  #else 
          blah blah blah
  #endif

Un ejemplo de define que considera a BeOS y a AROS::

  #if !defined(__BEOS__) && !defined(__AROS__)

Un ejemplo m�s complejo::

  #ifdef GP2X
	char *gngeo_dir="save/";
  #elif defined __AROS__
	char *gngeo_dir="/PROGDIR/save/";
  #else
	char *gngeo_dir=get_gngeo_dir();
  #endif

Algunos paquetes de fuente abierta ya han adoptado a los sistemas operativos
de la familia Amiga. Si encuentras algo como *#ifdef __AMIGA* en el fuente
puedes probar agregar el define a las opciones de configuraci�n (por ej.
CFLAGS="-nix -D__AMIGA__").


Entender los mensajes de error
------------------------------

Error: No return statement in function returning non-void 
  No hay un *return* en una funci�n que necesita uno.

Error: Control reaches end of non-void function
  Se lleg� al final de una funci�n que necesita devolver un valor, pero no hay ningun *return*.

Error: May be used uninitialized in this function
  La variable no est� inicializada.

Warning: implicit declaration of function 'blah blah'
  Necesitas incluir una cabecera.


Errores comunes
---------------

warning: incompatible implicit declaration of built-in function 'exit';
warning: incompatible implicit declaration of built-in function 'abort'::
  
    soluci�n: #include <stdlib.h>

warning: implicit declaration of function 'strlen';
warning: incompatible implicit declaration of built-in function 'strlen'::

    soluci�n: #include <string.h>

warning: implicit declaration of function 'memcpy';
warning: incompatible implicit declaration of built-in function 'memcpy'::

    soluci�n: #include <string.h>

error: memory.h: No such file or directory::

    soluci�n: #include <string.h>

error: malloc.h: No such file or directory::

    soluci�n: #include <stdlib.h>

warning: incompatible implicit declaration of built-in function 'printf'::

    soluci�n: #include <stdio.h>

warning: implicit declaration of function 'MyRemove'::

    soluci�n: #define MyRemove Remove


Consejos y trucos
-----------------

�C�mo hago una b�squeda de cadenas de texto usando GREP?

::

  grep -R "I am looking for this" *

�C�mo hago un archivo DIFF con mis cambios?

::

  diff originalfile.c mychangedfile.c >./originalfile.patch

Mi ejecutable se cuelga, �c�mo lo depuro?
  Mira en el `Manual para la Depuraci�n <debugging>`_. Puedes usar sys:utilites/snoopy
  para descubrir qu� intenta hacer tu aplicaci�n.

�C�mo dirigo las advertencias y errores de GCC a un archivo de texto?

::

  make 2>warnings.txt

