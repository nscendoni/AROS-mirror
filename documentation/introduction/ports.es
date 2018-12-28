=======
Puertos
=======

:Authors:   Adam Chodorowski, Matthias Rustler 
:Copyright: Copyright � 1995-2006, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done.

.. Contents::


Introducci�n
============

Puesto que AROS es un sistema operativo port�til, est� disponible para
varias diferentes plataformas. Un "puerto" de AROS es exactamente lo que
la palabra implica, una versi�n de AROS adaptada a alguna plataforma 
espec�fica.


Sabores
-------

Los puertos est�n divididos en dos grupos mayores, o "sabores" en la 
terminolog�a de AROS, denominados "nativo" y "alojado".

Los puertos nativos se ejecutan directamente sobre el hardware y tienen
un control total de la computadora. En el futuro �stos se convertir�n en
la manera recomendada para ejecutar AROS ya que tiene un rendimiento y 
eficiencia superior, pero hoy est�n demasiado incompletos para ser 
�tiles (al menos para desarrollar).

Los puertos alojados funcionan encima de otro sistema operativo y no 
tienen acceso directo al hardware, pero usan las capacidades 
proporcionadas por el OS anfitri�n. Las ventajas de los puertos alojados 
es que son m�s f�ciles de escribir porque no es necesario escribir los 
controladores de bajo nivel. Tambi�n, ya que el desarrollo de AROS 
todav�a no es efectuado en s� mismo (no podemos compilar AROS desde 
dentro de AROS) eso acelera mucho la programaci�n ya que podemos 
ejecutar el ambiente de desarrollo y AROS uno al lado del otro sin
perder el tiempo en los arranques seguidos para probar el c�digo nuevo.


Nomenclatura
------------

Los diferentes puertos AROS se nombran de la forma <cpu>-<plataforma>, 
donde <cpu> es la arquitectura de CPU y <plataforma> es un nombre 
simb�lico para la plataforma. La plataforma de un puerto puede ser el 
hardware para un puerto nativo, por ejemplo, "pc" o "amiga", o un 
sistema operativo para los puertos alojados, como "linux" o "freebsd". 
En los casos que no es obvio que el tema es AROS es com�n poner el 
prefijo "AROS/" al nombre del puerto, resultado en por ej."AROS/i386-pc".


Portabilidad
------------

Los ejecutables de AROS para una CPU espec�fica son port�tiles a trav�s
de todos los puertos que usen la misma CPU, es decir, que los ejecutables 
compilados para "i386-pc" funcionar�n bien sobre "i386-linux" y 
"i386-freebsd".


Puertos existentes
==================

Abajo est� la lista de todos los puertos de AROS que est�n funcionando 
en orden y/o desarrollados activamente. No todos est�n disponibles para 
descargar, ya que podr�an no estar suficientemente completos o tener 
requerimientos de compilaci�n que no podemos siempre cumplir debido a 
los limitados recursos.


AROS/i386-pc
------------

:Flavour:    Nativo
:Status:     Funcionando, soporte incompleto de los controladores
:Manteined:  S�

AROS/i386-pc es el puerto nativo de AROS para las computadoras comunes 
IBM PC AT y compatibles que usen los procesadores de la familia x86. 
El nombre en verdad es un poco errado porque AROS/i386-pc necesita al 
menos una CPU de clase 486 debido al uso de algunas instrucciones que 
no est�n en el 386.

Este puerto funciona bastante bien, pero nada m�s tenemos soportados a 
los controladores m�s b�sicos. Una de las limitaciones m�s grandes es 
que ahora s�lo tenemos soporte para la aceleraci�n por hardware de las 
tarjetas de nVidia y de ATI. Los dem�s adaptadores gr�ficos deben ser 
usados con los controladores VGA (no acelerado) y VBE. Hay m�s 
controladores en camino, pero el desarrollo es bastante lento porque 
solamente tenemos 2,5 hackers de hardware. Este puerto est� disponible 
para bajar.



AROS/m68k-pp
------------

:Flavour:    Nativo 
:Status:     Funciona en parte (en un emulador), soporte incompleto de 
             los controladores
:Maintained: S�

AROS/m68k-pp es el puerto nativo de AROS para la l�nea Palm de 
computadoras de mano y compatibles ("pp" significa "palm pilot", que fue 
el nombre del primer dispositivo de esta l�nea). Esto significa que 
en el futuro podr�s ser capaz de llevar a AROS contigo en tu bolsillo...

Este puerto es actualmente muy crudo. En su mayor�a funciona (ejecut�ndose 
en un emulador todav�a ya que nadie quiere arriesgarse a inutilizar su caro 
hardware) pero a�n queda bastante por hacer. Hay un controlador 
gr�fico, pero ninguna entrada de datos. Este puerto no est� disponible 
para descargar en este momento.


AROS/i386-linux
---------------

:Flavour:    Alojado
:Status:     Funcionando
:Maintained: S�

AROS/i386-linux es el puerto alojado de AROS en el sistema opertivo Linux [#]_
ejecut�ndose en los procesadores de la familia x86.

�ste es el m�s completo de los puertos de AROS en caracter�sticas, 
puesto que la mayor�a de los desarrolladores usan Linux cuando 
desarrolla AROS, y hay bastante menos controladores que escribir. 
Este puerto est� disponible para descargar.


AROS/i386-freebsd
-----------------

:Flavour:    Alojado
:Status:     Funcionando
:Maintained: S� (5.x)

AROS/i386-freebsd es el puerto alojado de AROS en el sistema operativo 
FreeBSD ejecut�ndose en los procesadroes de la familia x86.

Este puerto est� relativamente completo porque comparte la mayor�a de su 
c�digo con el de AROS/i386-linux, pero ya que no hay tantos desarrolladores 
que usen FreeBSD es ###lagging un poco atr�s. Nosotros intentamos 
compilar AROS/i386-freebsd cuando hacemos las instant�neas, pero no 
siempre es posible, as� que podr�a ser que no siempre est� disponible 
para bajar.


AROS/ppc-linux
---------------

:Flavour:    Alojado
:Status:     Funcionando
:Maintained: S�

AROS/ppc-linux es el puerto alojado de AROS para el sistema operativo 
Linux ejecut�ndose en la familia de procesadores PPC.

Una versi�n precompilada se puede descargar de `Sourceforge`__.
El rebuilding requiere un gcc3.4.3 parchado. El archivo diff se puede 
hallar en contrib/gnu/gcc.

__ http://sourceforge.net/project/showfiles.php?group_id=43586&package_id=194077


Notas al pie
============

.. [#] S�, sabemos que Linux es realmente s�lo un n�cleo y un OS entero,
       pero es mucho m�s breve de escribir que "los sistemas operativos 
       basados en el n�cleo Linux, algunas de las herramientas comunes 
       GNU y el sistema de ventanas X". Esta optimizaci�n de tama�o por 
       supuesto que es negada al tener que escribir esta explicaci�n 
       para los lectores pedantes, ...

