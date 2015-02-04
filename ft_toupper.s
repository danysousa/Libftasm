section .text

global _ft_toupper

_ft_toupper:
	mov r10, rdi

	cmp r10, 97
	jl quit

	cmp r10, 122
	jg quit

	jmp up

up:
	sub r10, 32

quit:
	mov rax, r10
	ret
