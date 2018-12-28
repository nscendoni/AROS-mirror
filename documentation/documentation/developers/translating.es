==========
Traducci�n
==========

:Authors:   William Ouwehand, Keen
:Copyright: Copyright � 1995-2007, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Work in progress.

.. Warning:: 
    
    Casi terminado


.. Contents::


Introducci�n
------------

Traducir el OS y el sitio web ayuda a que AROS llegue a m�s personas internacionalmente,
y a hacer el OS m�s f�cil de usar. Hacer estimaciones es imposible, pero nadie
puede negar que hay una base potencialmente grande de usuarios que son incapaces de leer,
hablar o escribir en ingl�s. Alcanzar a estas personas pueda *posiblemente* ayudar a 
tener m�s usuarios y desarrolladores.
Para este prop�sito a�n estamos buscando nuevos traductores o personas a las que les 
gustar�a ayudar con los esfuerzos actuales en esto.

Hasta el momento, AROS solamente ha sido traducido a unos pocas lenguas, y a menudo
parcialmente. Los pocos traductores disponibles y la cantidad de trabajo son una de las 
causas de esto. Tambi�n, sucede que la mayor�a de los traductores y escritores son los 
desarrolladores (principales); absorber sus tareas aqu� (incluso parcialmente) puede
ayudarles a maximizar sus esfuerzos en la codificaci�n o escritura de nueva documentaci�n.
Entonces si est�s interesado en ayudarnos, por favor `cont�ctanos`_. Incluso el m�nimo esfuerzo
puede ayudarnos enormemente.


D�nde empezar
-------------
Primero, por favor `cont�ctanos`_ para verificar si puedes contribuir (s�lo para estar en el
lado seguro).

Traducir es tan b�sico como implica. Todo lo que necesitas para empezar la traducci�n
de AROS es un editor de texto adecuado, acceder a las `SVN sources` de AROS y un
conocimiento de tu lengua y gram�tica. Informaci�n sobre las dos primeras se pueden encontrar
aqu� en la `p�gina Trabajando con SVN`_, la �ltima es para t� por supuesto. Advierte que no
necesitas incluso de AROS para trabajar en el sitio o el OS - tambi�n Linux, Windows o
OS X lo har�n.

El trabajo de traducci�n mismo se puede dividir en el sitio web (noticias/documentaci�n) y la
localizaci�n del sistema operativo AR(OS). El sitio web tiene una prioridad mayor ya que
es la primera cosa que los nuevos usuarios descubren, y porque contiene documentaci�n �til
e importante para los usuarios. la localizaci�n del OS no es menos importante, pero siempre
ocurre en una fecha posterior. A la par, la traducci�n m�s b�sica del sitio involucra s�lo
10 a 15 p�ginas no muy largas, haciendo que tal cosa no sea un gran trabajo de cualquier 
modo.


Traducir el sitio web
=====================

El sitio web es la presencia oficial online de AROS. Mantiene la informaci�n
general sobre AROS, las noticias, las descargas (del OS) y las gu�as del usuario
y del desarrollador. Juega un papel importante en informar a la gente sobre AROS,
y en servir como la gu�a de referencia para usuarios y desarrolladores. De las
dos �ltimas, las gu�as del usuario son lo m�s importante para ser traducido.

El sitio mismo es bastante extenso, aproximadamente m�s de 100 p�ginas largas. Aunque
es f�cil, no todo esto necesita ser traducido. Algunas partes son menos importantes,
otras no est�n terminadas y las restantes est�n bastante anticuadas. As� que para
tu propia facilidad, ponte por l�mite las primeras p�ginas ('el nivel 1'). Eso
significa sobre todo los documentos del usuario y las otras p�ginas principales
del sitio.

De todo el contenido, la secci�n del desarrollador es la menos importante. Generalmente
los desarrolladores tienden a hablar bien en ingl�s, haciendo que no sea valioso
el esfuerzo de traducirla; los usuarios requerir�n m�s atenci�n en general. La
excepci�n a la regla son las p�ginas 'working with SVN' y 'contribute' que pueden
resultar ser �tiles cuando t� reclutes otras personas en tu pa�s.


Procedimiento
~~~~~~~~~~~~~
El sitio web de AROS se compila de archivos de solo-texto, almacenados en un
archivo online de SVN. �stos son m�s tarde puestos en una plantilla, creando el
sitio web de AROS que conoces.

