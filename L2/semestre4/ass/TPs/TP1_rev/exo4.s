	.data
res:	.int	1
n:	.int	10
	.text
	.globl main
main:	movl	$0, %ecx
	movl	res, %eax
for:	cmpl	n, %ecx
	ja	fin
	addl	%ecx, %eax
	incl	%ecx
	jmp	for
fin:	movl	%eax, %ebx
	movl	$1, %eax
	int	$0x80
