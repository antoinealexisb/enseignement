#str_to_int(n):
#   res = 0
#   i = 0
#   tq i > 0 faire
#       res *= 10
#       res += n[i]
#       i--

#
#
#
#
#
#
#


    .data
prompt: .ascii  "Votre entier : "
len:    .int    .-prompt
ch:     .fill  15,1,' '
n:      .byte   '\n'
nbcar:  .int

    .text
    .globl main
main:
    #affichage prompt
    movl    $4, %eax
    movl    $1, %ebx
    movl    $prompt, %ecx
    movl    len, %edx
    int     $0x80
    #input
    movl    $3, %eax
    movl    $0, %ebx
    movl    $ch, %ecx
    movl    $15, %edx
    int     $0x80

apres: #%edx contient le nb de carac
    movl    $0, %esi #indice du carac courant
    movl    $0, %eax
    movl    $10, %ebx
    movl    %edx, nbcar
    
bcle: #IL MANQUE DES TRUCS
    cmpl    nbcar, %esi #tant que %esi < nbcar on continue = si esi >= nbcar, on sort
    jae     sortie
    movl    $0, %ebx
    movb    (%ecx,%esi,1), %bl  #%ebx contient la valeur du caractère courant
    subb    $48, %bl            #%ebx contient la valeur de l'entier qui correspondant
    mull    %edi
    addl    %ebx, %eax          #%ebx contient la valeur de l'entier qui correspond à tous les carac lus
    incl    %esi
    jmp     bcle
    
sortie:
    movl    $1, %eax
    movl    $0, %ebx
    int     $0x80