Para resumir, se recomienda mucho que t�:
+ hagas conocer tus intenciones a la LC (lista de correo) del desarrollador y veas si tus servicios son necesarios (para estar en el lado seguro)
+ leas entera esta p�gina
+ leas la `p�gina Trabajando con SVN`_
+ solicites acceso a SVN
+ te anotes en las LC del desarrollador y del sitio web.

*SVN*

Si no est�s familiarizado con SVN, lee sobre eso en la `p�gina Trabajando con SVN`_ 
como ya se dijo. En pocas palabras, SVN funciona como un tipo de FTP que se
enfoca solamente en los archivos. Sin embargo, en vez de mover los archivos de
a uno como lo hace FTP, mantienes una completa (y sincronizada) copia de los
fuentes en tu disco duro. Despu�s trabajas offline desconectado en estos
archivos, y cuando lo desees, sincronizas tus cambios con el dep�sito principal
en el servidor.
Los archivos fuentes con los que trabajar�s son archivos de texto plano 
(no HTML). 
El sofisticado aspecto del sitio web de AROS, junto con el men�, se agrega 
en un proceso separado en el servidor que transforma esto archivos de texto en 
un completo sitio HTML. Esto ser� tratado m�s tarde con alguna extensi�n.

Se recomienda mucho que esperes hasta que consigas acceso a SVN antes de empezar. Eso hace m�s f�cil
enviar y cambiar tus archivos traducidos m�s tarde. Sin embargo, el problema puede ser que pase
largo tiempo hasta que recibas tu verdadero acceso a SVN - a veces incluso varias semanas despu�s de
tu pedido inicial. Puede ser una prueba de paciencia, deber�as estar realmente entusiasmado...
afortunadamente para ti, puedes hacer un inicio descargando una copia de los fuentes
del sitio web desde el sitio web de AROS. Esto es simplemente una copia del dep�sito SVN
sitio web mencionado. Al lado, tambi�n es una gran manera para familiarizarte con el modo
con que el contenido es manejado y el archive est� estructurado. El �nico inconveniente
con este modo es que m�s tarde tendr�s que copiar a mano tus archivos para tu verdadero
revisi�n de SVN. Hay un escenario posible donde traduces desde el archive y 
env�as los archivos a la LC, pero el trabajo extra que esto lleva consigo no es
recomendado. No obstante, continuemos.

Cuando tengas acceso a SVN, ejecuta una revisi�n de los fuentes del sitio web 
con SVN. Esto descargar� el dep�sito del momento a tu HD, conteniendo todos los
archivos del sitio web.
Las ubicaciones son::

  https://svn.aros.org/svn/aros/trunk/documentation/

Cuando recorras la copia local (o la descargada) notar�s las extensiones para los 
diferentes lenguajes. Cada extensi�n corresponde a un lenguaje espec�fico, y como
puedes adivinar lo mismo ser� necesario para tus traducciones. Ahora simplemente escoge
una p�gina existente (en ingl�s de preferencia), duplica este archivo en alg�n lugar
mientras agregas la extensi�n c orrecta, por ej. contribute.en (ingl�s) -> contribute.nl
(holand�s). Entonces puedes traducir los contenidos de la p�gina.

*La codificaci�n de caracteres*

La codificaci�n de caracteres de tus archivos a traducir necesitan atenci�n
extra. La diferencia de idiomas y los s�mbolos que usan requiere que
los archivos de texto usen una codificaci�n espec�fica capaz de mostrar
los s�mbolos correctos. Si debes traducir para un idioma occidental 
gen�rico (por ej. ingl�s, alem�n) tienes poco de qu� preocuparte - s�lo
aseg�rate de configurar tu editor de texto para guardar los archivos
con la codificaci�n ISO-8859-1 o ISO Latin-1.
Cuando tu idioma use s�mbolos m�s 'ex�ticos' que las normas occidentales
(por ej. ruso o griego), requerir�s ajustes diferentes. Especialmente 
cuando configures la traducci�n de un nuevo sitio web se recomienda 
que contactes a la lista Dev ML para recibir consejo.
Tambi�n consulta la `p�gina de documentaci�n`_ para informaci�n adicional.

