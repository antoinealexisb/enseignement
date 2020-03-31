	.data
n:	.int	10
somme:	.int	0
	.text
	.globl main
main:	movl	$0, %ecx
	movl	$0, %eax
boucle:	cmpl	n, %ecx
	je	fin
	incl	%ecx
	addl	%ecx, %eax
	jmp	boucle
fin:	movl	%eax, somme
	movl	$1, %eax
	movl	somme, %ebx
	int	$0x80
