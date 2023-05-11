    .globl myFunc, main

main:
    pushq %rbp
    movq %rsp, %rbp

    movl $42, %edi
    call myFunc

    movl $0, %eax
    leave
    ret
