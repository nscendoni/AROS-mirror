=========================
Trabajando con Subversion
=========================

:Authors:   Aaron Digulla, Adam Chodorowski 
:Copyright: Copyright (C) 1995-2002, The AROS Development Team
:Version:   $Revision: 48788 $
:Date:      $Date: 2014-01-30 22:36:28 +0100 (Thu, 30 Jan 2014) $
:Status:    Done.
:Abstract: 
    Subversion (o SVN para abreviar) es una herramienta de control de versi�n que
    mantiene una base de datos de los archivos de un proyecto. Con SVN, es posible
    inspeccionar y controlar los cambios aplicados a cualquier archivo espec�fico:
    qu� cambios fueron hechos y cu�ndo, qui�n hizo aquellos cambios, cu�l fue el
    prop�sito del cambio (como una entrada de registro), la posibilidad
    de revertir los cambios mal hechos, mezclar los cambios de varias personas 
    distintas y m�s.
    
    En esencia, hace *mucho* m�s f�cil colaborar entre un grupo de gente en un
    proyecto com�n permitiendo que todos sepan qu� est� pasando con los archivos,
    asegur�ndose que la gente no eche a la basura los cambios de los otros por error y
    proporcionando los medios para hacer todo esto en Internet. Naturalmente, la
    usamos para colaborar en AROS.


.. Contents::


Introducci�n
============

El servidor mantiene un "dep�sito" central, que es la base de datos principal�
que contiene el c�digo base com�n publicado del proyecto. Los desarrolladores
individuales tienen sus propias "copias de trabajo", que son copias locales de
la base de datos de un momento espec�fico junto con los cambios locales que el
desarrollador no carg� al servidor. Cuando un desarrollador quiere compartir 
sus cambios con el resto del equipo simplemente "env�a" sus cambios al
servidor usando el programa cliente, que se encarga de cargarlos y mezclarlos
con los cambios hechos por los otros desarrolladores.


El software
===========

UNIX
----

Si est�s ejecutando Linux, FreeBSD o cualquier otro clon moderno de UNIX entonces
s�lo necesitas instalar el software oficial SVN, versi�n 1.0 o superior,
para tu OS. Todas las distribuciones comunes de Linux vienen ya con el paquete
SVN.

Tambi�n hay una interfaz GUI interplataforma para el sistema de revisi�n
Subversion llamado `RapidSVN <http://rapidsvn.org/>`__, disponible para los
Unixes(las distribuciones GNU/Linux, FreeBSD, Sun Solaris y otras), Mac OS X
y Windows.

.. Note:: El servidor ejecuta Subversion 1.1 que se puede acceder con un cliente
          versi�n 1.0, 1.1 o 1.2.

SVN no funciona con la localizaci�n UTF-8. Tienes que cambiar el locale a
ISO8859 antes de cualquier acci�n con SVN.

AmigaOS
-------

Si est�s ejecutando AmigaOS, necesitar�s una pila TCP/IP y alg�n puerto
de SVN instalados. Una opci�n es el puerto para Amiga de Olaf Barthel que se
puede hallar en AminNET__ (busca "subversion").

__ http://main.aminet.net/

Windows
-------

Si ejecutars Microsoft Windows (TM) puedes usar el cliente SVN TortoisseSVN__, especialmente si
te gusta usar Windows Explorer. Este programa es de fuente abierta y gratuito, con muchas caracter�sticas
y un buen soporte. Por favor aseg�rate tambi�n que presentas los archivos con los fin de rengl�n estilo UNIX,
de otro modo puedes *romper* la generaci�n de c�digo.
Si los archivos que est�s cambiando tienen puesta la propiedad de SVN eol-style:nativa 
(ahora los nuevos archivos de cualquier modo) entonces puedes olvidarte, y los fin de rengl�n 
(EOL) se convertir�n autom�ticamente.
Ejemplos de editores que se sepa que pueden guardar tal EOL incluyen 
`Notepad++ <http://notepad-plus.sourceforge.net>`__, TigerPad (free 
enhanced notepad), `DOS Navigator OSP <http://dnosp.com/>`__, y muchos m�s.
Tambi�n est� disponible el cliente RapidSVN, como se dijo antes.

__ http://www.tortoisesvn.net/

MacOS X
-------

