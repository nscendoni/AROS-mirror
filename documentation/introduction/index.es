
:Authors:   Aaron Digulla, Stefan Rieken, Matt Parsons, Adam Chodorowski 
:Copyright: Copyright � 1995-2009, The AROS Development Team
:Version:   $Revision: 31438 $
:Date:      $Date: 2009-06-19 17:02:24 +0200 (Fri, 19 Jun 2009) $
:Status:    Casi terminado, creo...


.. Include:: index-abstract.es


Metas
=====

La meta del proyecto AROS es crear un OS que:

1. Sea tan compatible como sea posible con AmigaOS 3.1.

2. Pueda ser llevado a diferentes tipos de arquitecturas de harware
   y procesadores, como x86, PowerPC, Alpha, Sparc, HPPA y dem�s.

3. Deber�a ser compatible a nivel de binarios en una Amiga y a nivel
   de fuentes en otro hardware.

4. Pueda ejecutarse como una versi�n aut�noma que arranque directamente 
   del disco duro y como una emulaci�n que abra una ventana en un OS 
   existente para desarrollar software y ejecutar aplicaciones del Amiga y 
   nativas al mismo tiempo.

5. Mejore la funcionalidad del AmigaOS.

Para lograr esta meta, usamos un n�mero de t�cnicas. Antes que nada, 
hacemos un uso intensivo de Internet. T� puedes participar en nuestro
proyecto incluso si s�lo puedes escribir una sola funci�n del OS. La 
versi�n m�s actual del c�digo fuente es accesible las 24 horas del d�a 
y los parches pueden mezclarse en �l en cualquier momento. Una peque�a 
base de datos con las tareas encargadas asegura que no haya duplicaci�n 
de trabajo.


Historia
========

Tiempo atr�s, en el a�o 1993, la situaci�n para la Amiga se ve�a algo
peor que lo usual y algunos fans de la Amiga se reunieron y discutieron qu�
se deber�a hacer para aumentar la aceptaci�n de nuestra amada m�quina. 
De inmediato se hizo evidente la principal raz�n de la p�rdida de �xito: 
su propagaci�n, o la falta de ella. La Amiga deber�a conseguir una base 
m�s amplia para hacerse m�s atractiva para que todos la usen y desarrollen 
para ella. Entonces se hicieron planes para alcanzar esta meta. Uno de 
los planes era reparar los errores del AmigaOS, otro fue hacerlo un 
moderno sistema operativo. As� naci� el proyecto AOS.

Pero, �qu� es exactamente un error? Y, �c�mo deber�an ser reparados? 
�Cu�les eran las caracter�sticas que un OS llamado *moderno* deber�a 
tener? �Y c�mo deber�an ser implementadas en el AmigaOS?

Dos a�os despu�s, la gente todav�a estaba argumentando sobre esto y ni
una l�nea de c�digo se hab�a escrito (al menos nadie hab�a visto tal 
c�digo). Las discusiones todav�a eran del tono en que alguien afirmaba 
que "deber�amos tener..." y otro que respond�a "lee los viejos mensajes" 
o "esto es imposible de hacer, porque..." a lo que le segu�a un "t� est�s
equivocado porque..." y as� en adelante.


En el invierno (boreal) de 1995, Aaron Digulla se hart� de esta 
situaci�n y puso un RFC (pedido de comentarios) en la lista de correo de 
AOS en el que preguntaba cu�l podr�a ser un terreno m�nimo com�n. Se 
dieron varias opciones y la conclusi�n fue que a casi todos les gustar�a 
ver un OS abierto que sea compatible con el AmigaOS 3.1 (Kickstart 40.68) 
sobre el que se pudieran basar las discusiones posteriores para ver qu� 
es posible y qu� no.

As� comenz� el trabajo y naci� AROS.

