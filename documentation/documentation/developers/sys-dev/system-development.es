==========================================
Manual para el Desarrollo del Sistema AROS
==========================================

:Authors:   Aaron Digulla, Bernardo Innocenti
:Copyright: Copyright � 2001, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $

.. Warning::

   �Este documento no est� terminado! Es muy probable que muchas
   partes est�n desactualizadas, contengan informaci�n incorrecta o
   simplemente falten. Si quieres ayudar a rectificar esto,
   por favor, cont�ctanos.

.. Contents::

--------------------------
Pol�tica de licenciamiento
--------------------------

Casi todo el c�digo escrito por el AROS Development Team est� licenciado con
la AROS Public License (APL), y es la elecci�n recomendada para todo el
nuevo c�digo escrito para el proyecto.

Sin embargo, nos damos cuenta que esto no siempre es posible; por ejemplo,
a menudo queremos usar las buenas bibliotecas y aplicaciones de terceros en vez 
de inventar la rueda otra vez por nosotros mismos. Por lo tanto se permite importar
c�digo ajeno en el dep�sito SVN que no est� licenciado con la APL, mientras
la licencia de ese c�digo satisfaga los siguientes requerimientos.


Requerimientos sobre el c�digo fuente del �rbol contrib
=======================================================

Para incluir c�digo fuente en el �rbol contrib, se deben cumplir los
siguientes requerimientos:

1. La licencia nos debiera permitir:

   a. Redistribuir los fuentes.
   b. Redistribuir los binarios.

   En el caso que sean necesarios cambios al c�digo fuente para poderlo
   compilar y hacerlo funcionar en AROS, entonces la licencia adem�s nos debiera
   permitir hacer las modificaciones y redistribuir los fuentes y binarios que
   contengan aquellas modificaciones.

2. La licencia debe estar expresada por escrito en un archivo llamado LEGAL
   ubicado en el directorio ra�z de los fuentes a los que se aplica.

   
Requerimientos en el c�digo fuente en el �rbol principal de AROS
================================================================

Para incluir c�digo fuente ajeno, que no est� licenciado con la APL en el
�rbol principal de AROS se deben cumplir los siguientes requerimientos:

1. Que el c�digo fuente se necesite para build alg�n componente o sea necesario
   para alg�n otro componente (que podr�a o no ser APL) que querramos que est�
   inclu�do en la distribuci�n base binaria de AROS.

2. Que la licencia deba ser de fuente abierta como se define en la
   Open Source Initiative (OSI), lo que significa que debe permitirnos:

   a. Hacer modificaciones.
   b. Redistribuir el fuente (posiblemente con modificaciones).
   c. Redistribuir los binarios (posiblemente basados en los fuentes modificados).

3. Que la licencia no tenga conflictos con la APL:
   
   a. Si se trata de un programa separado, casi toda licencia que cumple con
      (2) est� permitida.

   b. Si se trata de una biblioteca, la licencia debe permitir enlazar con
      programas y bibliotecas que usen una licencia diferente sin ning�n 
      problema. Esto significa que las bibliotecas que est�n cubiertas por
      la GPL (no la LGPL) no se permiten.

4. La licencia debe estar expresada por escrito en un archivo llamado LEGAL
   ubicado en el directorio ra�z de los fuentes a los que se aplica.
   

----------------------------
Convenciones de codificaci�n
----------------------------

Estilo general
==============

Este c�digo es usado por mucha gente y por lo tanto debieras tener algunas
cosas en mente cuando env�es c�digo fuente:

+ Conservar simple las cosas
+ Conservar limpio el c�digo
+ Siempre debes saber qu� haces
+ D� lo que est�s haciendo
+ Recuerda que el c�digo se escribe una vez pero se lee muchas otras y por bastantes personas


Los comentarios
===============

AROS usa parte de los comentarios en los fuentes para generar la documentaci�n.
Por lo tanto, es necesario mantener cierto formato para que las herramientas
puedan encontrar su informaci�n. Los otros comentarios son ignorados aunque
deber�an explicar lo que pensabas cuando escrib�as el c�digo. Si de verdad
no puedes pensar en una explicaci�n, entonces no escribas the code a 
second time like this::


    /* Esto suma 1 a t */
    t++;
    
