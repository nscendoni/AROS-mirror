==================
C�mo compilar AROS
==================

:Authors:   + Flavio Stanchina
            + Henning Kiel
            + Bernardo Innocenti
            + Lennard voor den Dag
            + Aaron Digulla
            + Adam Chodorowski
:Copyright: Copyright (C) 2001-2008, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done.
:Abstract:  
    Este documento explicar� c�mo compilar AROS. En la actualidad el
    desarrollo de AROS no se aloja en s� mismo, o sea que
    no puedes compilar AROS desde dentro de AROS. Para compilar y 
    desarrollar para AROS necesitar�s un systema Linux o FreeBSD.


.. Contents::


Requerimientos
==============

Se necesita el siguiente software para compilar AROS:

+ GCC 3.2.2+
+ GNU Binutils
+ GNU Make
+ GNU AWK (GAWK) - other awks may also be suitable
+ Python 2.2.1+
+ Bison
+ Flex
+ pngtopnm and ppmtoilbm (part of the netpbm package)
+ Autoconf
+ Automake
+ Los utilidades comunes como cp, mv, sort, uniq, head...

Si quieres compilar los puertos hosted i386-linux o i386-freebsd,
necesitar�s tambi�n:

+ las cabeceras y las bibliotecas de desarrollo de X11.

El c�digo fuente
================

Puedes descargar el c�digo fuente de AROS de la `download page`__
o usando SVN (aunque requiere que tu `apply for acces`__). En el primer
caso, es suficiente tener el paquete ``source`` (a menos que tambi�n
quieras compilar los programas contribu�dos). En el �ltimo caso, mira
en la `subversion documentation`__.

__ ../../download
__ ../../documentation/developers/contribute#the-subversion-repository
__ ../../documentation/developers/svn


Building
========

Configuraci�n
-------------

Antes que nada, necesitas ejecutar configure en la ra�z del c�digo fuente
de AROS::

    > cd AROS
    > ./configure

Puedes especificar varias opciones a configure. Est�n disponibles las
siguientes opciones para todos los targets:

``--enable-debug=LIST [default: none]`` 
    Habilita los diferentes tipos de depuraci�n. Se pueden usar comas o
    espacios para separar los elementos de la lista. Si no se proporciona
    una lista entonces se supone ``all``. Si no se especifica ``--enable-debug``
    por omisi�n es ``none``. Los tipos disponibles son:
    
    ``none``
        Deshabilita todos los tipos de depuraci�n y la depuraci�n misma.
    
    ``all``
        Habilita todos los tipos de depuraci�n siguientes.
        
    ``stack``
        Habilita la depuraci�n de la pila.
        
    ``mungwall``
        Habilita la depuraci�n de mungwall.
        
    ``modules``
        Habilita la depuraci�n de los m�dulos.
    

Hosted AROS/i386-linux or AROS/i386-freebsd
"""""""""""""""""""""""""""""""""""""""""""

No tienes que especificar la opci�n ``--target`` para compilar estos
targets. Est�n disponibles las siguientes opciones para los
compilados hosted:

``--with-resolution=WIDTHxHEIGHTxDEPTH [default: 800x600x8]``
    Set the default resolution and depth AROS will use. 
    Establece la resoluci�n y la profundidad que AROS usar� por omisi�n 
    
``--enable-xshm-extension [default: enabled]``
    Habilita el uso de la extensi�n MIT-SHM de X11. Da una ventaja
    de rendimiento significativa, pero podr�a no funcionar bien si est�s
    usando una pantalla remota.
    
No puedes hacer la compilaci�n cruzada de estos puertos.


Native AROS/i386-pc
"""""""""""""""""""

Para compilar el puerto i386-pc, necesitas pasar ``--target=pc-i386``
a configure. Adem�s, est�n disponibles las siguientes opciones espec�ficas
para i386-pc:

``--with-serial-debug=N [default: disabled]``
    Habilita la depuraci�n en serie, enviando la salida al puerto ``N``.
    
No puedes hacer la compilaci�n cruzada de este puerto.


La compilaci�n
--------------

Para empezar la compilaci�n, simplemente ejecuta::

    > make

Si esto no funciona despu�s de una actualizaci�n con SVN,
prueba::

    > make clean
    > rm -rf bin/
    > ./configure {options}
    > make

Si usas FreeBSD o alg�n otro sistema que no use GNU Make como el make del
sistema, entonces deber�as substitu�rlo con el comando GNU Make.
Por ejemplo, bajo FreeBSD deber�as instalar el puerto de GNU Make, 
despu�s ejecuta::

    > gmake


Hosted AROS/i386-linux or AROS/i386-freebsd
"""""""""""""""""""""""""""""""""""""""""""

Si est�s compilando un hosted i386-linux o i386-freebsd, deber�as
ejecutar tambi�n lo siguiente para configurar apropiadamente el soporte
del teclado::

    > make default-x11keymaptable


Native AROS/i386-pc
"""""""""""""""""""

