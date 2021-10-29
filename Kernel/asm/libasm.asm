GLOBAL cpuVendor
GLOBAL getRTC

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret


getRTC:
	push rbp
	mov rbp, rsp

	push rbx

	mov al, cl
	out 70h, al
	in ax, 71h

	pop rbx

	mov rsp, rbp
	pop rbp
	ret