Si ejecutas MacOS X puedes usar uno de los varios puertos de SVN disponibles
como `el puerto de Subversion`__ de Martin Ott. Tambi�n puedes querer instalar un cliente
adicional con GUI como `svnX`__. svnX es el cliente SVN m�s puesto al d�a para OS X y
tambi�n soporta la integraci�n con, entre otros, el editor de texto gratuito
`Textwrangler`__ (antes BBedit Lite). F�jate que cuando uses Textwrangler u otro editor
de texto Mac, necesitar�s cambiar la codificaci�n de los caracteres del 'Macos roman' a
'ISO latin 1' (ISO8859) para tus documentos (haz el cambio en las preferencias). Para Textwrangler
todas las restantes configuraciones son correctas por omisi�n. 
Todas las aplicaciones nombradas son freeware y est�n disponibles como Binario Universal
para las Mac PPC e Intel. Como ya se dijo, tambi�n est� disponible RapidSVN.

__ http://www.codingmonkeys.de/mbo/
__ http://www.lachoseinteractive.net/en/community/subversion/svnx/
__ http://www.barebones.com/products/textwrangler/


Ingresar al servidor
====================


A diferencia de CVS, no necesitas ingresar (login) en el servidor. En su
lugar, SVN preguntar� cuando necesite conocer tu cuenta de usuario y 
contrase�a.

.. Note:: 

    El dep�sito de AROS est� funcionando sobre un srvidor SVN protegido por
    contrase�a, lo que significa que necesitas `solicitar acceso`__ para
    poder colaborar en el desarrollo. A pedido de Amiga Inc., el acceso
    an�nimo de solo-lectura al dep�sito est� deshabilitado.
          
__ contribute#joining-the-team


Obtener los fuentes de AROS
===========================

Para obtener una copia de los fuentes de AROS usa el comando "checkout", as�::

    > svn checkout https://svn.aros.org/svn/aros/trunk/AROS

Esto crear� un directorio llamado AROS y lo poblar� con todos los fuentes,
lo que podr�a tomar bastante tiempo si tienes una conexi�n lenta a la red.
El m�dulo "contrib" contiene los programas de terceros que han sido transferidos
a AROS. Tienes que descarga para compilar todos los sabores de AROS::

    > cd AROS
    > svn checkout https://svn.aros.org/svn/aros/trunk/contrib

.. Consejo::
    Despu�s de la descarga, SNV recordar� de d�nde vino el fuente.


Obtener los fuentes extras
==========================

Adem�s de los fuentes principales de AROS que descargaste en la secci�n
previa, hay tambi�n otras cosas en el servidor SVN no relacionadas directamente
al n�cleo del sistema operativo. Por ejemplo, el m�dulo "binaries" que 
contiene im�genes como capturas de pantalla, fondos de escritorio y cosas similares,
y el m�dulo "documentation" que contiene los fuentes del sitio web.

Puedes tener una lista de los m�dulos disponibles con el comando::

    > svn ls https://svn.aros.org/svn/aros/trunk/

Actualizar los fuentes
======================

Despu�s de haber descargado los fuentes, podr�as querer actualizarlos
peri�dicamente para tener los �ltimos cambios que los otros desarrolladores
han enviado. Para esto usa el comando "update"::

    > cd AROS
    > svn update
    
Esto mezclar� cualquier cambio que los otros desarrolladores hicieron en tus
fuentes y tambi�n buscar� los directorios y archivos nuevos que se han
agregados. Si alguien envi� cambios a un archivo que tu has cambiado
localmente, SVN intentar� mezclar los cambios autom�ticamente. Si ambos cambiaron
los mismos renglones SVN podr�a fallar en mezclar los fuentes. Cuando esto
sucede, SVN se quejar� y pondr� **ambas** versionea en el archivo separadas
por un ``<<<<``. Necesitar�s editar el archivo y resolver el conflicto a mano.

.. Warning:: 

    Porque SVN haya mezclado con �xito los cambios de los otros desarrolladores
    con los tuyos no significa que todo est� bien. SVN solamente se encarga del
    contenido *textual*; todav�a podr�a haber conflictos l�gicos despu�s de la 
    mezcla (por ej. el otro desarrollador podr�a haber cambiado la sem�ntica de
    la misma funci�n que usaste en tus cambios). Deber�as siempre inspeccionar
    los archivos que fueron mezclados y ver si todav�a tienen sentido.


Enviar los cambios
==================

Si has hecho algunos cambios y sientes que quieres compartir tu trabajo con 
los otros desarrolladores, deber�as usar el comando "commit"::

    > svn commit

Puedes especificar una lista de los archivos para enviar; de otra manera
SVN revisar� recursivamente el directorio actual y hallar� todos los archivos
que has cambiado y los enviar�.
Antes de enviar tus cambios al servidor para su incorporaci�n, SVN te pedir�
que ingreses un mensaje de registro. Este mensaje de registro deber�a 
contener una breve descripci�n de lo que has cambiado y en ciertos casos un
comentario para ellos. Los mensajes de registro bien escritos son muy importantes
porque pueden hacer mucho m�s f�cil para los otros desarrolladores ver 
r�pidamente lo que hiciste y quiz�s el por qu�. Los mensajes de registro son
reunidos y despu�s enviados en un mensaje de correo diario a la lista de 
correo de desarrollo para que todos puedan seguir a la par de los desarrollos
con el c�digo base.