*Env�o*

Cuando est� hecho, env�a tus archivos al dep�sito para que sean
procesados. Por favor usa mensajes de rgistro t�picos como "traducciones
al alem�n" o "actualizaci�n de la p�gina X del alem�n" y prueba a juntar
m�s de un archivo en un env�o (cuando est�n relacionados). Los cambios
clave pueden enviarse mejor por separado: si se comete un error, el cambio
puede ser f�cilmente deshecho por los administradores sin desperdiciar
tu otro trabajo para ese particular env�o (y ent�rate, que puesto que
el sistema sincroniza todas las copias, �incluso puedes perder tu trabajo
local!).

�Puedes ver los archivos de texto plano que en el servidor crean el sitio web?
Son guiones, que toman los textos fuente y los convierten en p�ginas HTML/PHP
adecuadas para navegar. Este proceso se llama 'building', y puede tambi�n
hacerse en tu m�quina para prop�sitos de prueba - m�s sobre eso despu�s. El
sitio web ejecuta las builds una vez cada unas pocas horas (o d�as), 
despu�s de lo cual tus paginas estar�n listas para navegarse en el sitio web.

La excepci�n a esta regla es cuando una nueva secci�n de lenguaje entera se agrega: son
necesarios m�s cambios en la configuraci�n del proceso de build. 
Dependiendo de tu habilidad, puede ser mejor que contactes a la LC de Desarrollo
para instrucciones.

.. Note:: 
    
	Los archivos en ingl�s deber�an ser considerados la base 'por omisi�n' para todas
	las traduccciones, ya que por lo general tiene los textos m�s al d�a. Para todas las 
	p�ginas que todav�a no has traducido, el sitio mostrar� la versi�n en ingl�s,
	incluso cuando navegues con tu lenguaje espec�fico.

Revisa tu trabajo
~~~~~~~~~~~~~~~~~

Se aconseja que revises tus textos respecto a dos asuntos: ortograf�a y errores de
las marcas.

Los correctores ortogr�ficos deber�an considerarse obligatorios, la opci�n
que vuelvas a leer tu trabajo puede ayudar. La combinaci�on deber�a
atrapar el 99% de los errores ortogr�ficos y  gramaticales, e involucra
poco trabajo. No te quejes, pero un uso correcto del lenguaje hace
a la presentaci�n del sitio.

Los errores de marcado son otra historia. Estos errores se cometen en la etiquetas
usadas en el documento fuente. Las etiquetas son s�mbolo/c�digos especiales, como
enlaces o renglones de '===' que indican que el rengl�n previo es una cabecera.
Cuando se presenten, estos errores rompen el proceso de 'building' para esa
p�gina. A pesar de estos errores, la p�gina todav�a se generar� y puesta online
-pero- con mensajes de error molestos y partes rotas. No es agradable, pero los
problemas est�n limitados cuando cometes un error ;-)
El proceso de building informa todos los errores autom�ticamente a la LC del 
sitio web. Tambi�n se muestra informaci�n extra haciendo que el arreglo sea m�s
f�cil. (Por lo tanto deber�as siempre estar anotado en la LC).
Tambi�n puedes esperar que uno de los otros desarrolladores corrigan el error,
pero eso genera trabajo extra para los otros, y t� no aprendes de tus errores.
Sabe que es bastante usual cometer errores en el primer trabajo, mientras 
que la mayor�a de los posteriores son errores casuales.

*Compilar el sitio de modo local*

Estar�s de acuerdo que este proceso de solo enviar al servidor y esperar es un modo de
'volar a ciegas'. �C�mo puedes evitar (razonablemente) que las p�ginas defectuosas 
terminen en el sitio web? Compilar el sitio web por t� mismo tambi�n, igual
que se hace en el servidor. Esto requiere que instales algo de software extra
(Python), pero despu�s puedes revisar tu trabajo con el mismo gui�n que
crea los archivos HTML del sitio web en el servidor; no es magia =).
Trabajas de un modo m�s eficiente de esta manera, mantienes el sitio ordenado
y ahorras el tiempo de los otros desarrolladores.
Para intrucciones sobre c�mo compilar localmente y las herramientas necesarias, revisa
la `p�gina de documentaci�n`_. 

