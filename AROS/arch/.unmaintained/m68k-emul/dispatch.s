#    (C) 1995-96 AROS - The Amiga Replacement OS
#    $Id$
#    $Log$
#    Revision 1.3  1996/12/05 15:30:59  aros
#    Patches by Geert Uytterhoeven integrated
#
#    Revision 1.5  1996/11/01 02:05:24  aros
#    Motorola syntax (no more MIT)
#
#    Revision 1.4  1996/10/24 15:51:30  aros
#    Use the official AROS macros over the __AROS versions.
#
#    Revision 1.3  1996/10/24 01:38:31  aros
#    Include machine.i
#
#    Revision 1.2  1996/08/01 17:41:34  digulla
#    Added standard header for all files
#
#    Desc:
#    Lang:

#*****************************************************************************
#
#   NAME
#
#	AROS_LH0(void, Dispatch,
#
#   LOCATION
#	struct ExecBase *, SysBase, 7, Exec)
#
#   FUNCTION
#	This function switches between the task in SysBase->ThisTask and
#	the first task in the ready list. It must be called from supervisor
#	mode with all registers set to the values of the underlying user
#	context and sp pointing to the normal exception frame (just as if
#	it was a routine in one of the interrupt vectors).
#
#	SysBase->IDNestCnt is moved to and from the task structures and
#	the interrupt control is prepared accordingly. The routines in
#	task->tc_Launch and task->tc_Switch are called if necessary and
#	a task exception for the new task is raised if TF_EXCEPT is set.
#
#   INPUTS
#
#   RESULT
#
#   NOTES
#	Raising an exception for a waiting task reactivates the task
#	completely.
#
#	If the current task (when calling this function) is not part of
#	one of the two task lists it gets lost.
#
#	This function is for internal exec use only.
#
#	This function is processor dependant.
#
#   EXAMPLE
#
#   BUGS
#	This function currently reads the global variable sysbase instead of
#	*(struct ExecBase **)4. This makes it usable for link libraries.
#
#   SEE ALSO
#
#   INTERNALS
#	For the task lists the following conditions must always be true as
#	long as SysBase->IDNestCnt>=0. Changes are legal with interrupts
#	Disable()d only:
#
#	* A task is in state TS_WAIT if and only if it is part of the waiting
#	  list.
#	* It is in state TS_READY if and only if it is part of the ready list.
#	* SysBase->ThisTask always points to a legal task structure.
#	* In normal user context SysBase->ThisTask->tc_State is TS_RUN.
#	  There are two possible exceptions from this rule:
#	  * In supervisor mode when bit 15 of SysBase->AttnResched is set
#	    (dispatch pending bit).
#	    This ends by calling Dispatch() before falling down to user context.
#	  * In exec code. This ends by calling Switch() before going back to
#	    user code.
#	* The task in SysBase->ThisTask is one of the ready tasks with the
#	  highest priority (round robin). There's an exception from this rule,
#	  too:
#	  * If dispatching is disabled and bit 7 of SysBase->AttnResched is set
#	    (switch pending bit) it is allowed to have a running task with a
#	    lower priority as a waiting one. This ends by calling Switch() as
#	    soon as the dispatcher is reactivated.
#	* The ready list is sorted by priority.
#	* There is always at least one task willing to run - the busy task.
#
#   HISTORY
#
#******************************************************************************

	# Dispatching routine for the 68000.
	# Higher models (with FPU) need a slightly different
	# routine or the additional registers cannot be used!

	.include "machine.i"

	.text
	.balign 16
	.globl	_Exec_Dispatch
	.type	_Exec_Dispatch,@function

_Exec_Dispatch:

	# preserve a5 then move user stack pointer into it
	movel	%a5,%sp@-
	movel	%usp,%a5

	# move whole user context to user stack
	movel	%sp@+,%a5@-
	movew	%sp@+,%a5@-
	movel	%sp@+,%a5@-
	moveml	%d0-%d7/%a0-%a4/%a6,%a5@-

	# get SysBase
	movel	_SysBase,%a6

	# block all signals
	jsr	disable

	# get current task and store usp there
	movel	%a6@(ThisTask),%a2
	movel	%a5,%a2@(tc_SPReg)

	# call the switch routine if necessary
	btst	#TB_SWITCH,%a2@(tc_Flags)
	beq	noswch
	movel	%a2@(tc_Switch),%a5
	jsr	%a5@

	# store IDNestCnt and reenable interrupt hardware
noswch: moveb	%a6@(IDNestCnt),%a2@(tc_IDNestCnt)
	moveb	#-1,%a6@(IDNestCnt)

	# get address of ready list
	leal	%a6@(TaskReady),%a0

	# remove first ready task in the list
	movel	%a0@,%a2
	movel	%a2@,%a1
	movel	%a1,%a0@
	movel	%a0,%a1@(4)

	# and use it as new current task
	movel	%a2,%a6@(ThisTask)
	moveb	#TS_RUN,%d0
	moveb	%d0,%a2@(tc_State)

	# restore IDNestCnt and disable interrupt hardware if necessary
	moveb	%a2@(tc_IDNestCnt),%a6@(IDNestCnt)
	bpl	nodis
	jsr	en

	# call the launch routine if necessary
nodis:	btst	#TB_LAUNCH,%a2@(tc_Flags)
	beq	nolnch
	movel	%a2@(tc_Launch),%a5
	jsr	%a5@

	# get user stack pointer
nolnch: movel	%a2@(tc_SPReg),%a5

	# test task exception bit
	btst	#TB_EXCEPT,%a2@(tc_Flags)
	bne	exc

	# not set. read complete user context
	moveml	%a5@+,%d0-%d7/%a0-%a4/%a6
	movel	%a5@+,%sp@-
	movew	%a5@+,%sp@-
	movel	%a5@+,%sp@-

	# restore usp and a5 and return
	movel	%a5,%usp
	movel	%sp@+,%a5
	rte

	# Raise a task exception.
	# The user stack looks like: a5, ccr, pc, a6, a4-a0, d7-d0.
	# Change that to	     pc, ccr, a5, a6, a4-a0, d7-d0
	# so that it's easier to restore the context.
exc:	movel	%a5@(14*4),%d0
	movel	%a5@(14*4+6),%a5@(14*4)
	movel	%d0,%a5@(14*4+6)

	# do a Disable() to fall down to user context atomically
	jsr	%a6@(Disable)

	# prepare going to user mode
	movel	%a5,%usp
	movel	#usrexc,%sp@-
	clrw	%sp@-
	rte

	# handle exception
usrexc: jsr	%a6@(Exception)
	jsr	%a6@(Enable)

	# restore context
	moveml	%sp@+,%d0-%d7/%a0-%a4/%a6
	movel	%sp@+,%a5
	movew	%sp@+,%ccr
	rts

