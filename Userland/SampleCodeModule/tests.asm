GLOBAL divByZero
GLOBAL opCodeTest

section .text

divByZero:
    mov dx,0
    mov ax, 1
    mov cx, 0
    div cx
    ret

opCodeTest:
    UD2
    ret