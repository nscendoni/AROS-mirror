/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: util.S 30792 2009-03-07 22:40:04Z neil $
*/

	.text
	.balign 16
	.globl	get_ssp

get_ssp:
	move.l	%ssp,%d0
	rts


	/*
 	 * Leave this!
	 */
	.text
	.balign 16
	.globl end_marker

end_marker:
	rts
