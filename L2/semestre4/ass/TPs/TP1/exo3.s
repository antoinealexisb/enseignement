.data
    nb1 : .int 4
    nb2 : .int 2
    res : .int 0

.text
.global main

main:
    movl 5,%eax
    movl 2,%ebx
    jmp for

for : cmpl %eax,%ebx
      je fin
      cmpl %eax,%ebx
      ja addnb1
      cmpl %eax,%ebx
      jb addnb2
      jmp for

addnb1 : addl nb1,%eax
         jmp for

addnb2: addl nb2,%ebx
        jmp for

fin : movl %eax, res




2       4       6       6       8       10

5       5       5       10      10      10

