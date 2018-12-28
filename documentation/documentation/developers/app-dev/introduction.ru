==========================================
����������� �� ���������� ���������� AROS 
==========================================

:������:    Staf Verhaegen, Sebastian Rittau, Stefan Rieken, Matt Parsons,
            Adam Chodorowski, Fabio Alemagna, Matthias Rustler
:Copyright: Copyright (C) 1995-2006, The AROS Development Team
:������:    $Revision: 45870 $
:����:      $Date: 2012-10-07 19:53:43 +0200 (Sun, 07 Oct 2012) $
:������:    �� ���������; � �������� ����������� (������� ������ ����).
:�������:   ���������� ������ �����. �������� � ���������. ���������...
:��������:
    AROS - The AROS Research Operating System ������ ����� ����� ������������
    API ������������ ������� AmigaOS �� ������ ���������� ���������. ����
    �������� ������������ ����� �������� � ���������������� ��� AROS
    ����������� ������� ������ AROS � ��������� � API.
    
`Index <index>`__

.. ��������������::

   ���� �������� �� �������! ������ ��������, ��� ������ ����� ��������,
   �������� ������������ ���������� ��� ��������� �����������. ����
   �� ������ ��������� ��, ���������� �������� ���.

.. ����������::


--------
��������
--------

���������� �������� ��� ��������� AROS
======================================

� ���� ����� �������������� � ���, ��� ������������� ���������, ������� ����� ��������
� AROS, � ����� �� ������� � ���, ��� �������������� �� �� ���������� �����������
�������� �� ����, �� ������� �������� AROS. ��������������, ��� �� ������ ����
�� ������� �������� � ����� C � ����� �������� �������� ���������������� ���
`����������`.

��������� "Hello, world!"
-------------------------

���� ������� ������ ���������, ��������� �� ����� ��������� "Hello, world!" -
�� ��������������� �������� �������� �� ��� �� ������� �����. ����
`helloworld.c` �������� ��������� ����������� ���::

  #include <stdio.h>

  int main(void)
  {
    puts("Hello World");      
    return 0;
  }


�������������� � ������ ���������� AROS ��� ������ ������� ������
-----------------------------------------------------------------

���� �� ������ ���� ����������� ����� ������ ���������� AROS � ������������
AROS � ���, �� �� ������ ��������������� �������� ������ AROS ���
�������������� �������� ��� AROS. ��� �������� ���� ���������� ������
������������ ���� ���-������ � ������ AROS. ���������� 'local' � ��������
���������� ���������� AROS ����� �������������� ��� ���������� ����. �������
������� �������� � ����� �������������, ����������� ��� ������ �� ���������� � 
����� ���������� ���������� AROS::

  %mkdir local/helloworld

��������� � �� ���� helloworld.c � �������������� ���� � ������������ �� 
������ �� ����� `mmakefile.src`, ���������� ���������::

  include $(TOP)/config/make.cfg
  
  %build_prog mmake=local-helloworld files=helloworld progname=HelloWorld

������, �������� � ����� ���������� ���������� AROS, �� ������ �������
��������� HelloWorld ��� ������ ��������� �������::

  %make local-helloworld

������ �� ������ � ������ �������� ������ AROS ���������������� ���������
`local/helloworld/HelloWorld`.

������� ������ AROS ������������� ��� ��������� ����� ����� ��� ������
���������� � �������������� �������������. �� ���� �������� �������������� �
`��������� �����`__.

__ buildsystem


������������� � Linux ��� ������ GCC
------------------------------------

��� AROS/hosted �� ����������� ������������������ ������ ����������� Linux GCC.
���� �������� ������������ �� ���� ����������� �� ������� ����������������
������ AROS (i386-linux-system) ��� �� ������������ ��������� ��������������:

+ i386-linux-system

  �������� ����� `i386-all-sdk`. ���������� ���, ��������� � ���������
  ���������� � �� ����� ����������������� root ��������� ����������� ��� ������
  (��������, ``sudo AROS-SDK-Install``). ������ ������ ��������� ��������, ��
  ������ ����������� �� ����������, ������������� �� ���������. ����� ����
  �������� ����. ��� ��� ������� ������� �� ��������� ��������, ������� ��
  �����������. �������� �� ����������� Bash � ��������� ���� � ��� �������� �� 
  ���������. ����� �������� ���� /home/*user*/.bashrc � �������� ������ 
  ``PATH=/usr/local/aros-sdk/bin:"${PATH}"`` � ����� �����. ��������� �
  ������������� bash. ������� ``i386-aros-gcc -v`` ��� ������������.
  
+ �������������� ����������������

  ���������� AROS ����� ����� ���� `AROS/bin/linux-i386/tools`. �������� ����
  ���� ��� �������� ����. ��� ����������� `i386-linux-aros-gcc`.
  
�� ������ c������������� ��������� ��� ������ ��������� ������� ��������
Linux::

  % i386-linux-aros-gcc -o -heloworld helloworld.c

�� ������ �������������� ����������� � ���������� ����������� AROS: 
AROS-������ �������� ld, ranlib, ���������� ��������� Flexcat � �.�.

