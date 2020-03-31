	.data
chaine:	.asciz "Je suis une chaine de caracteres"
nb:	.int	.-chaine
cara:	.byte	'a'
occ:	.int	0
	.text
	.globl main
main:	movl $0, %ecx
boucle:	cmpl nb, %ecx
	je fin
	movb chaine(,%ecx,1), %al
	incl %ecx
	cmpb cara, %al
	jne boucle
	incl occ
	jmp boucle
fin:	movl $1, %eax
	movl occ, %ebx
	int	$0x80
