=============================
Introducci�n al Shell de AROS
=============================

:Authors:   Matthias Rustler 
:Copyright: Copyright � 2006, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Draft

-------------

`�ndice <index>`_

-------------

AROS tiene una interfaz de l�nea de comandos, el 'Shell'.
Puedes iniciarla con el men� Wanderer>Shell. Se abrir� una ventana
con la ruta de la ventana actual de AROS. El prompt normalmente
muestra el n�mero de Shell y la ruta actual.

El Shell tiene un registro de historial de los comandos ingresados.
Puedes acceder a �l con las teclas de cursor arriba y abajo.

Hay una funci�n de finalizaci�n. Si tipeas las primeras letras
de un comando o nombre de archivo y aprietas el tabulador, el Shell buscar�
un nombre acorde. Si hay m�s opciones se abrir� una ventana donde podr�s
seleccionar una entrada.

Los comandos de AROS y los nombres de archivo no son sensitivos a las
may�sculas. Incluso puedes mezclar may�sculas y min�sculas.

AROS busca los comandos en el directorio actual y en la ruta de b�squeda.
Puedes ver y cambiar la ruta de b�squeda con el comando `path <path>`_

Algunos importantes comandos
----------------------------
+ `CD <cd>`_ -- cambia el directorio actual.
+ `DIR <dir>`_ -- muestra el contenido del directorio actual.
+ `COPY <copy>`_ -- copia archivos y directorios.
+ `DELETE <delete>`_ -- borra archivos y directorios.
+ `INFO <info>`_ -- muestra las unidades disponibles.
+ `MAKEDIR <makedir>`_ -- crea directorios.
+ `RENAME <rename>`_ -- renombra archivos y directorios.
+ `TYPE <type>`_ -- muestra el contenido de un archivo de texto.

La ruta
-------
Las rutas absolutas empiezan con el nombre de la unidad y los dos puntos (:),
los directorios se separan con una barra inclinada (/).
El nombre de la unidad puede ser un nombre de dispositivo (dh0:),
un nombre de volumen (workbench:) o una unidad l�gica (vea el comando
`assign <assign>`_ )

::
  
  Ejemplo: dh0:dir1/dir2/file.dat

Si necesitas la ruta actual como argumento de un comando, puedes escribir "".

::

  Ejemplo: copy from ram:x to ""
  
Un signo de dos puntos solo, significa el directorio base de la ruta actual.
Cuando la ruta empieza con dos puntos entonces es una relativa al
directorio base de la ruta dada.

Una barra inclinada al inicio de una ruta significa un nivel arriba. Dos barras
inclinadas significan dos niveles arriba, y as� en m�s.

Cuando una ruta contiene espacios debe escribirse entre comillas (").

::

  Ejemplo: type "un nombre con espacios"

La plantilla de comando
-----------------------
Un signo de interrogaci�n despu�s de un comando muestra la plantilla de par�metros 
del comando. El comando est� en modo de espera a que tipees en los par�metros.

::

  Ejemplo: copy ?
  FROM/M,TO/A,ALL/S,QUIET/S,BUF=BUFFER/K/N,CLONE/S,DATES/S,NOPRO/S,COM/S,NOREQ/S

Las palabras clave pueden tener opciones::

  /A -- se debe dar el argumento.
  /K -- la palabra clave debe ser escrita cuando se use este argumento.
  /S -- switch; s�lo escribe la palabra clave para acceder al switch.
  /N -- el argumento es num�rico.
  /M -- es posible m�s de un argumento.
  /F -- el resto de la l�nea de comandos. 
  =  -- abreviaci�n; puedes usar opcionalmente la abreviaci�n.

Cuando invoques un comando se puede usar '=' para asignaciones distintas entre palabra clave
y valor::

  Ejemplo: copy from=a.dat to=b.dat
  
Los patrones
------------
Algunos comandos permiten patrones para los par�metros de nombre de archivo::

  ?  -- un caracter cualquiera
  #? -- cero o m�s caracteres cualquiera
  #x -- cero o m�s x
  ~  -- negaci�n
  |  -- o
  () -- grupo
  [] -- rango

Ejemplos::

  dir #?.info
  dir #?~(.info)
  dir a(b|c)d
  dir [a-c]e

La redirecci�n
--------------

::

  > redirige la salida a un archivo o un dispositivo.
  >> redirige la salida y la anexa a un archivo.
  < redirige la entrada desde un archivo o un dispositivo.
  Ejemplo: dir >ram:a 

La tuber�a
----------
Si quieres enviar la salida de un comando a otro puedes usar la tuber�a
Tienes que conectar los comandos con el caracter \|. Debe haber al menos un
espacio antes y despu�s del \|::

  Ejemplo: dir | othercommand

  
�Pero si el segundo comando quiere leer la entrada desde un archivo? La soluci�n
es usar el dispositivo falso 'in:'::

  Ejemplo: dir | more in:  

Los dispositivos especiales
---------------------------
+ ram: puedes usar el disco ram como una unidad de disco r�gido. Pero
  despu�s de un reset su contenido se pierde.
+ nil: si no quieres que se muestren los mensajes de un comando en
  la ventana puedes usar el dispositivo 'nil:'. Ejemplo: delete #? >nil:

La ejecuci�n en segundo plano
-----------------------------
Normalmente, un comando bloquea al Shell hasta que termina de ejecutarse.
Puedes ejecutar comandos en segundo plano con el comando `run <run>`_.

::

  Ejemplo: run delete #?

Los archivos info
-----------------
Los archivos que tienen el sufijo '.info' juegan un papel importante en
Wanderer. Contienen la imagen del �cono e informaci�n adicional. Cuando trabajas
con los comandos del shell tienes que tener en cuenta a los archivos Info. 