.. ����������:: ���� �� ����������� i386-linux-aros-strip, �� ��� ���� ��������
   ��������� `--strip-unneeded --remove-section .comment`. ����� strip-������
   ����� ��������� ����������� ���������.
  
�������������� ��� native-i386
------------------------------

�� ������ ������� ������ GCC, ������� �������� ��������������� � AROS, �
`SourceForge
<http://sourceforge.net/project/showfiles.php?group_id=43586&package_id=127743>`_
. ��� ����� �� ������� ���� binutils � core. ����� ��� ����������� AROS SDK.
���������� ��� � �� �� ����� (��������, sys:ADE). ���������� �������� �
���������� �� SDK � sys:ADE. 

����� ����������� ��������� �������::

    path sys:ade/bin add
    assign Development: sys:ade

    
�������
=========

����� ���������
---------------

AROS ���������������� � �������������� ������� ��������� (include). ���
��������� � `sys:Development/include`. ������������� `proto` �������� �����
��������� � ����������� ������� ��� ��������� ������������ ���������. �
`libraries` ������������� ����� ���������� �� ����������� � �������������.
��������� �� ������� ���������, ��������, `Intuition` ����� ���� ����������� 
���������� � �����������.

��������� ������������ ���������� AROS
--------------------------------------

��������� ������������ ���������� �������� ��� ������, ��������� ������� AROS
��������. ������ ���������� ������������ �� ���� ����� �������, �������
������ ��������� ����. ������ ������� �� ������� ����������� ���������� � ����
����������. ��������, ��� �������� ������� ���������� ������� ��������� �
���������� `exec.library`.

���������� ������ ��������� � ���������� `LIBS:`, �� ����� ��������� � � ������
������. ��������� �������� ������ ���������� �������� �� � ��������� ������, � 
�������� � ���� ������������ �������. �������, ��� ����� ���������� ���� ����� 
����������� � ������ ������� �������, ������� �� ���� ������� ������������ ��
������������� ���������, ���������� ������ ����.

����� ��������� ��������� AROS
''''''''''''''''''''''''''''''

���� ������� ������ ��������� ������ ��������� � �� �������. ��� �����
���������� ��, ��� �������� � ��� �����, ��� ��� ��� �������� ���������������
�����.

+ `exec.library` - �������� ������ ����������. ��� ���� ��������������� �� 
   ������ ����� �������� ���������� ������������ �������: ����������
   `��������` (�.�. �����������), `�������`, `������������` � ������� �������
   ������� ������.

+ `utility.library` ��������� ����� ������ ��������� ��� ��������� �
   �����������: `taglist-�`, ������� ��������������� ����� � ���� ����� �
   `hook-�`. �������� �� �����, ������ ���������� �������� �������������
   ��������� ��������� �������.
   
+ `dos.library` �������� �� ��������� � �������, �������� � ������� � ��������� 
   �������� ������� �����-������. ��� ���� ���������� AROS �� ����� ��
   ����������� �������� � �������.
   
+ `intuition.library` ��������� `������������ ������������ ������������ (GUI)`.
   ��� ������ ���� ���������� �� ������ ��������� `����` � `gadgets` �,
   ��������������, ��������� ���. ���� � ������ ����������, ������� ��������
   ������ intuition � ������������� ����� ������� � ����� ������������������
   ������� ��� ������ � ����������� �����������. �������� ����� �������
   `gadtools.library`, ������� ��������� ��������� ����� ������� gadgets, �
   `asl.library`, ������� ������������� ������� ������������ �������� � ������
   � ������ `������������� �������� (requesters)`.

.. ���������: �������� �������� zune, graphics � ������.

