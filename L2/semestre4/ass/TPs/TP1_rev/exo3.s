	.data
a:	.int	40
b:	.int	100
mutli:	.int	0
	.text
	.globl	main
main:	movl	a, %eax
	mull	b
	movl	%eax, mutli
boucle:	movl	a, %eax
	cmpl	b, %eax
	je	finboucle
	cmp	b, %eax
	jb	boucleif
	subl	b, %eax
	movl	%eax, a
	jmp	boucle
boucleif:
	subl	%eax, b
	jmp	boucle
finboucle:
	movl	%eax, a
	movl	mutli, %eax
	divl	a
fin:	movl	%eax, %ebx
	movl	$1, %eax
	int	$0x80
