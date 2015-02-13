section .text
global _ft_strncpy

_ft_strncpy:
	xor al, al

	mov rcx, rdx
	mov r8, rdi

	cld
	rep movsb

	mov rax, r8
	ret
