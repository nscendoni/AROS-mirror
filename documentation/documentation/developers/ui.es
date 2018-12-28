========================================
Gu�a de Estilo de la Interfaz de Usuario
========================================

:Authors:   Adam Chodorowski
:Copyright: Copyright � 2003, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $

.. FIXME: Introduction here...

.. Warning::

   �Este documento no est� terminado! Si quieres ayudar a rectificar esto,
   por favor ponte en contacto con nosotros.

.. Contents::


------------
Las ventanas
------------

Preferencias
============

Las ventanas de preferencias son similares en apariencia a la ventanas
de di�logo, en que tienen una fila de botones a lo ancho del fondo y 
ning�n gadget de cierre en la barra de t�tulo.

.. Figure:: ui/images/windows-prefs-titlebar.png

   Ejemplo de la barra de t�tulo de una ventana de preferencias. Note la
   ausencia del gadget de cierre.

.. Topic:: Justificaci�n

   No hay un gadget de cierre porque su significado ser�a ambiguo. En
   otras palabras, no estar�a claro para el usuario qu� efecto lateral
   es exactamente cerrar la ventana. �Guarda las preferencias o abandona todos los
   cambios?
 
El siguiente conjunto de botones siempre est� presente, ubicados de modo
horizontal en la ventana abajo (en este orden, de izquierda a derecha):

    Test (Probar)
        Aplica las configuraciones en la ventana para que tengan 
        efecto inmediatamente. No cierra la ventana.
        
    Revert (Revertir)
        Restaura las configuraciones en la ventana al estado que ten�an
        cuando se abri� la ventana, y lo hace inmediatamente. No cierra 
        la ventana.
        
    Save (Guardar)
        Aplica las configuraciones en la ventana inmediatamente y
        las guarda de modo permanente [#]_. Cierra la ventana. Si no es
        posible guardar definitivamente las configuraciones (por ej. si
        el disco donde deber�an guardarse es de solo-lectura) el bot�n
        est� fantasmal.
        
    Use (Usar)
        Aplica las configuraciones en la ventana inmediatamente y 
        las guarda de modo temporal (solamente para esta sesi�n) [#]_.
        Cierra la ventana.
        
    Cancel (Cancelar)
        Restaura las configuraciones en la ventana al estado que ten�an
        cuando se abri� la ventana y de inmediato. Cierra la ventana.

.. Topic:: Disposici�n

   Los botones est�n divididos en dos grupos, con Test y Revert en uno y
   Save, Use y Cancel en el otro, el primer grupo alineado a la izquierda,
   y el segundo alineado a la derecha. Hay un espacio para separarlos
   visualmente [#]_. Todos los botones tienen el mismo ancho, que deber�a
   ser tan peque�o como sea posible (cuando la ventana se agrande, solamente
   deber�a ensancharse el espacio entre los dos grupos y no los botones).
        
.. Figure:: ui/images/windows-prefs-buttons.png

   Ejemplo de la fila de botones en una ventana de preferencias.

.. [#] Guarda ambos a ``ENVARC:`` y ``ENV:``.
.. [#] Guarda solamente a ``ENV:``.
.. [#] F�jese que los botones del grupo izquierdo no cierran la ventana,
       mientras que los del grupo derecho s� lo hacen. 
