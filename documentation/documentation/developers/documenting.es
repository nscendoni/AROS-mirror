====================================
Manual para la Documentaci�n de AROS
====================================

:Authors:   Adam Chodorowski, Matthias Rustler 
:Copyright: Copyright � 1995-2006, The AROS Development Team
:Version:   $Revision: 48788 $
:Date:      $Date: 2014-01-30 22:36:28 +0100 (Thu, 30 Jan 2014) $
:Status:    Work in progress.

.. Warning::

   �Este documento no est� terminado! Es muy probable que muchas partes
   est�n anticuadas, contengan informaci�n incorrecta o simplemente
   falten. Si quieres ayudar a rectificar esto, por favor cont�ctanos.

Este manual describe el sistema de documentaci�n de AROS. Est� dirigido
a los escritores de la documentaci�n como tambi�n a los
desarrolladores que deseen extender o enredarse con el sistema en s�.
Con este fin, el manual est� separado en tres partes: una 
introducci�n com�n, el modo de escribir la documentaci�n y 
por �ltimo las notas t�cnicas y las especificaciones. Adem�s de
informar sobre el uso del sistema, el segundo cap�tulo tambi�n contiene
algunas directrices generales a seguir cuando se escriba la 
documentaci�n de AROS.


.. Contents::


Introducci�n
============

La documentaci�n es vital para cualquier proyecto, al hacerlo *�til*. Lo
usual, en un proyecto con tan limitados esfuerzos de desarrollador como
el nuestro, es que la documentaci�n est� considerablemente demorada o ausente.
Adem�s, la mayor�a de los programadores no son tan buenos escribiendo 
documentos, as� que lo que ya se escribi� en general no es legible. Se 
necesitan combinar los esfuerzos de los desarrolladores y de los usuarios
para que la documentaci�n llegue a la meta de un "AROS Ultimate
Documentary". As� que si sabes de algunos usuarios que puedan ayudarnos, 
�s�lo perm�teles! =)


*FIXME: �Escribir algo m�s?*


Escribir la documentaci�n
=========================

El formato de la documentaci�n que usamos es ReStructuredText (o para
abreviar ReST) como est� especificado en el `Docutils Project`__.
ReST es una sintaxis de marcas de texto plano, extensible, f�cil
de leer y de escribir y del tipo "obtienes lo que ves".

Puede describirse como un h�brido entre una sintaxis de marcas 
impl�cita y una de marcas expl�cita, que lo hace f�cil de aprender 
y muy legible, y a la vez poderoso y extensible. La `Introduction to
reStructuredText`__ contiene algunos buenos puntos sobre las metas
que tiene la sintaxis.

Dado que el formato es b�sicamente texto plano es muy f�cil de aprender
simplemente inspeccionando la documentaci�n existente y usando el sentido
com�n, no obstante se recomienda al menos una ligera lectura del
`ReStructuredText Primer`__ antes de empezar a trabajar en la documentaci�n
de AROS.

Para m�s informaci�n sobre el formato, se recomienda leer los siguientes
documentos:

+ `Quick reStructuredText Reference`__

__ http://docutils.sourceforge.net/
__ http://docutils.sourceforge.net/docs/ref/rst/introduction.html
__ http://docutils.sourceforge.net/docs/user/rst/quickstart.html
__ http://docutils.sourceforge.net/docs/user/rst/quickref.html

El archivo de la documentaci�n
------------------------------

Para cambiar o escribir la documentaci�n necesitas descargar del
`subversion archive <svn>`_ 'documentation'. El archivo contiene:

+ algunos documentos comunes como contact.en, links.en, etc.
+ un directorio 'documentation' con la documentaci�n del usuario y del
  desarrollador
+ un directorio 'scripts' con los guiones usados para compilar los
  targets HTML y WWW
+ ...

.. Note::

    El archivo de subversion y el directorio con los manuales del usuario
    y del desarrollador tienen el nombre 'documentation'. No los mezcles.

Los subdirectorios
------------------

Puedes crear directorios adicionales en 'documentation/users' y en
'documentation/developers'. El build system explora recursivamente
los subdirectorios. Se recomienda que crees un archivo 'index.en' en
los nuevos directorios.

La internacionalizaci�n
-----------------------

El build system soporta I18n para el target 'www'. Tienes que
agregar un sufijo de idioma al nombre del archivo del documento (por ej.
commands.en).
Actualmente hay soporte para el ingl�s (.en), alem�n (.de), fin�s (.fi),
italiano (.it), ruso (.ru), sueco (.sv) y holand�s (.nl). Si deseas 
traducir la documentaci�n a m�s idiomas entonces por favor ponte en
contacto con nosotros a trav�s de la `website mailing list`__.

