/*
 * unwind.S
 *
 *  Created on: Feb 17, 2012
 *      Author: Jason McMullan
 *  $Id: unwind.S 47619 2013-07-02 18:27:20Z neil $
 */

/* unwind operation stubs */
	.align 2
	.weak __aeabi_unwind_cpp_pr0
	.type __aeabi_unwind_cpp_pr0,%function
__aeabi_unwind_cpp_pr0:
	mov		r0,#0
	bx 		lr

	.align 2
	.weak __aeabi_unwind_cpp_pr1
	.type __aeabi_unwind_cpp_pr1,%function
__aeabi_unwind_cpp_pr1:
	mov		r0,#0
	bx 		lr