Como con los arreglos, las nuevas p�ginas deber�an mostrarse en unas pocas horas
(a un m�ximo de un d�a) en el sitio web.

Localizar AROS o las aplicaciones
=================================
Localizar el OS y sus aplicaciones agrega mucho de la usabilidad y 
experiencia a los usuarios no angloparlantes, quiz�s incluso hace que AROS
pueda ser usado por ellos en primer lugar. El procedimiento para localizar el OS es b�sicamente
el mismo que para el sitio, pero difiere en sus detalles.
Como con el sitio web incluso una traducci�n b�sica basta, limit�ndose al
Workbench y sus aplicaciones/utilidades. Esto hace un buen comienzo/base para 
la adicional localizaci�n. Siempre puedes progresar a las aplicaciones
extra del OS y los archivos contribuidos.

Procedimiento
~~~~~~~~~~~~~ 

AROS, como el AmigaOS, ofrece la opci�n de almacenar las cadenas de texto
de una aplicaci�n en un archivo separado, permitiendo una f�cil y eficiente
localizaci�n. Los archivos de cat�logo para AROS est�n ubicados en su mayor�a
dentro del dep�sito de c�digo principal, que es diferente del dep�sito del 
sitio web. En este caso tu puedes ya sea ejecutar una completa revisi�n de SVN, o
navegar el dep�sito SVN con tu navegador y descargar los archivos especificados.
Necesitar�s acceso a SVN para esto, a diferencia de las fuentes del sitio web
los fuentes completos del OS no est�n disponibles por separado.

El dep�sito del OS se puede acceder por un navegador usando este enlace
https://svn.arog.org:8080/svn/aros/trunk/AROS lo que te permite que
tengas uno o dos archivos de manera eficiente.

  https://svn.aros.org:8080/svn/aros/trunk/AROS

Nota que la revisi�n de SVN es bastante grande (200MB) y por esto toma alg�n tiempo 
completarlo. No te intimides por el tama�o del dep�sito: solamente necesitas
enfocarte en una fraccci�n del estos archivos, por suerte. Ahora puedes empezar
el trabajo. Si est�s confundido, no dudes en pedir ayuda en AROS-exec o en la LC.

*Definiciones del idioma y de las fuentes*

Primero, debes buscar tu pa�s en Locale/Countries y el archivo de
definici�n del idioma en Locale/Languages. La mayor�a de los idiomas
ya fueron agregados por si acaso. Si no puedes encontrar algo como <tu_idioma>.c
ah�, entonces debes crearlo. Intenta evitar los caracteres especiales en el
nombre del archivo, esto puede ayudar a evitar problemas con algunos
programas no-utf (recuerda, AROS pretende ser port�til). Puedes buscar el 
m�s completo lang.c y copiarlo a tu_idioma.c. Entonces, abre el archivo
en tu editor de texto y traduce todas las cadenas de texto que necesites.
Esto incluye las unidades usuales como d�as, meses, moneda, etc. Puedes
buscar tablas con descripciones de los caracteres usados en estos archivos
(tablas de collation), o puedes saltarlas al empezar. Despu�s de compilar,
tu locale debe aparecer en la lista de locales del Pref Locale.

�Qu� sigue? Si tu lenguaje usa fuentes no-ISO, las necesitas.
Busca en Internet las fuentes bitmap de AmigaOS o True Type de
fuente abierta, que pueden ser inclu�das al sistema. P�nlas en /Fonts
o /Fonst/TrueType y arregla el mmakefile (�se **cuidadoso** con los
mmakefiles!)

*Crear los archivos CT*

Ahora viene el verdadero trabajo de traducci�n. Ent�rate que la localizaci�n en 
AROS es similar al del AmigaOS. Esto significa que puedes encontrar algunos
archivos .cd y .ct junto con el c�digo (por lo general en un caj�n Catalog).
Los archivos <nombre>.cd contienen las definiciones de cat�logo y no deber�an
ser tocados a menos que sepas que cambiaste el programa mismo.
Los archivos .CT contienen todas las cadenas traducidas, y son el objeto de 
tu trabajo. Navega el �rbol SVN por estos archivos y trad�celos: encuentra
el archivo <nombre>.ct m�s reciente (mira laversi�n y la fecha en la 
cabecera), copia tu <tu_idioma>.ct (es mucho m�s f�cil que traducirlos del
archivo <lang>.cd) y ed�talo. Intenta poner las palabras en los lugares correctos,
para lo que necesitar�s revisar d�nde se usan.

