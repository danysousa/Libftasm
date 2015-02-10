section .text
global _ft_memset

_ft_memset:
	xor al, al
	mov rcx, rdx
	mov r8, rdi
	mov rax, rsi

	cld
	rep stosb

	mov rax, r8
	ret