��� �������� ���������� AROS
''''''''''''''''''''''''''''

�������� `����������` ������ ���������� ������, ����� �������� �������� �������
� ����� ����� �������, ������� ��������� ����� �������� ������������ �����
����� ��� ������, � ������ ��� ��� ������� ������ ����� ����, ������� �����
���� ���������� ������������� ���������������� �����, ����������� ������������ 
� ������� ������ �����, ������� ��������� ����� �������� ���������.

� ����� ���� 2 ���� ���������: ����������� (link-time) � ������������
(run-time). ����������� ����������, ��� ������������ ��������, ������������
������ �� ����� ���������� ���������: ����������� �������� ��� �������, �������
����� ���������, �� ��������������� ��������� � ��������� �� � �����������
����. ������������ ����������, ������ �����, �������� ���������� ����� ���
����������� ��� � �������� �� ���������� ����������� ����������� �������� ��
��������. � ����������� ������ ������������ ���������� ������������
������������ ����������� ���������, ���������� ���� � ������ ����������� ������
���� ����� ����������. � ����� ������� �� ����� �������� `��������� 
������������� ������������`.

� �� ����� ��� ���������� ������������ ������������ ����� ��� ����� ���������
�� ���� ������������ ��������, �.�. ��� ���������� �� �� ���� �� ����,
���������� ������������� ������������ � ������ ������������ �������� �����
�������������� ��-�������.

����� ��� ��� ���������� ����� ���� ������������ � ���������, ��� ������ ����
`�������`. ��� ����� ������� �������� ������� ��� ��������� ``OpenLibrary``.
����� ���� ��� ���������� ������� �������, ������������ ��������� ��� ����������
`������������ ����`. ������������ ���� - ��� ������� ������,
���������� ������� ������� � ����������� ������ ��������� [#]_. �����
���������� �������, ��� �������� �������� ����� �� ���� ����� � ��� �� ��� ����
����� ��� �� ������ ��� � ������ ����� ����������� �����. ����� ������� ��
���������� ������� �������� ����� ������������ ���� ������� �������
������������� ������ �������� ����� ���� ������������ � ���������� [#]_.
���������� ����� ������� ����� ������ ��� ��� ������ ������� � ������������
���� �������������� �� ����������� ���� ��� ����. ���� ��� ����� �����, ��
������ ��� � ����� ��������� `proto/libname.h`. ��������� ����������
���������� ���������� ���� ��������, �� ����� ����� ���������� �� ������
���-���� ������������� � ������������ �������� �������� ���������� ���������
���������� �������� ������������� ��������� �������.

.. [#] ���� �� ������� � C++, �� ������ ������ � ������� �������� ��� �
       `VTable`, ������������ ��� ����������� �������, � �� ���������
       ������������ ���� ��� �� ��������� `this`.

.. [#] �������� ������������ ���� ����� ���� �����, ���� �������, � �����������
       �� ���������� ������������ �����������. ����� ��������� ���������� �����
       ���� ������ �������� ����: ������� ������������� C, ������������ �������,
       ���������� ���������� � �.�.

��� ��������������� ��������� ������������� ������������ AROS
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

��� ��� ����������� � ���������� �������, ���������� ���� ��������� �� ���� ��� 
�� ������� ����� ����� ������������. ������������ ����������, ������� ���
������������� ���������, ��� `exec.library`. Exec �������� ������
�������� � ��� ���������� ����� ��� �������� � ��� ������. ������������� ���
���������� ���������� ���������, ����� ������� �������� ������� ��������� ����.
���� ���� ��������� ��������� � ���������� `proto`, ��� ��� ���� �� ������
��������������� ���������, ��������, �� ���������� `dos.library`, �� ��� ����
������������ ��������� ������::

  #include <proto/dos.h>
  
��� ���������� ��� ����� ������ ����� ������������� ������� ��� ��� ���������
����������, �������������, ��� ��� ������������ ��������� �� �������. ��������
����������� � ������ �����������, ����� ������ � �������� ������������. �
��������� ���������� ����� ���������� � ���, ��� ��� ������� ��� ������
������������, ��������� � AROS, � ��� ��������� ���������� �������.

�������������� �������� ��� ������ gcc �� AROS SDK
''''''''''''''''''''''''''''''''''''''''''''''''''

���������� GCC �� ������ AROS SDK ������������� ��������� ��������� ��������
����������:

- aros.library
- asl.library
- commodities.library
- cybergraphics.library
- datatypes.library
- diskfont.library
- dos.library
- expansion.library
- gadtools.library
- graphics.library
- icon.library
- iffparse.library
- intuition.library
- keymap.library
- layers.library
- locale.library
- muimaster.library (��������������� � AROS �������� Zune)
- partition.library
- realtime.library
- utility.library
- workbench.library

�� ������ ��������� ������������ ���� ���������, ������ ����������� GCC ����
``-nostdlibs``. ��� ������ ��������� ��������������� AROS �� ������
������������ ��������������� ����������� ����������, ������� ����������� ��
�������� ���������. �������������, ����, ��������, ���� ��������� ����������
���������� reqtools.library, �� �������� ���� ``-lreqtools`` � ������� ������
����������� GCC. 

.. ����������:: ��� ���������: ����� ����������� ���������� AROS GCC
   ������������� ��������� ������������ ��������� ���������� ����� ������� �
   ����� �������������� � 2 ����:

   + ����������� �������� ��������� ��� ���������� ������� �� ����������::
   
       #include <proto/reqtools.h>

   + �������� �������������� ������ �� ����������, ���� ����������
     ������������� �� ����������� GCC::

       % i386-linux-aros-gcc ... -lreqtools

�������������� ��������  ��� ������ ������ ������ AROS
''''''''''''''''''''''''''''''''''''''''''''''''''''''

������������ ��������� �������� ������ ����� ������ �� �������������
����������� AROS GCC. ���������� ����������� ����� ``-l`` ����������
������������ ���� ���������� � ��������� ``uselibs`` ��� ``%build_prog`` �
������� ``%build_module``. ����� ��������� ���������� �� ������ ����� �
`����������� �� ������� ������`__.

__ buildsystem#build-system-tutorial

�������� ��������� �������
''''''''''''''''''''''''''

��� �������� ���������� ��� ���� ������������ ������� �� `exec.library`::

    #include <proto/exec.h>

    struct Library *OpenLibrary( STRPTR name, ULONG version );

������� `OpenLibrary()` ��������� 2 ���������:

name
    ��������� ��� ����������. ������ ��� ������� ��������� ���, �� ��� �����
    ����� ���� ������ (���������� ��� �������������) ���� � ����������.
    
    .. ����������:: ���� �� �������� � ������������, ����������� � ����
                    ������������ �������. ����������� ���������� ���� ������,
                    ���� ����� ������, ��� �������!
                    
version
    ���������� ���������� ������ ����������� ����������. ���� ���������
    ���������� �������, �� � ������ ���� ���������, �� ���������� �� �����
    �������, �� ����� ���������� ������. ������ ����� ��������� �����������
    ���������� ���������. ��������� ������� �������� ������ ������� �
    ����������� ������ ����������. ��������, ������� `AllocVec()` ��
    `exec.library` ��������� � 36 ������ ���� ����������. ���� �� �����������
    ������� ��� �������, ���� ������������� ����� ������ ������ `exec.library`,
    �� �������� ��������������� ���� (������ ����� ������������������
    ����������).

��������� ������� �������� ���������� ��� �������� ���������� ��� ��������:

1. ��-������, ��� ���������� ������ � ������ ��� ����������� ���������. ����
   ��� ���������� ���� ��������� � ������ ����� (��������, ������ ����������) �
   �� ��� ��������� ���, �� �� ������������ � �������� ������� `OpenLibrary()` 
   ����� ���������� ����������.

   ����������, ���������� � ����, ������ ��������� � ������ �����������
   ���������.
    
    .. ����������:: ����� � ���� ������ ������������ � ��������! ������ 
                    �������, ��� ����������� ���������� ������� � `name`.
                    ������ ��� ������� � ��������� ��������� ����������� �
                    ������ ��������.

2. ���� ���������� �� ������� � ������ ����������� � ������ � `name` ���
   ������� ����, �� ����� ����������� ������� ������� ���� �� ���������� ����.
   ���� ��� �� ���������, �� ������� `OpenLibrary()` ������ ������.
   
3. ���� ���� �������� ������ ������� ��������� ���, �� ���������� ����� ������ 
   ������� � `������� ����������`. ���� ��� ��� �� ����� �������, �� ����� �
   ��������� ����� � ���������� `LIBS:`.

   
`OpenLibrary()` ������ ���� ��������� �� ���������, ����������� ����������
(`struct Library *` ����������� � ``exec/libraries.h``), ���� `NULL`,
����������, ��� �� �����-�� �������� ������� ���������� ���������. ��������
��������� ����������� ��� ������������� ������������. ������ �� �������� �
���������� � �����: `<���_����������>Base`, ��������, `IntuitionBase` ���
��������� �� ���������� *intuition.library*.

����� �������� ����������, �� ������ ������������, ��������������� �� �������, 
������ ������� �� ��� ����� ������ ������� � ����� ���������. ��, �����
��������� ������ ����������� ������ ��� ������, ��� ���� ���������� �����������
� ���������� ������������ ����. ��� ������������ C ��� ������ �������� ������� 
*proto/<���_����������>.h*.

����� �� ��������� ������������ ����������, ��� ���� ������� � ���
������������ ������������ �� ��������. ��� �������� ��� ������::

    #include <proto/exec.h>

    void CloseLibrary( struct Library *base );

    
������� `CloseLibrary()` ��������� ���������� ��������� `�����`. ��� �����
����� ���� `NULL`, � ������ �������� `CloseLibrary()` �� ������ ������.

�� ���������������� ������������� ��������� ��������� ��������� �����������
��������� �����������. ������ ������ �� ����� ��������� ``Hello World!``, ��
����� ���������� ��� � ������� �������. ��������, ������������
������ �������, �������� `EasyRequestArgs()` �� ����������
*intuition.library*. �� �� ����� ����� ��������� � �������������. �����
��������� ���������� �������� � ������� `Requesters`.

������ ������������� ���������::

    #include <proto/exec.h>          /* OpenLibrary() � CloseLibrary() */
    #include <exec/libraries.h>      /* struct Library */
    #include <dos/dos.h>             /* RETURN_OK � RETURN_FAIL */
    #include <proto/intuition.h>     /* EasyRequestArgs() */
    #include <intuition/intuition.h> /* struct EasyStruct */

    /* ��� ���������� ����� ������� ��������� �� intuition.library */
    struct IntuitionBase *IntuitionBase;

    int main(int argc, char *argv[])
    {
        /* ����� ��� EasyRequestArgs(). */
        struct EasyStruct es = {
          sizeof(struct EasyStruct), 0UL,
          "Requester", "Hello World!", "Ok"
        };

        /* ������� �� ��������� intuition.library. ��� ����� ������ 36 ���
           �����, ������ ��� EasyRequestArgs() ���� ������� ������ �������
           � ���� ������ intuition.library.
        */
        IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", 36);

        /* ���� ���������, ������������� �� intuition.library ���� �������
           �������. ���� ���, �� �� �� ������ �������� ������� �� ��, �������
           �� ���������� ������ ������.
        */
        if (!IntuitionBase)
            return RETURN_FAIL;

        /* ����� �������� intuition.library, �� ������� EasyRequestArgs(). */
        EasyRequestArgs(NULL, &es, NULL, NULL);

        /* �, �������, ��� ���� ������� intuition.library. */
        CloseLibrary((struct Library *)IntuitionBase);

        return RETURN_OK;
    }

���������� �������������� � ��������� ���������. ��� ���������� ��� ��������
���������, ������������ ������ ������� "Hello, world!" � ������� Ok.
                    
���������� ����������� ������� ������
'''''''''''''''''''''''''''''''''''''

��������� ������������ ���������� ����� �� �������� ����������� � �������������
����� �����������. ������, ����� ��������� ���������� ����������� ����� ������
������ ���������� � � ��������� � ������� ������� ����� ������ ������, ��
�������� ��������, ��� ��� ������� � ���������� ���������� ���������. ��� ��
����� ��������� ������ ��������� ������� ��� ����, ����� ��������� �����
���������, �������� �� ������ ���������� � ��������� ����������� ���
��������������� ������� ���������� ���� ����������������, ���� ���. � AROS � 
Amiga-�������� ������������ �������� ������ ������������ ������� (major) �
������� (minor) ������� (����� �� ������������� "������" � "�������"). �������
����� ��������� �� �������� ����� ������������, � �� ����� ��� ����������
�������� ��������� ���� �� ��������� ����������� �/��� ����������� ������,
�� � ����������� �������������. ������ ���������� ����� ��������� ���
major.minor [#]_, � � ����� ������ ��� ������ ������� version::

  5.System:> version dos.library
  dos.library 41.7

��� �������� ���������� �� ������ ������� ����� ������ � ������� ��������
���������� ��������, ���� ������ ���������� ������, ��� ��������� ��������::

  mylibbase = OpenLibrary("my.library", 2);

����� ����� ���������� �������� NULL ���� ����������� ������ ������ 1 
���������� my.library. ���� �� ����������� ������������ ���������, �� �����
������� �� ������ ����������, ������� �������������� �� ����� ����������. ���
������ ����� ���� ������������� ��� ������ ���������� libbasename_version. �
������ ������ dos.library ����� ������ 41 � ��� ������, ��� ����������������
��������� ����� �������� ������ � ����� ������ ��������, ������� ����� 41-�
������ ���������� dos.library. ���� �� �������, ��� ����������� �����������
������ ������ �� 36-�, �� ������ ��������� ���� ��������� � ��� ������� ��
��������� ���������� ���-������ � ����� ����������� ����::

  const LONG DOSBase_version = 36;

��� ���������, ���������� ������ ������ ���� �������
������������: ���� ������ ����� ���������� 41, � ��������� �������������� �
������� 36, �� ��� ������ ���������� �������� ��� �������. ���������� �����
������� �� ����������� ����� � ������� ������������ ������ ������ ���������
����� �� �� �������� ���� ��� ����� ����� ������ ����������.

���� �� ������������� ������ �������� ��������� ������� � ����������� ������,
��� ���� ������� ���, �������� � � ������ ����� � ������� ������������. �����
�� ������ ����� ����������� ����������� �������, ������� �� ��� �����
���������� � ���������� ����� ������ ������ ����������. ��������, ��� ����
������� ��������� ��� ������� `OpenLibrary` �� exec.library. � ������ ������
AmigaOS ��� �� ����� ������ ��������� ��� ������ � ���� ��������� �� ����� 68.
� ����� ������� ������� ���� ������� ������� `OpenLibrary`, ������� �������
������, � ��������� �� ����� 92. ������� �� ������� 68 ���� ������������� �
`OldOpenLibrary`.

.. [#] � ����������������� ����, ��� ��������� ���� ������, major.minor ������
       �� �������� �������� ���������: �������� ��������� ����� 1.9 ����� 1.10,
       � 1.09 �� �������� ���������� ������� ������ ��� AmigaOS � ������������
       � �������� �������� ��������� ������.

������� �� ������ ������ � ������������� ������������
'''''''''''''''''''''''''''''''''''''''''''''''''''''

