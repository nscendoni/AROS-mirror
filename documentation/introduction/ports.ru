==========
����� AROS
==========

:Authors:   Adam Chodorowski, Matthias Rustler 
:Copyright: Copyright � 1995-2007, The AROS Development Team
:Version:   $Revision: 30800 $
:Date:      $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
:Status:    Done.

.. Contents::


��������
========

��� �����������, ��� AROS - ����������� ��, �������������, ��� �������� �� 
���������� ��������� ����������. "����" AROS - ���, ���������, � ���� ������ 
AROS, ������������� �� ������������ ���������.

���� (Flavors)
--------------

��� ����� ������� �� ��� ������ ����, ��� ���� (Flavors � ������������ AROS),
� ������ - �� "������" ("native") � "��������" ("hosted")

Native-�����  �������� � ���������������� �������� � "�������" � ����� ������ 
������ � ����������. � �������, ��� ������ ����� ������������ �������� 
������������� AROS, ��������� ������������ ��������� ������������������ � 
�������������, ������, � ��������� ����� ��� ������������ ������� (�� ������� 
����, ����� �������� ��� ����������).

Hosted-����� �������� ��� ����������� ������ �� � �� ���������� � "������ 
��������", ��������� ����������� ��-�����. �� �������� ������������ - �������� 
����������, ��������� �������� ����� ������ �������� � ����������� ��������� � 
��. � ���� ��, ���� ��� AROS �� ������������ ���� ���� (���� ������ 
�������������� AROS ��� ��� �� �����), ��� ����������� �������� 
����������������, ��������� ��������� ��������� ����������� � ����� ����������, 
� "����������" ��, �� �������� � ���������� ������������� ������ ��� ����������� 
���������� ���������.

��������
--------

�������� ������ AROS ����� ��� <���������>-<���������>, ��� - <���������> - 
������������� �������� ���������, � <���������> - ����������� ������������� 
����������. ��������� ����� ���� ��� "��������" (� ������ native-������), ����� 
��� "pc" ��� "amiga", ��� �� (� ������ hosted-������), ����� ��� "linux" or
"freebsd". ������������ � �������� ����������� ��������� - "AROS/", ��� ��� 
��������, "AROS/pc-i386".

�������������
-------------

����������� ����� AROS �������� ��� ���� ������, ������� ���������� ���������, 
��� �����������, ��� ���������, ���������������� ��� "pc-i386" ����� �������� 
����� �� "linux-i386" � �� "freebsd-i386".


������������ �����
==================

���� �������� ������ ���� ������ AROS, ������������� ���������� ��� �����������
� �������� ����������. ������, ��� ���������� �������� �� ���, ��������� ��� 
���� �� ��������� � ����������� ����, ���� ��������� ������� �� ������������� 
�� ����������� ��� ������.

AROS/pc-i386 � x86-64
----------------------

:Flavour:    Native
:���������:  ��������, ��������� ��������� ���� ������������
:���������:  ����

AROS/pc-i386 native-���� ������������ ��� ����� ��������� IBM PC AT-����������� 
�����������, ������� ���������� x86 (��� x86-64) �����������. �������� ��������� ���������,
��������� ������ ���� �������, �� ������� ����, 486 - ������������ ����������,
��������� ������������� ����������, ������������� � 386. 
(���������� ����������� - ��������� ���� PCI).


���� ���� ������ ��������������, �� ���� ����� ������ ����� ������� ��������. 
����� �� ������������ ����������� �������� ��������� ��������� ������� ������ 
�� ������ nVidia and ATI. ��������� ������ ����������� ��������� ��������� 
������������ "������������" (��� ���������) VGA � VBE-����������. � ���������� 
��������� � ������ ��������, �� ������� ��� ������ ��������, ��������� 
������������� ��������� � ��� �������� 2,5 ��������. ���� �������� ��� ����������.

AROS/pp-m68k
-------------

:Flavour:    Native 
:���������:  �������� ��������������(� ���������), ���� ���������
:���������:  ����

AROS/pp-m68k - native-���� AROS �� ����� Palm-����������� ��� ("pp" ����� 
�������� "palm pilot", ��� ���������� ���-�������������� ���� �����). ��� 
������� �������, ��� �����-������ AROS ����� �������������� � ���� - � ����� 
��������� �������.

� ��������� ����� ���� ���� ������ "�����". � ����� � ����� �� �������������� 
(����������� � ���������, ����� ���� �� ��� �� ���� ��������� ���� ����������� 
�������), �� ��� ��� ��� �������� � ��������. ���� ����������� �������, �� ��
������� �������� ��������� �����. � ���������� ���� ����������.

AROS/linux-i386
----------------

:Flavour:   Hosted
:���������: ��������������
:���������: ����

AROS/linux-i386 - hosted-���� AROS �� �� Linux [#]_ ��� ��������� ����������� x86.

��������� "������" ���������� ���� AROS, ��������� Linux ���� �������� ������� 
������ � �������������, � ���� ���� ����� �� ������� ��������� ��� ������. 
�������� ��� ����������.

AROS/freebsd-i386
------------------

:Flavour:    Hosted
:���������: ��������������
:���������: ���� (5.x)

AROS/freebsd-i386 - hosted-���� AROS �� �� FreeBSD ��� ��������� ����������� x86.

���� ���� ����� ������������ ��������, ��������� ����� ������� ����� ���� � 
AROS/linux-i386 ������, ��, ����� ����� ������������ FreeBSD ����� ����� 
�������������, �� �� ������ �� ����. ��� ���������� ������� (snapshots) �� 
��������� ������������� ���, �� ��� ������ �� ������, ������� ���������� 
�������� ����� �� ���������.

AROS/linux-ppc
--------------

:Flavour:    Hosted
:���������: ���������������
:���������: ����

AROS/linux-ppc - hosted-���� AROS �� �� Linux ��� ��������� ����������� PPC.

������ ����� ������� � `Sourceforge`__.
��� ������ ���������� �������� ������ gcc3.4.3, diff ��� ������� ����� ����� � 
contrib/gnu/gcc.

__ http://sourceforge.net/project/showfiles.php?group_id=43586&package_id=194077

AROS/mingw32-i386
------------------

���� ���� ������������ ��� ������� �� Microsoft Windows (������� � Windows 98) 
� �������� �������� �������. ���� ��������� �� ������ ������ �������� � ����� ���� ����� 
����������� �������, �� ������� ���������������. ����������� ����� � ������ ������������ 
������� ���������� ����� �����. ��� ������ �� ����� ������������ GDI.

������ ������� ����� ����� ������� � ����� ������ �������.

�� �����������
--------------
��� ��������� ��� �����:


AROS/68k-native (aka AfA) - ���� � ����������, �������������� (?),
� �������� ���� �� ������ ������, � ������, ������� ��������� ��� �������� 
��������� AOS.

AROS/chrp-ppc - native-���� AROS �� ���� �������� Efika � Samantha. ������������
Michal Schulz � ��������� � �������� � ������ ������������ �������.


�������
=======

.. [#] ��, �� �����, ��� Linux �� ����� ���� ����� ���� ����, � �� �� � �����,   
       �� �� �� ������� ����� � ������ ������ ���, ������ "������������               
       �������, ���������� �� ���� Linux, ��������� ����������� ������������           
       GNU � ������� ������� X". ������, ��� ����������� �������� �������, ��         
       ��������� �������� ����� ��������� ����� ���������, �� �� �� ...