Antes de enviar tus cambios en un directorio, deber�as hacer primero
una puesta al d�a ah� para ver si alguien m�s ha cambiado los archivos mientras
t� has estado trabajando en ellos. En caso de que eso suceda, necesitar�s resolver
cualquier problema antes de hacer el env�o. Tambi�n aseg�rate que has
probado tus cambios antes de enviarlos; al menos para que no rompan la compilaci�n.


Agregar nuevos archivos y directorios
=====================================

Para agregar archivos y directorios nuevos al dep�sito, usa el comando "add"::

    > svn add file.c
    > svn add dir

SVN no revisar� recursivamente de modo autom�tico en los directorios agregados
recientemente y agregar� los contenidos; tienes que hacerlo por t� mismo. 
Despu�s de haber agregado el archivo, necesitas usar el comando "commit"
para de verdad agregarlos al dep�sito.

.. Note::

    No agregues los archivos generados (usualmente *mmakefile*, *strings.h*) al
    dep�sito. De otro modo estos archivos no ser�n actualizados cuando el 
    archivo fuente se haya cambiado.

    
Ajustar las propiedades
=======================

Los sistemas operativos difieren en los c�digos que se usan para marcar el fin de
rengl�n. Para asegurarte que los archivos de texto que no son generados/modificados
en Linux tienen el correcto fin de rengl�n es necesario hacer::

    svn propset svn:eol-style native <source.c>

Subversion puede substituir las palabras clave especiales en los archivos fuente.
Para habilitar esto necesitas hacer::

    svn propset svn:keywords Author Date Id Revision <main.c>

.. Note::

    Puedes configurar Subversion para que ponga autom�ticamente las propiedades
    para ciertos tipos de archivo. Por favor consulta tu documentaci�n de Subversion.


Importar
========

Cuando quieras agregar una gran colecci�n de archivos, por ej. el c�digo fuente
de alg�n software existente, "svn add" se vuelve r�pidamente fastidioso. Para
esto deber�as usar el comando "svn import". Desafortunadamente, la secci�n sobre
el comando import en el manual de SVN es muy pobremente escrito, dado el ejemplo:

1. Pon los archivos y los directorios que quieres importar en donde te guste,
   mientras **no** sea en tu directorio de trabajo. Ejecuta el comando
   "import" en el directorio situado dentro de una copia existente de SVN
   que funcione puede llevar a resultados muy extra�os, as� que es mejor
   evitarlo.
   
2. Cambia el directorio que contiene los archivos que deseas importar::

       > cd name-1.2.3

3. Importa los archivos con el comando "svn import"::

       > svn import -m <logMessage> <destinationPath>

   Esto importar� recursivamente todos los archivos del directorio actual
   y de los internos en el dep�sito, en la ruta de destino y con el mensaje de 
   registro que has especificado. En realidad, no *todos* los archivos ser�n
   agregados: SVN ignorar� los nombres de archivo que son comunes para respaldo
   y los archivos ocultos, como ``#?.bak``, ``.#?`` y ``#?~``.

   No obstante, deber�as quitar todos los archivos que no quieres que 
   terminen en el dep�sito antes de que empiece la importaci�n. No intentes
   interrumpir SVN durante el import cuando veas que un archivo est� siendo
   agregado que no quiera. S�lo haz una nota y despu�s borra el archivo.
   
   Por ejemplo, digamos que quieres importar los fuentes de SVN 1.1.3
   en el directorio "contrib/development/versioning/svn"::

      > cd subversion-1.1.3
      > svn import -m "Initial import of SVN 1.11.12" 
      \ https://svn.aros.org/svn/aros/trunk/contrib/development/versioning/svn

Lecturas adicionales
====================

Informaci�n m�s detallada sobre SVN se puede encontrar por supuesto en las p�ginas
del manual (man pages) y en los archivos distribu�dos con el mismo SVN, y tambi�n
hay numerosos sitio que contienen tutoriales y gu�as �tiles que podr�an ser
m�s f�ciles de leer.
Las siguientes p�ginas se recomiendan bastante:

+ `Version Control with Subversion`_
+ `Subversion Home`_

.. _`Version Control with Subversion`: http://svnbook.red-bean.com/
.. _`Subversion Home`:               http://subversion.tigris.org/