��������� ������������ ���������� AROS ����� ���������� ����������� �� ������
�������������� � ������������. ��������� ������� ����� ����������� ����� � ����
�����. � �������� ��� ���� �� ����� ��������� �� Windows � UNIX(-��������) �������.

�������� ��������� ������������ ���������
'''''''''''''''''''''''''''''''''''''''''

� AROS ����������� ����������� ���������� �������� ������������� ELF-��������. 
� ������ ����� ����� �������� ���������� ��� ����������� � ����� � ����������� 
�� ���������� ������, � ������� ��� ���� ���������. � AROS � Amiga-��������
�������� ���� ���, ���������� � ������� ���������� ���� ������� ������� ������.
��� ��������, ��� ��������� ����� ������������ ����������, �����
����������� � ������.

������ �������, ������� Windows � UNIX, ����� ������ ����������� ��������
������������ ��� ������� ��������. � ���� ������, ������������ ������� �����
�������� ��������� ��������� ������������ ���������� ������ ������� � �����
�������� ���������� � � �������� ������������ ������� ��������, �������������
��� ����������. ����� �������, ���������� ����� ������������� �� ������ �������
� ������ �������� ������������� � ������������ ������� ������ ��������� ����
���������.

Windows �������� ����������� ��������� ������������ ���������� � �����������
����� ������ � ���������� �� � �� �� ������� ������, � ������� ��������� ������
������������ � �������. ���� ��� ����������, ���������� ����������� � ������.
� ����������� ������ UNIX ��� �������� �������� ���� ���������� �����������
������������ ����������-����������� ���, ��������, ���, ������� �������� ��
����� ������� � ������ ��� ������������� ��� �����������. � �����������
�� ����������� ���� ��� ���� ����� ����� ������� ��� ������� ������� ��
�������� ������ �����������.

������������ ���������� �������
'''''''''''''''''''''''''''''''

�����������, ������������ ��������������� ����� ���������������� ��� ������� �
�������� ��������� ������������ ���������, ����� ������������ �� ��� �������,
������� �������. ����� �������������� ��������� ���������, �� ���������� ������
������ ��� �������� � ����������� �������. �������������� ���, ������������
�������������, ������ ���� ������������� � ����� � ������.

� Amiga �������������� ����������, ����� ��� ������������� ��� ����� ���������
��� ������ �����������. ������ libbase ���������� AROS �������� �������
������������ ��� ������� ����������. � �������� ���������� (��� ����������) ���
������� ������������� � ������� � ���� �������, � ������� ����� ���� ������
����� ������� [#]_. ����� �������, ������� � ��������� ������������ �����������
AROS �������� � ����� ������� ��������������. � ����������� �� ����������� ��� 
���� ������� �������������� ����� ����� ������� ��� ������� ������� �� ��������
������ ����. � �������, �������� ��� �������������� ������������ ��� ������
����������� ������� � ������� C++ � �������� ����������� ��� �������������� ���
���������� ��������������� ��� (��������) ������� �� ��������. ��� ��� ������� 
������������ ����������� � libbase, �� � ���� ����������� ��� ���������,
������������ per-opener base.

� Windows � UNIX-�������� �������� �������������� ����� ������� � �����
���������� ����� ��������� ����������� � ������ � ����������� ����������� �
��������� ������������� ������������ [#]_. ����� ��������� ����������� �� �����
��������������, ������ ��������� ���������� � ����������� ���� ������ ��
������� ������������ �������. ��� ������ �������� ASCII ��������. �����
��������� ������������ �����������, ����� ������� �������������� � �� ������
(��� � ��������� � ������� ������������). ������� ���������� �� ������
��������� �����������, ����� ���� ������ ������� ������ � �����������. ���
������ ��� ������� ������������ ��������� ���������. ��������, � Windows
��������� ������� ���������� � ��������������� ������, ��� ��� ����� ����
��������� �������� �����, � � Linux ��� ��������� ������ ������������ ����.

���������� � ����������� ���������� � �����������
'''''''''''''''''''''''''''''''''''''''''''''''''

��� ���������� � ���������� ���������, ��������� ������������ ���������� AROS
����������� � ������ � ���������������� ������ ���� ���. ��� ����� ������ ��
������� ���������� ����������� � ������������ �����������. �� ������ ��������
���������� ���������� � �������� ���� ����� ���������� ��������� ��������::

  int globvar;
  
���������� ���������� ����� �������� �� ���� ������
����������. ����� ��������� ������������ ���������� ��������� � ������, ����
���������� ����� ����� ��������� � ������, ������� ����������� � ����� ������
���������� �� ����� � ��� �� �����, ���� ���������� �� ����� ��������� ��
������. ����������� ����������, ����������� � �������, ����������� �����������
��������. ��� ����� �������������, ��� ��� � ���������� ������������ �
���������� ���������� ����� ������ ����������� � ���� � ���� ����� � ������, ������� 
������� ��� ���������� ����� ����������� ��� ����� ��������� �������
��� �� ����������. � ��������� ����� ������������ �������� �������� ����������,
������� ����� ��������� �������� ��� ������� ������������ ����������, ��������
���������� � per-opener base � �������� ���������� � ���� ����. ����� � ������
������ ���������� ���������� �� �������������� �� ��������� ������������
��������� AROS. ��� ����� ���� �������� ������ ������ ����� ����������,
���������, ������������ ����������, �� ����� ������� ������� � ����������
���������� ����������. � ���� ��������� ���������� � ��������� ������������
����������� AROS ����������� �������� ������� �� ���������� � �����������
�����������. ���������� ���������� ����������� � ����������� ����������
���� �������� ���������, � ������� ���������� ������������, � ������ ���������,
�������������� � ���� �� ����������� �����������, ����� ����� ���� ����������� 
������ ���������� ����������.
  
� UNIX, ��������� ������������ ���������� ���� ������� ����� ����, ���
����������� ���������� ��� ������������ ��������������. ����� �� �����������
������� ����� ��, ��� ��������� ��������� ������������ ��������� ���� ����� ��,
��� � ��������� �����������. ������� ������ ���, ����� ��������� ���������
��������� ������������ ����������, �������� ����� ����������. � ���� ������
������ ���������, ��������� ��������� ������������ ����������, �������� ����
���������� ����� ���������� ����������. ����� ���������� ���������� ���������
������������ ���������� ������������� ���������������� �� ���� ����������,
���������� ���� ���� �������� �������� �� ���������, ������������ ���
����������.

� Windows ����� ������� ��������� ���������� ���������� ��� � AROS, ���� ��� �
UNIX, �� �� ��������� ��� ����������� ��� � UNIX.

��� ������������ ��������� ������������ ��������� � AROS ��� Amiga ��� �������
� ��������� ���������� ������ �����������. ��������� ���������� ������� ��
����, ��� ���������� ����������� � ��������� ������������ ����������� UNIX �
Windows, � �� ������������ � AROS ����� ��������� ���������������.

.. ����������::
   � ���� ��������� ����������� ��� �������� ���������� ������� � ���������
   ������������ �����������, ����� ����� ��� �������. � ������ ������ �����
   ����������� ��, ��� �������������� ������� ����� ���������� �� ����������
   ������� ������ ���������.

����������, ������������ ������ ����������
''''''''''''''''''''''''''''''''''''''''''

���������� ����� ������� ������ ����������. ����� ����, ��� ���������� ������� 
������ ����������, ��� �������� ���� ���� ����������. ��� ��������, ���
����������, ������� ���� per-opener , ������ ������ ���������� ����������
��������� ����. ����� ��������� ��������� ���������� � per-opener base, ������� ���
������� ����. ������, ����� ��������� ��������� ������ ����������, �������
��������� ������ ����������, ������ ���� ����� ����������
������ ����������, � ����� - ���������. ��, ��� ������ ���������� �
per-opener libbase ������ ��� ���������.

��� ��� ���������� ����, � UNIX � Windows �� �������� �� ���������. �����
��������� �����������, �������� ����� �������, ������ ��������� ������������
���������� ������������ ���� ��������� ����� ������ ������� �����������
������������ � ���������. ��� ������, ��� ��������� � ��������� ������������
����������, ������� ������ � ������ ��������� ������������ ����������, �����
������������ ���� � ���� ����� ���� ������ ����������. ��� �������� � ���������
����� ������� ������������ ��������� ������������ ��������� �� UNIX/Windows
���������������.

.. ����������::
   � ���� ��������� ����������� ��� �������� ���������� ��������� ���������
   ������������ ��������� �� ���������, ����� ����� ��� �������. � ������
   ������ ����� ����������� ��, ��� �������������� ������� ����� ���������� ��
   ���������� ������� ������ ���������.

.. [#] �� ����� ����, � ������ ����� AROS, ��� ������� ����� ��������� ������, ���
       ������ ��������� �������. � AROS ��� ��������� 68k, ����������, ���
       �������� ������������� � AmigaOS (tm) �������� ���������, ������
       ��������� � ������� �������� ���������� JMP, ��������� �� �������
       ������� (������� ����� ������� �������� ������ ���� �������� JMP), �
       ��������� ������������ �� �������� � ������ � �������, ��� ��������� 
       � ������ �������, � ����� ���������� JMP �������������� ����� ������
       ��������� ���������� �������.

.. [#] ���������: ��������� ������������ ���������� a.out, cardinal � Windows
       � �.�.
   
������ �������������� ���������� ����� taglist
----------------------------------------------

������ ������� ���������� ������� ������������� ����� ����������. ��� ������
�������� �� �������� ���������, ������� ����� ��������� � ������� ����������
����������. ��� ������ ���� �������� ���� ������� ��� ���������� ������ �����
(taglist). � ``utility/tagitem.h`` �� ������� ��������� `TagItem`, �������
�������� � ���� ����� `ti_Tag` � `ti_Data`. ������ ����� �������� ������ �����
��������. ������ ������ �����������. ���� `ti_Tag` �������� ���������������
(����� ����������� ��� Tag), ������� ����������� ���������� `ti_Data`.
`ti_Data` �������� ���� ������������� �����, ���� ����������. ��� �����������
���������� ������ long-word ��� ��������� (����� �� �� ��� �� ��� ������).

� ������ �������� �������, ������������ ������ �����, ����������� ��� ���������
����. ������� ������ ������������ ����������� ���� � ������������ �������� �� 
��������� ��� �� ��������������� �����, ������� ������ ����� �������� �����
������ �������� �������������� ���������� ��������.

���� ��������� ����������� �����, ������� �������� ��� ������� (��� ���������� 
� ``utility/tagitem.h``):


`TAG_DONE` � `TAG_END`
    ���������� ����� ������ �����. ������ ������ ����� ������ ������������
    ����� �� ���. ����������� `ti_Data` ������ ���� �������������� ����������
    ��������, ������� ��� ������������� ���������� � ������.

`TAG_IGNORE`
    �������� ��� ���������� `ti_Data` ������������. ���� ��� �������� �������
    ��� ��������� ��������� �����.

`TAG_MORE`
    ��������� ���� ���, �� ������ ������� ������ ����� �������. `ti_Data`
    ��������� �� ������ ������ �����. ��������� �������� ������ ����� �����
    ����������� � ������ �� ����� �������������� ����� ������ �����. ���� ���
    ����� ��������� ������� ������ �����.
    
`TAG_SKIP`
    ���������� ������ ���������� ��������� ���� `ti_Data`. ��� �� �����
    ����������.

�� ����� ������ �������� ������ ����� `NULL` ������ ���������. ��� �������
������ ���� �������� ��������� ����������� ���� `NULL`. ��� ����������� �������
�����, � ������� ������ ����� �������� `TAG_DONE`.

�������, ������� ��������� � ������ �����::

    #include <proto/intuition.h>

    struct Window *OpenWindowTagList
    (
        struct NewWindow *newwin, struct TagList *taglist
    );

.. FIXME::*    ��� ������� ����� �������� ��������� � ����� �� �����.

������ ��� ���� ������ �����, ��� ��� ������� ��������� ����� ����. �� �������
��������� `newwin` �������� `NULL`. ������������ ����, ������������ ������:

==========  ===============================  ========
���         ��������                         ���
==========  ===============================  ========
WA_Width    ������ ���� � �������            UWORD
WA_Height   ������ ���� � �������            UWORD
WA_Title    ��������� ����                   STRPTR
==========  ===============================  ========

������ �������, ����������� ��� � ���� ��������� �������::

    #include <proto/intuition.h>

    void CloseWindow( struct Window *window );

��� ������� ������������ ��� �������� ��������� ����.

������ ������� ��������� �� ������ ��������� ��������� hello-world. ���
��������� ����, � ��������� �������� �������� "Hello, world!", �� 2 �������::

    #include <proto/exec.h>
    #include <exec/libraries.h>
    #include <proto/dos.h>
    #include <proto/intuition.h>
    #include <intuition/intuition.h>

    struct DosLibrary    *DOSBase;
    struct IntuitionBase *IntuitionBase;

    int main(int argc, char *argv[])
    {
        int error = RETURN_OK;

        /* ��� ��� ����������� ������� ��� ������� Delay(). */
        DOSBase = (struct DosLibrary *)OpenLibrary("dos.library", 36);
        if (DOSBase)
        {
            IntuitionBase = (struct IntuitionBase 
            *)OpenLibrary("intuition.library", 36);
            if (IntuitionBase)
            {
                struct Window *win;
                /* ����� �������� ����� ����� */
                struct TagItem tags[] =
                {
                    { WA_Width, 100                  },
                    { WA_Height, 50                  },
                    { WA_Title, (IPTR)"Hello World!" },
                    { TAG_DONE, 0UL                  }
                };

                win = OpenWindowTagList(NULL, tags);
                if (win)
                {
                    /* ������ ��� 2 �������, ����� ���� �� ������ ���� ����.
                    */
                    Delay(100);

                    /* ��������� ���� ����. */
                    CloseWindow(win);
                }

                CloseLibrary((struct Library *)IntuitionBase);
            }
            else
                error = RETURN_FAIL;

            CloseLibrary((struct Library *)DOSBase);
        } else
            error = RETURN_FAIL;

        return error;
    }

�������, ���� ����� ������� ������ ����� ���������� ������������. ������� ���
����������� �������, ������������ ������ �����, �������� ����������� ��������.
����������� ���������� `amiga.lib` ������������� ��� ����������� �������� ����
���������� �������� AROS. ��� varargs ������ ����� ������������ ���������
�������:

    #include <proto/alib.h>

    Function( arg1, ..., argn, TAG1, data1, ..., TAG_DONE );

��� ������ ���� ����� ��������� ���, ��������� varargs ������ �������
`OpenWindowTagList()`, ������������ `OpenWindowTags()`::

    [...]

    if( IntuitionBase )
    {
        struct Window *win;

        win = OpenWindowTags
        (
            NULL, WA_Width, 100, WA_Height, 20,
            WA_Title, "Hello World!", TAG_DONE
        );
        )
        if( win )
        {

    [...]

������� �����, �� ��� ��?
    
��������� �������� ���������� ������������
==========================================

"Hello, world!" - �� ������� ������� ������������, �, ��������, ��� ����� 
���������, ���� �� � AROS ���-�� ������������. ��� ��, �������, ������� ����. ��
��� ����������� �� �������� �� ������������ ������������, �� ����������
������������ ������������. ����� ����������� ����� ���� ����� �������� �
�������, � ���� ������� ������������� ������������ ��� AROS, ������� �� ������
�����, �������� �����, ���������� ��� Amiga, � ������ ������������ �� AROS
- `autodocs <./../autodocs/index>`__ (autodocs ���������
������� ��������� AROS, ������� ��������� ����� ��������������� �������
��������� ���� AROS).

� ��������, ��� ������� ������� ������������� ��� Amiga: ��� ��������
������ ����� ������� ���������� ������ �������. ���� �� ������ ���������
���������������� ��� AROS � ������ ������, ��� ������������� ������� ����������
����� ������ ����� �� Amiga ��� ������ �������-���� ������������ ��� Amiga
(Amiga Developer CDRom, RKM - ROM Kernel Manuals).
