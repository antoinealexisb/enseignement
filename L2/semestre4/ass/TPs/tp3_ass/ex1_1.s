    .data
ch:  .asciz  "Je ne fsuis pfas mofrt0"
car:    .byte   'f'
nb:   .int

    .text
    .globl main
main:
    movl    $0, %eax
    movl    $0, %esi
    movl    $ch, %ecx
    movb    car, %bh
boucle:    
    movb    (%ecx, %esi, 1), %bl
    cmpb    $0, %bl
    je      fin_boucle
    cmpb    %bh, %bl
    je      suivant
    incl    %esi
    jmp     boucle
suivant:
    incl    %eax
    incl    %esi
    jmp     boucle
fin_boucle:
    movl    %eax, nb
