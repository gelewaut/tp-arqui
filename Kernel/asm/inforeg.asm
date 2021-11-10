GLOBAL fill_registers
GLOBAL print_ip
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