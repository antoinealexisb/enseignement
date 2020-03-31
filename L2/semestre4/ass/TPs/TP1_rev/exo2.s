	.data
note:	.int	15
	.text
	.globl main
main:	movl	note, %eax
	cmpl	$16, %eax
	jae	noteA
	cmpl	$14, %eax
	jae	noteB
	cmpl	$12, %eax
	jae	noteC
	cmpl	$10, %eax
	jae	noteD
	movl	$'E', %eax
	jmp	fin
noteA:	movl	$'A', %eax
	jmp	fin
noteB:	movl	$'B', %eax
	jmp	fin
noteC:	movl	$'C', %eax
	jmp	fin
noteD:	movl	$'D', %eax
	jmp	fin
fin:	movl	%eax, %ebx
	movl	$1, %eax
	int	$0x80
