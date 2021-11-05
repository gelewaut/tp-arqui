GLOBAL sys_read
GLOBAL sys_write
GLOBAL sys_writeAt
GLOBAL sys_clock

section .text
    
;Para pasar argumentos se usan los registros RDI, RSI,
;RDX, R10, R8, R9

; %rbp
; %rsp
; %rbx
; %r12
; %r13
; %r15

%macro pushAsm 0
    push rbp
    push rsp
    push rbx
    push r12
    push r13
    push r15
%endmacro

%macro popAsm 0
    pop r15
    pop r13
    pop r12
    pop rbx
    pop rsp
    pop rbp
%endmacro

sys_read:
    pushAsm
    mov rax, 0
    INT 80h
    popAsm
    ret
sys_write:
    pushAsm
    mov rax, 1
    INT 80h
    popAsm
    ret
sys_writeAt:
    pushAsm
    mov rax, 2
    INT 80h
    popAsm
    ret
