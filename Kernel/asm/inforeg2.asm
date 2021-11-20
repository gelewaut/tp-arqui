GLOBAL _saveReg
EXTERN saveIp
EXTERN saveReg
EXTERN saveRsp
_saveReg:
   	push r15
	push r14
	push r13
	push r12
	push r11
	push r10
	push r9
	push r8
	push rsi
	push rdi
	push rbp
	push rdx
	push rcx
	push rbx
	push rax

	mov rdi, [rsp+120]
    call saveIp

    lea rdi, [rsp+120]
    call saveRsp

    mov rbx, 0
	mov rcx, rsp
	add rcx, 8
	nextReg:
	push rcx
	mov rdi, rbx
	; call printRegName
	; pop rcx
	; push rcx
	mov rsi, [rcx]
	call saveReg
	pop rcx
	add rcx, 8
	inc rbx
	cmp rbx, 15
	jne nextReg
	
	pop rax
	pop rbx
	pop rcx
	pop rdx
	pop rbp
	pop rdi
	pop rsi
	pop r8
	pop r9
	pop r10
	pop r11
	pop r12
	pop r13
	pop r14
	pop r15
    ret