Si est�s compilando el puerto nativo i386-pc, hallar�s una imagen
de un disquete de arranque en ``bin/pc-i386/gen/rom/boot/aros.bin`` 
despu�s de que la compilaci�n haya terminado. Adicionalmente puedes
crear una imagen ISO de arranque ejecutando::

    > make bootiso-pc-i386

La imagen ISO se encuentrar� en ``distfiles/aros-pc-i386.iso``.

Ap�ndice
========

Compilar varios targets de los mismos fuentes
----------------------------------------------
   
Si pretendes compilar varios targets diferentes de un mismo �rbol
de fuentes, primero tienes que ir por el paso de configuraci�n para 
cada uno de tus targets.
Puedes agregar targets en cualquier momento que quieras. El �ltimo
target especificado para configure es el target por omisi�n.

Para seleccionar un target espec�fico cuando compiles,
simplemente ejecuta make as�::

    > AROS_TARGET_ARCH=$ARCH AROS_TARGET_CPU=$CPU make
    
Donde ``$ARCH`` es la arquitectura del compilado buscado, y ``$CPU`` es
la CPU. Por ej., para compilar AROS/i386-pc ejecutar�as::

    > AROS_TARGET_ARCH=pc AROS_TARGET_CPU=i386 make

Si est�s compilando varios puertos que usan la misma CPU,
solamente tienes que especificar ``AROS_TARGET_ARCH`` ya que la CPU
quedar� igual.

Despu�s que hayas hecho "make" una vez, y algunos cambios sean hechos
a los archivos, puedes usar la compilaci�n r�pida de los cambios usando
el comando make <target-name>-quick.

Compilar los C�mo... (HowTo)
----------------------------

Esta gu�a paso a paso describir� c�mo preparar el ambiente de desarrollo
y compilar AROS en Ubuntu Linux 6.10 "Edgy Eft". Supongamos que tengas una
imagen de CD (iso) de los sitios de Ubuntu y hayas instalado el sistema.
Tambi�n deber�as ajustarlo para hacer que acceda a Internet.
      
Conseguir los paquetes necesarios
"""""""""""""""""""""""""""""""""

Puesto que al Live CD le faltan los paquetes necesarios tenemos que
conseguirlos de Internet.

    > sudo apt-get install subversion gcc-3.4 gawk bison flex netpbm autoconf automake1.4 libx11-dev

Necesitar�s ingresar tu contrase�a de usuario en el prompt.

Configurar el locale a ISO8859
""""""""""""""""""""""""""""""

Necesitaremos establecer el locale para usar los fuentes de AROS
y compilarlos.
S�lo encuentra la cadena en_US iso 8859-1 en la lista proporcionada
por las siguientes aplicaciones y esc�gela)::

     > sudo apt-get install localeconf
     > sudo dpkg-reconfigure localeconf

Luego estableceremos el locale de la consola:

     > sudo locale-gen "en_US"
     > sudo dpkg-reconfigure locales
     > export LANG="en_US.ISO-8859-1"

Instalar make v. 3.80
"""""""""""""""""""""

Para instalar la versi�n de make que necesitaremos, se deben
agregar los dep�sitos adicionales de Ubuntu. Lancemos la 
consola y ejecutemos::

     > sudo nano /etc/apt/sources.list

Agrega estos dos renglones ah�::

    deb http://us.archive.ubuntu.com/ubuntu breezy main restricted
    deb http://us.archive.ubuntu.com/ubuntu dapper main restricted
    (save and exit nano via "ctrl-x")
    (guarda y sal de nano con "ctrl-x")

Ahora obt�n la lista de los programas disponibles actualizados::

     > sudo apt-get update

Ahora usaremos el administrador de paquetes Synaptic. V� al men�::

    System > Administration > Synaptic package manager

Despu�s busca el paquete "make", escoge "make" en la ventana
derecha y establece la versi�n con ''package>force version..'' "3.80 (breezy)".



Obtener los fuentes
"""""""""""""""""""

Para encontrar m�s instrucciones sobre C�mo usar nuestro Dep�sito SVN
por favor refi�rete a `Working with Subversion <svn.php>`__

Para ser breve, los comandos que deber�s usar son los siguientes::

   > svn checkout https://svn.aros.org/svn/aros/trunk/AROS
   > cd AROS
   > svn checkout https://svn.aros.org/svn/aros/trunk/contrib


Configurar y compilar los fuentes de AROS
"""""""""""""""""""""""""""""""""""""""""

Primero estableceremos los par�metros y configuraremos::

      > export CC="gcc-3.4"
      > ./configure

Podr�as necesitar abrir de nuevo la consola cuando ./configure
encuentre problemas con el compilador.

Por �ltimo, tipea::

      > make

Esto tomar� un tiempo (hasta algunas horas en las
m�quinas lentas) :)
Despu�s de eso tendr�s compilado AROS hosted.
Por favor f�jate que podr�as necesitar un acceso a Internet durante el 
progreso, para descargar los m�s recientes fuentes de EUAE.

