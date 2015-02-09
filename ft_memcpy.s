section .text
global _ft_memcpy

_ft_memcpy:
	xor al, al
	mov rcx, rdx
	mov r8, rdi

	cld
	rep movsb

	mov rax, r8
	ret
