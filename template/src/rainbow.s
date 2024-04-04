	include "hardware/custom.i"

	xdef	_rainbow
	xdef	_getvbr
	xdef	_lev3irq
	xref	_vertb_irq

	section	.text

_rainbow	; d0 = delay
	move.l	d2,-(sp)
	move.w	#$fff,d1
.loop	move.w	d1,$dff000+color
	move.w	d0,d2
	beq.b	.skip
.wait	tst.b	$bfe001
	dbf	d2,.wait
.skip	dbf	d1,.loop
	move.l	(sp)+,d2
	rts


_getvbr movec	vbr,d0
	rte


_lev3irq
	movem.l	d0-a6,-(a7)

	bsr.w	_vertb_irq

	lea.l	$dff000,a3
	move.w	#$0020,$09c(a3)
	move.w	#$0020,$09c(a3)

	movem.l	(a7)+,d0-a6
	rte