Para ayudarte con este trabajo de copia y cambio de nombre, hay una aplicaci�n
CLI/Terminal llamada Flexcat. Puede generar los archivos .CT para tu idioma 
de modo autom�tico de los archivos .CD. Es �til que tambi�n comente el texto
original (para inspecci�n) y que cree renglones vac�os para que llenes con tu traducci�n. 
Tambi�n ofrece las opciones de compilaci�n necesarias para probar los
cat�logos, que se trata m�s adelante. Flexcat se puede encontrar en AROSTrunk/Tools
pero necesita que se lo compile para AmigaOS o Linux. Puedes tambi�n revisar
Aminet o preguntar en la LC del Desarrollador.

*Usar Flexcat*

Antes de generar los archivos CT, pon a Flexcat en la misma ubicaci�n
que tus archivos CD (o en AROS/AmigaOS, p�nlo en el caj�n "C"). Ahora navega
la ubicaci�n con el Shell/Terminal y haz que Flexcat cree un archivo .CT
de su original archivo .CD usando el siguiente comando::

	FlexCat <application>.cd NEWCTFILE=deutsch.ct

Esto te dar� un archivo deustch.ct listo para traducir. A menudo no se agrega
la informaci�n sobre la versi�n; c�piala a mano del archivo original.
Traduce sus contenidos y cuando est� listo, env�a el archivo al dep�sito.

Un nota especial sobre actualizar los archivos de cat�logo m�s viejos - se
puede hacer efici�ntemente con Flexcat usando el siguiente comando::

	FlexCat <application>.cd deutsch.ct NEWCTFILE=deutsch.ct
	
Esto conservar� las cadenas viejas e insertar� nuevas donde las encuentre. La
documentaci�n de Flexcat tiene informaci�n adicional.

Revisa tu trabajo
~~~~~~~~~~~~~~~~~
De nuevo, ejecuta las correcciones ortogr�ficas y relecturas de los textos como
ya se mencion�. La prueba es posible de varias maneras: (1) env�alos al 
servidor SVN y espera la siguiente nightly build. O (2), que es la m�s inmediata,
compila los locales por t� mismo usando Flexcat, luego c�pialos al caj�n
Locale de AROS y rev�salos con las aplicaciones interesadas.
La compilaci�on de los archivos cat�logo 'finales' con Flexcat se hace
con la siguiente sentencia::

	Flexcat <application>.cd <yourlanguage>.ct CATALOG <File>.catalog

Advierte que <tu_idioma> no siempre tiene su equivalente en ingl�s; verif�calo 
con los locales existentes. Adem�s de verificar el correcto uso textual tambi�n
se recomienda probar la legibilidad de las traducciones en tama�os de pantalla
m�s peque�os.

Mantenimiento
-------------
Como con la mayor�a de las cosas, la informaci�n tiende a perder actualidad o se 
actualiza con frecuencia, lo que obliga a las subsecuentes sincronizaciones de 
los documentos traducidos. No es un trabajo recompensador (excepto del punto de 
vista de los usuarios finales), pero necesario. As� que es tuya la responsabilidad
por mantenerlos actualizados.

El seguimiento de los cambios se puede hacer con los registros de cambios de SVN,
disponibles del cliente de SVN. Esta lista muestra *todos* los cambios hechos
al dep�sito. Juzga de los mensajes de registro y de los archivos modificados 
si el cambio es relevante.
Hacer despu�s la comparaci�n y sincronizaci�n de los documentos puede ser 
tediosa. Algunos editores de texto ofrecen la opci�n de desplazamiento sincronizado
en la ventana, que puede ayudar algo cuando se comparan dos p�ginas. 
FIXME: �hay una manera m�s f�cil con SVN?

Cuando actualices los cat�logos del OS, se sigue lo mismo respecto a los
registros de cambios de SVN, excepto que ahora tienes a Flexcat, que probar�
ser una herramienta indispensable.

.. _`cont�ctanos`: http://aros.sourceforge.net/contact.php#mailing-lists
.. _`p�gina Trabajando con SVN`: svn
.. _`p�gina de documentaci�n`: documenting
