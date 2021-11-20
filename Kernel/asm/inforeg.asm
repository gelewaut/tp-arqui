GLOBAL fill_registers
GLOBAL print_ip

GLOBAL return_rax
GLOBAL return_rbx
GLOBAL return_rcx
GLOBAL return_rdx
GLOBAL return_rbp
GLOBAL return_rsp
GLOBAL return_rdi
GLOBAL return_rsi
GLOBAL return_r8
GLOBAL return_r9
GLOBAL return_r10
GLOBAL return_r11
GLOBAL return_r12
GLOBAL return_r13
GLOBAL return_r14
GLOBAL return_r15



EXTERN ncPrintHex
EXTERN ncPrintChar

	; push rax
	; push rbx
	; push rcx
	; push rdx
	; push rbp
	; push rdi
	; push rsi
	; push r8
	; push r9
	; push r10
	; push r11
	; push r12
	; push r13
	; push r14
	; push r15


return_rax:
    ret

return_rbx:
    mov rax, rbx
    ret

return_rcx:
    mov rax, rcx
    ret

return_rdx:
    mov rax, rdx
    ret

return_rbp:
    mov rax, rbp
    ret

return_rsp:
    mov rax, $
    ret

return_rdi:
    mov rax, rdi
    ret

return_rsi:
    mov rax, rsi
    ret

return_r8:
    mov rax, r8
    ret

return_r9:
    mov rax, r9
    ret

return_r10:
    mov rax, r10
    ret

return_r11:
    mov rax, r11
    ret

return_r12:
    mov rax, r12
    ret

return_r13:
    mov rax, r13
    ret

return_r14:
    mov rax, r14
    ret

return_r15:
    mov rax, r15
    ret

fill_registers:
    push rdi
    mov rdi, rax
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar

    mov rdi, rbx
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar

    mov rdi, rcx
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, rdx
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, rbp
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar

    mov rdi, rsp
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    pop rdi  
    call ncPrintHex
    push rdi
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, rsi
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r8
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r9
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r10
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r11
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r12
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r13
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r14
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    mov rdi, r15
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar
    
    pop rdi
    ret

print_ip:
    push rax
    push rdi

    mov rdi, $
    call ncPrintHex
    mov rdi, 32
    call ncPrintChar

    pop rdi 
    pop rax 
    ret