Cuando creas un enlace a un documento tienes que omitir el sufijo
(por ej. \`Commands <user/commands>\`_). Pero si usas el directorio
'include' para los documentos traducidos debes dejar el sufijo.

El build system usa la versi�n en ingl�s cuando no est� disponible
la traducci�n de una p�gina.

__ http://aros.sourceforge.net/contact.php#mailing-lists

El c�digo de muestra
--------------------

El directorio 'documentation/developers/samplecode' est� para los ejemplos
en c�digo fuente. El contenido se copia sin modificar a los targets.
           
Las im�genes
------------

Los nombres y las rutas de las im�genes est�n hard-coded en el gui�n
de python 'buildit.py'. Si quieres agregar im�genes tienes que cambiar
el gui�n. Si�ntete en libertad de hacer un pedido
de caracter�stica en la lista de correo del desarrollador si quieres que
esto se cambie.

Env�o
-----

Antes que env�es los documentos nuevos o modificados deber�as 
`build`__ ambos targets HTML y WWW localmente. Busca los mensajes de
error y rep�ralos. Comprueba el resultado en un navegador web. Lo normal
es que los cambios sean aplicados a http://aros.sourceforge.net/ algunas horas
despu�s de su env�o.

__ building_

 
Notas t�cnicas
==============

Las bases de datos
------------------

Hay varias peque�as bases de datos, que puedes encontrar en el directorio
``db``, que est�n en texto plano pero usan un par de formatos ligeramente
diferentes. Principalmente, esto es un artefacto hist�rico y quiz�s deber�a
ser rectificado en el futuro, pero por ahora es m�s f�cil mantenerlos
tal como est�n.


credits
~~~~~~~

Esto es una lista de las personas que han contribu�do con AROS. El
build system crea el archivo 'credits.en'. Este archivo se usa en
ambos targets WWW y HTML. Por favor f�jate que tambi�n deber�as
cambiar el archivo workbench/system/AboutAROS/db/credits en el dep�sito
de AROS.


quotes
~~~~~~

Las citas notables de las celebridades de AROS. El formato es
dicho;autor. El build system copia este archivo al target HTML.


mirrors
~~~~~~~

Puesto que AROS est� alojado en Sourceforge no hay servidores 
espejo. Este archivo es ignorado por el build system.


tasks
~~~~~

Es la base de datos TODO (Para Hacer). Este archivo no ha sido mantenido
por un largo tiempo y no es usado para los targets.


Sizes
~~~~~
Los archivos ``aros.size`` y ``contrib.size`` no se usan m�s y es 
probable que ser�n borrados.


Building
--------

Requerimientos
~~~~~~~~~~~~~~

Necesitar�s lo siguiente para compilar la documentaci�n de AROS 
desde cero:

+ Python__ 2.2.1

Para construir el sitio web necesitar�s adicionalmente:

+ The `Python Imaging Library`__ 1.1.3

MacOS X viene con Python pre-instalado, pero para compilar el
sitio web necesitar�s:

+ The `MacPorts`__ package 

+ The `MacPorts Python Imaging Library`__ 1.1.3

__ http://www.python.org/
__ http://www.pythonware.com/products/pil/
__ https://www.macports.org/
__ https://trac.macports.org/browser/trunk/dports/python/py-pil/

Setting up
~~~~~~~~~~

Antes de que empieces a compilar la documentaci�n, podr�a ser necesario
alg�n ajuste si la versi�n necesaria del interpretador Python
no se llama "python" en tu sistema. Si no es as�, simplemente puedes 
saltar esta secci�n.

Primero, copia los ajustes por omisi�n::

    % cd AROS/documentation/scripts/config
    % cp defaults user

Despu�s, edita el archivo ``user`` y aseg�rate que las variables son
correctas para tu sistema. Un archivo de configuraci�n de ejemplo 
podr�a verse algo as�::

    PYTHON=python

``PYTHON`` indica el nombre del interpretador de Python; podr�a tambi�n
ser una ruta absoluta si no lo tienes en la ruta de b�squeda. Podr�as 
necesitar establecerlo a ``python2`` o ``python2.2`` en algunos sistemas.


Targets
~~~~~~~

En este momento hay dos targets soportados:

+ ``www`` 
  
  Este target genera el sitio web de AROS que incluye toda la 
  documentaci�n, las novedades-noticias, las galer�as de fotograf�as
  con miniaturas y la informaci�n del estado. La documentaci�n
  se integrar� satisfactoriamente con el resto del sitio.

+ ``html``
  
  Este target genera el HTML separado de la documentaci�n, adecuado
  para la visi�n offline y la inclusi�n en los paquetes de documentaci�n.
  
  
Procedimiento
~~~~~~~~~~~~~

Para compilar un target espec�fico, simplemente invoca el gui�n de compilaci�n
con el nombre del target como primer argumento. El directorio actual
necesita ser la ra�z del �rbol de la documentaci�n. Por ejemplo, para
compilar el sitio web haz::

    > cd AROS/documentation
    > ./build www

Si quieres compilar la documentaci�n HTML separada::

    > cd AROS/documentation
    > ./build html

Consejo: agregar un sufijo de idioma (por ej. en, du o it) despu�s del nombre
del target dar� solamente las p�ginas para ese lenguaje. Todas las
p�ginas faltantes o no traducidas ser�n substitu�das por sus contrapartes
en ingl�s. Esto resulta en tiempos de compilaci�n enormemente reducidos. ::

    > cd AROS/documentation
    > ./build www du


Los archivos generados ser�n puesto en ``../bin/documentation/<target-name>``,
por ej. ``../bin/documentation/www`` para el target ``www``. Los
archivos espec�ficos de un lenguajes son puesto en ``../bin/documentation/<target-name>/<language-name>``.

Adicionalmente, hay un target ``clean``, que borrar� entero el 
directorio ``../bin/documentation``.

.. Note::

    Actualmente hay muchos archivos intermedios generados en
    los directorios fuente, as� que no puedes ponerlos en un sistema de
    archivo de solo-lectura. Si haz descargado los fuentes desde SVN
    no necesitas preocuparte: los archivos generados son ignorados seg�n
    sea apropiado.
