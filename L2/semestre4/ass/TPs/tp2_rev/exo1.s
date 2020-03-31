	.data
nligne:	.byte	4
ncol:	.byte	8
comp:	.byte	5
cara:	.byte	'0'
cara2:	.byte	'\n'
	.text
	.globl main
main:	movl	$4,%eax
	movl	$1,%ebx
	movl	$cara,%ecx
	movl	$1,%edx
	int	$0x80
	incb	cara
	decb	comp
	cmpb	$0, comp
	jne	main
	movl	$1,%eax
	movl	$0,%ebx
	int	$0x80
