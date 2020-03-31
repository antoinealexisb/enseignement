	.data
toto:	.byte	't'
tata:	.byte	'o'
	.text
	.globl main
main:	pushq	$toto
	call	ecr_car
	pushq	$tata
	call	ecr_car
	pushq	$toto
	call	ecr_car
	pushq	$tata
	call	ecr_car
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
ecr_car:
	movq	8(%rsp), %rcx
	movl	$4, %eax
	movl	$1, %ebx
	movl	$1, %edx
	int	$0x80

	retq	$8
