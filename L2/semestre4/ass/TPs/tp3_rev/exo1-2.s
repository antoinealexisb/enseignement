	.data
mess:	.asciz	"Entrez votre message :"
nbmess:	.int	.-mess
chaine:	.fill	120,1,''
nb:	.int	.-chaine
temp:	.int	0
cara:	.byte	'A'
	.text
	.globl main
main:	movl	$4, %eax
	movl	$1, %ebx
	movl	$mess, %ecx
	movl	nbmess, %edx
	int	$0x80
	movl	$3, %eax
	movl	$0, %ebx
	movl	$chaine,%ecx
	movl	nb, %edx
	int	$0x80
	movl	%eax, temp
boucle:	decl	temp
	movl	temp, %eax
	movl	chaine(,%eax,1), %eax
	movl	%eax, %ecx
	movl	$4, %eax
	movl	$1, %ebx
	#movl	$cara, %ecx
	movl	$1,%edx
	int	$0x80
	cmpl	$0, temp
	je	fin
	jmp	boucle
	#mov	chaine(,%eax, 1), %ecx

	#movl	$4, %eax
	#movl	$1, %ebx
	;movl	mess(,%eax,1), %ecx
	;movl	$1, %edx
	;int	$0x80
fin:	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
