.data
   nbIt: .int 3
   res : .int 0

.text
.global main

main : movl $1,%ecx #compteur
       movl $1,%eax #resultat
       jmp boucle

boucle: cmpl %ecx,nbIt
        jb fin
        addl %ecx,%eax
        addl $1,%ecx
        jmp boucle


fin :
     movl %eax,res

