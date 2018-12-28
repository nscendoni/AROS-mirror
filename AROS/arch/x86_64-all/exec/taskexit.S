#   Copyright © 2011, The AROS Development Team. All rights reserved.
#   $Id: taskexit.S 47619 2013-07-02 18:27:20Z neil $
#
#   Desc: Stack-realigning exit stub for x86-64
#   Lang: english

	.text
	.align	16
	.globl	TaskExitStub
	.type	TaskExitStub, @function

TaskExitStub:
	add	$16, %rsp
	ret
	.size	TaskExitStub, .-TaskExitStub
