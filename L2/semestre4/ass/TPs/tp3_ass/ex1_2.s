#affiche un message d'invite
#ch, nb <- lire la chaine donnée par l'utilisateur
#eax <- $ch + nb-1
#i<-nb
#tq i>0 faire
#   affiche le contenu de ch[i-1] (%eax contient $ch l'adresse de ch[i-1])
#   i<-i-1
#fin
#

    .data
prompt:      .ascii  "Votre message :"
len:  .int   .-prompt
ch:   .fill  150,1,' '
nl:   .byte  '\n'

    .text
    .globl main
main:
    movl    $4, %eax
    movl    $1, %ebx
    movl    $prompt, %ecx
    movl    len, %edx
    int     $0x80

    #saisie chaine
    movl    $3, %eax
    movl    $0, %ebx
    movl    $ch, %ecx
    movl    $150, %edx
    int     $0x80
    
    #maintenant %edx contient le nb de caractères
    movl    %edx, %edi  #%edi contient le nb de car à afficher 
    movl    $0, %esi    #%esi est l'adresse de parcours
    movl    $ch, %ecx   #%ecx contient l'adresse du caractère courant
    addl    %edi, %ecx
    decl    %ecx

bcle:
    cmpl    %edi, %esi
    je      sortie 
    #afficher le car courant
    movl    $4, %eax
    movl    $1, %ebx
    movl    $1, %edx
    int     $0x80
    #passer à l'indice suivant
    incl    %esi    #inc l'indice
    decl    %ecx
    jmp     bcle

sortie:
    #afficher un retour à la ligne
    movl    $4, %eax
    movl    $1, %ebx
    movl    $nl, %ecx
    movl    $1, %edx
    int     $0x80
