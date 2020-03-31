.data
	chaine:	.ascii	"abcd"
	ordre:	.ascii	"abcdefgh"
	acoder:	.ascii	"cda"
	length:	.int	.-chaine
	zero:	.int	48
	tab:	.int	0, 1, 2
	len:	.int	.-acoder
	len2:	.int	.-ordre

#idee: pour chaque caractere dans acoder -->je cherche son indice dans ordre--->et je le remplace par le caracter de meme indice dans chaine


.text
.globl main
main:
	movl	$0,%esi #compteur dans acoder

boucle:	
	cmpl	%esi,len
	je	fin
	mov	acoder(,%esi,1),%edx
	movl	$0,%edi  #compteur dans ordre
	#jmp	boucle2

boucle2:
	cmp	%edi,len2
	je	boucle3
	cmp	%edx, ordre(,%edi,1)
	jne	suite
	mov	chaine(,%edi,1),%ebx
	mov	%ebx,acoder(,%esi,1) #compteur dans acoder

boucle3: incl	%esi
	jmp	boucle

suite:	incl	%edi
	jmp	boucle2
	
#affiche: #mov chaine(,%esi,1), %bl
#	 movl	$4,%eax
#	movl	$1,%ebx
#	mov	chaine(,%esi,1),%ecx
#	movl	$1,%edx
#	int	$0x80	
#	incl	%edi
#	incl	%esi
#	jmp	boucle
#suite:	incl	%esi
#	incl	%edi
#	jmp	boucle
fin:	
