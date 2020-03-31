	.data
chaine:	.asciz	"Je six"
	.text
	.globl	main
main:	pushq	$chaine
	call	len
	popq	%rbx
	movl	$1, %eax
	int	$0x80
len:	movq	8(%rsp), %rax
	movq	$0, %rcx
boucle:	cmpb	$0, (%rax)
	je	fin
	incq	%rax
	incq	%rcx
	jmp	boucle
fin:	movq	%rcx, 8(%rsp)
	retq