Lo que pensamos de esto es::

    /* Ir al siguiente elemento */
    t++;


Los prototipos y las cabeceras de funci�n
=========================================

Toda funci�n en AROS debe tener un prototipo ANSI C completo. Los prototipos
deber�an estar reunidos en una cabecera por archivo si son necesarios para
unos pocos archivos (no se necesita recompilar el proyecto entero si cambias
una funci�n que se usa una sola vez), en una cabecera por directorio si es
muy usada en ese directorio, o en una cabecera por grupo l�gico (por ej.
una cabecera para todas las funciones en una biblioteca).

La cabecera de funci�n (es decir, el comentario que precede a la funci�n) debe
tener un formato especial porque los AutoDocs se generan de all�. Aqu� est�
un ejemplo (de <filename>AROS/exec/addhead.c</filename>)::

    /*****************************************************************************

        NAME */
    #include <exec/lists.h>
    #include <clib/exec_protos.h>

        AROS_LH2I(void, AddHead,

    /*  SYNOPSIS */
            AROS_LHA(struct List *, list, A0),
            AROS_LHA(struct Node *, node, A1),

    /*  LOCATION */
            struct ExecBase *, SysBase, 40, Exec)

    /*  FUNCTION
            Insert Node node as the first node of the list.

        INPUTS
            list - The list to insert the node into
            node - This node is to be inserted

        RESULT
            None.

        NOTES

        EXAMPLE
            struct List * list;
            struct Node * pred;

            // Insert Node at top
            AddHead (list, node);

        BUGS

        SEE ALSO
            NewList(), AddTail(), Insert(), Remove(), RemHead(), RemTail(),
            Enqueue()

        INTERNALS

    ******************************************************************************/
    {

Como ves, los comentarios se usan para mezclar el prototipo de funci�n y la
cabecera en uno.

NAME 
    Este campo contiene todos los prototipos necesarios para usar la funci�n
    desde el punto de vista del usuario, y el nombre de la funci�n en una
    macro `AROS_LH#?()` (Library Header, Cabecera de Biblioteca). Estas macros
    se usan para hacer que el mismo c�digo funcione en diferente hardware. El
    nombre depende de la cantidad de par�metros y si la funci�n necesita de la
    de la biblioteca base. `AddHead()` no, y por lo tanto se anexa una "I" al
    nombre de la macro. Si se necesita la biblioteca base (como lo hace `AddTask()`),
    entonces se omite la "I".

    Si la funci�n no es parte de una biblioteca compartidad y sus argumentos 
    deben ser pasados a ciertos registros (por ej. las callback hooks), debes 
    usar las macros `AROS_UFH#?()` (User Function Header, Cabecera de Funci�n del
    Usuario) en lugar de `AROS_LH#?()`. A�ade la cantidad de argumentos a esta
    macro. Dado que nunca tiene una base, el campo LOCATION se debe omitir
    y no se necesita agregar la "I" al nombre de la macro. Un ejemplo para una
    callback hook `foo()` ser�a::

        AROS_UFH3(ULONG, foo,
            AROS_UFHA(struct Hook, hook,  A0),
            AROS_UFHA(APTR,        obj,   A2),
            AROS_UFHA(APTR,        param, A1)
        )

    (Nota que los registros no necesitan tener un orden en particular).

    Si la funci�n no es parte de una biblioteca compartidad y sus argumentos no
    necesitatn estar en registros espec�ficos, no necesitas las macros `AROS_#?H#?()`::

        /*****************************************************************************

            NAME */
        #include <header.h>

	        int foo (

        /*  SYNOPSIS */
	        int a,
	        int b)

        /*  FUNCTION
	        blahblahblah.
	        ...

        *****************************************************************************/
        
SYNOPSIS 
    Este campo contiene todos los argumentos de la funci�n uno
    por uno en las macros `AROS_LHA()` (Library Header Argument, Argumento de
    la Cabecera de Biblioteca). Estas macros aseguran que el argumento respectivo
    es puesto en el registro correcto de la CPU cuando se invoca la funci�n
    (si es posible y es necesario). El primer argumento para la macro es el
    tipo del par�metro seguido del nombre del par�metro y el registro en el
    que el par�metro espera estar. Los nombres v�lidos para los registros son
    D0, D1, D2 hasta D7 y A0 hasta A6.

    Si la funci�n no es parte de una biblioteca pero los argumentos deben ser
    pasados a los registros, entonces usa las macros `AROS_UFHA()` (User 
    Function Header Argument, Argumento de la Cabecera de Funci�n del Usuario)
    que toma los mismos par�metros que las macros `AROS_LHA()`. No olvides
    cerrar los par�ntesis de la `AROS_UFC`.

    Si la funci�n no es parte de una biblioteca y los argumentos no necesitan
    ser pasados a los registros, no son necesarias las macros.

LOCATION
    Este campo solamente es necesario para las bibliotecas compartidas. Contiene
    los �ltimos cuatro par�metros de la macro `AROS_LH#?()` que son el tipo de
    la biblioteca, el nombre de la variable, en qu� biblioteca base se espera la
    funci�n, el desplazamiento de la funci�n en la tabla de salto (el primer
    vector tiene 1 y el primer vector que podr�a ser usado por una funci�n es 5)
    y el nombre de la biblioteca.

FUNCTION
    Este campo contiene una descripci�n de la funci�n.

INPUTS
    Este campo contiene una lista de todos los par�metros de la forma
    "nombre - descripci�n" o "nombre, nombre, nombre - descripci�n". La descripci�n
    deber�a decir qu� es el par�metro y qu� valores puede tener. There is 
    no point es explicar el par�metro dos veces, en FUNCTION y aqu�. Si la funci�n
    no tiene par�metros, pon "None." aqu�.

RESULT
    Lo que devuelve la funci�n. Esto incluye los valores devueltos y los 
    valores pasados en los argumentos de la funci�n. Si la funci�n puede fallar,
    deber�as explicar qu� regresa en caso de falla y por qu� podr�a fallar.

NOTES
    Las cosas importantes que el usuario debiera conocer o tener en cuenta.

EXAMPLE
    Este ejemplo deber�a contener un ejemplo peque�o o con todas las caracter�sticas.
    Una buena manera de presentar un ejemplo es escribir algo de c�digo que pruebe
    la funci�n, ponlo en `#ifdef TEST` en alguna parte del archivo y pon 
    "See below" aqu�. Si necesitas que haya comentarios en el c�digo, tienes dos maneras.
    Si solamente necesitas comentarios breves de un rengl�n, usa el estilo
    de C++ (``//``). Todo desde ``//`` hasta el final del rengl�n es el comentario.
    Si necesitas comentar m�s, entonces puedes terminar el comentario despu�s de
    `EXAMPLE` y usar `#ifdef EXAMPLE` para enmascarar el ejemplo::

            EXAMPLE */
        #ifdef EXAMPLE
	        struct List * list;
	        struct Node * pred;

	        /* Insert Node at top of the list */
	        AddHead (list, node);
        #endif

    No uses `#ifdef EXAMPLE` si tienes un ejemplo completo (es decir, uno que se
    pueda compilar sin errores).


BUGS
    Este campo contiene una lista de los errores conocidos.

SEE ALSO
    Este campo contiene una lista de las otras funciones y documentos que
    podr�an ser de inter�s. Esto incluye la funci�n que necesitas para inicializar,
    crear o destruir un objeto que necesite esta funci�n, las funciones 
    que hagan cosas similares u opuestas a las del objeto principal.

    Por ejemplo, `SetAttrs()` deber�a contener aqu� las funciones para crear, 
    destruir y manipular los objetos BOOPSI pero no las taglists.

INTERNALS
    Este campo deber�a contener la informaci�n para los otros desarrolladores que
    sea irrelevante para el usuario, por ejemplo una explicaci�n del algoritmo
    de la funci�n o sus dependencias.


Formateo
========

Aqu� est� un ejemplo de c�mo se formatea el c�digo de AROS::

    {
        /* a */
        struct RastPort * rp;
        int               a;

        /* b */
        rp = NULL;
        a  = 1;

        /* c */
        if (a == 1)
            printf ("Init worked\n");

        /* d */
        if
        (
            !(rp = Get_a_pointer_to_the_RastPort
                (
                    some
                    , long
                    , arguments
                )
            )
        ||
            a <= 0
        )
        {
            printf ("Something failed\n");
            return FAIL;
        }

        /* e */
        a = printf ("My RastPort is %p, a=%d\n"
            , rp
            , a
        );

        return OK;
    }


Se ve feo, �eh? :-) De acuerdo, aqu� vienen las reglas:

+ Si varios renglones tienen c�digo similar, pon las cosas similares
  una debajo de la otra (mira a y b);

+ Pon espacios entre los operandos y los operadores

+ Pon las aperturas y cierres de llaves ``{}``, corchetes ``[]`` y par�ntesis
  ``()`` alineadas (d) si hay mucho c�digo en el bloque que encierran (c).
  Los corchetes y los par�ntesis pueden estar en el mismo rengl�n si el
  c�digo entre ellos es peque�o (c)

+ La sangr�a debe ser de 4 espacios. Dos niveles de sangr�a pueden abreviarse
  con una tabulaci�n.

  Las razones para esto son:
  
  1. Mientras que algunos editores pueden usar tama�os arbitrarios para las
     tabulaciones, es un poco complicado indicarle a otro editor qu�
     tama�o de tabulaci�n se us� en el editor con que se escribi� el c�digo.
  2. La mayor�a del c�digo en AROS fue escrito de esta manera y tu c�digo
     deber�a verse como el resto.
  3. Puedes imprimir este c�digo en cualquier impresora sin la necesidad
     de herramientas especiales para "arreglar" las tabulaciones.
  4. La mayor�a de los editores tienen tabulaciones inteligentes que hacen
     exactamente esto. Si tu editor no lo hace, escribe un informe de error.

+ Si tienes una funci�n con muchos argumentos (d, e) deber�as poner los
  par�ntesis en renglones aparte y cada argumento en su propio rengl�n (d)
  o poner el primer argumento detr�s del par�ntesis de apertura (e) y
  los sucesivos argumentos en un rengl�n distinto con una coma delante.
  El par�ntesis de cierre debe estar en su propio rengl�n y alineado
  con el comienzo de la expresi�n (es decir, el a y no el par�ntesis de
  apertura o el `printf()`).

+ Usa un rengl�n vac�o para separar los bloques l�gicos. Los comentarios 
  largos deber�an tener un rengl�n vac�o antes y despu�s, los comentarios
  cortos deber�an suceder al c�digo que explican con un �nico rengl�n
  vac�o de separaci�n.


Escribir el c�digo para ROM
===========================

El c�digo de los m�dulos de AROS deber�a ser escrito de modo que se
ajuste para incorporarlo en una ROM, FlashRAM u otro tipo de memoria
de solo-lectura. Est�n previstas las siguientes reglas de estilo de 
codificaci�n para que eso sea posible. Por supuesto, que se aplican
a todos los m�dulos Kickstart y al c�digo que podr�a ser residente,
compartido o enlazado a otros m�dulos.

+ Los m�dulos ROM no deben tener las secciones .data y .bss.
  B�sicamente, necesitamos quitar todos los datos globales no constantes.
  El Amiga Kickstart aut�ntico prueba que es posible y f�cil lograr esto.

  Si encuentras una variable externa (est�tica o no) que sea 
  modificada por el c�digo, prueba a quitarla o moverla a la base de
  biblioteca/dispositivo (o en el nodo dispositivo de tu manejador o en los
  datos de usuario de tu clase).

+ Lo de arriba tambi�n se aplica a las bases de las bibliotecas. Si est�s
  escribiendo una biblioteca, pon las bases de las otras bibliotecas en
  la estructura base de tu propia bibliteca. Las clases BOOPSI pueden
  almacenar las bases de la biblioteca en sus datos privados de la clase.

+ Intenta establecer los atributos `static` y `const` para todos tu datos
  globales. Tambi�n puedes usar los tipos `CONST_STRPTR` y `CONST_APTR`
  definidos en <exec/types.h>. Usar `static const` permite que el 
  compilador mueva los datos al segmento ".text" (m�s conocido como c�digo).
  Si necesitas pasar estas variables globales a otra funci�n, prueba a 
  cambiar su prototipo para usar `const` tambi�n. F�jate que, del OS 3.5,
  Olaf Barthel ha cambiado para usar `const` en las cabeceras <clib/#?_protos.h>.

+ **NUNCA JAM�S** toques los b�feres pasados por el usuario como
  un par�metro "input". El concepto de los par�metros de entrada 
  est� impl�cito en la descripci�n de la funci�n. Por ejemplo,
  el nombre de archivo pasado a `Open()` claramente es una variable
  de entrada y `Open()` no debe mess con ella, incluso si va a 
  dejarla como estaba despu�s. Ten en cuenta, que el b�fer podr�a
  estar en una memoria de solo-lectura o compartida entre varias
  instancias de un programa residente o multihilo.

+ Intenta evitar las llamadas del OS anfitri�n como `malloc()` y
  `free()` si puedes usar `AllocMem()` y `FreeMem()`. Porque
  las macros de depuraci�n que revisan el puntero se basan en
  encontrar al puntero dentro de los bloques de memoria de Exec
  con `TypeOfMem()`.
  
-------
Porting
-------

Este archivo describe como pasar AROS a un nuevo tipo de hardware.

1. Selecciona un nombre identificatorio para tu CPU (por ej. i386, m68k,
   hppa, sparc) y a��dele "-emul" (por ej. i386-emul) si tu puerto
   se ejecutar� como un "sub-OS" o "-native" (por ej. m68k-native) si el
   puerto ser� un OS separado.

2. Selecciona un nombre identificatorio para tu sistema (por ej. sgi, linux, amiga, etc.).

3. Edita "configure" y make reconocer� tu tipo de hardware y acomodar� las
   numerosas variables que necesite tu sistema.

   KERNEL
   	El tipo de CPU que usas (mira 1.)
   
   ARCH
   	El nombre de tu sistema (mira 2.)
    
   SYS_CC
   	El nombre de tu compilador de C
    
   COMMON_CFLAGS
   	Las opciones que deber�as ser consideradas por cada invocaci�n al
	compilador de C (por ej. -g -Wall -O0 etc.)
   
   ILDFLAGS
   	Las banderas que debes darle al compilador cuando enlaces para
	evitar usar cualquier biblioteca est�ndar o m�dulos de inicio
	(para GCC las opciones son -nostartfiles -nostdlib -Xlinker -i).
	Esto se usa para crear los ejecutables de AROS. Estos ejecutables 
	no deben tener ning�n s�mbolo sin resolver y todas las referencias
	deben estar verificadas.
    
   RANLIB
   	contiene el nombre de tu programa ranlib. Si no tienes uno
	especifica "true" (o el nombre de cualquier otro comando del shell
	que sencillamente ignore todos los par�metros y no devuelva 
	ning�n c�digo de error).

4. Tipea "make". Abortar� porque no hay $(KERNEL) a�n, pero configurar�
   algunos archivos importantes y �rboles de directorio.

5. Haz una copia de i386-emul a $(KERNEL) y convierte todos fuentes en
   ensamblador de x86 a tu CPU.

6. Llena $(KERNEL)/. Se recomienda que hagas una copia de i386-emul, porque
   es la versi�n m�s al d�a del n�cleo.

7. Tipea "make machine". Compilar� un programa y lo ejecutar�. La salida
   se puede usar para modificar $(KERNEL)/machine.h.

8. Ejecuta "make machine.i" en $(KERNEL). Generar� el archivo "machine.i"
   que necesitar�s para compilar los archivos en ensamblador. "machine.i"
   contiene los valores de numerosas constantes del sistema (los
   desplazamientos de los vectores de funci�n, los desplazamientos de los
   campos de estructura y las banderas del sistema).

9. Edita todos los archivos #?.s en $(KERNEL) y genera el c�digo m�quina
   adecuado para tu CPU. Para compilar los archivos, tipea "make".

10. Ve al directorio principal y tipea "make". Si hay alg�n error, escr�belos,
    luego corr�gelos y sigue con el paso 10.

11. Ve a bin/$(ARCH)/AROS e inicia "arosshell". Ahora puedes escribir algunos
    comandos (por ej. "dir all", "list" o "demowin"). Si todo va bien, tienes
    una lista de los directorios y archivos con "dir all" y "demowin" abre
    una ventana con algunos gadgets y renderings con los que puedes jugar.
    Tipea "Esc" o aprieta en "Exit" para salir de la demo. Para detener el
    arosshell, debes apretar ^C (Ctrl-C) puesto que como un verdadero OS no
    hay manera de pararlo limpiamente.
