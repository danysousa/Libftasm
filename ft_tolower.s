section .text

global _ft_tolower

_ft_tolower:
	mov r10, rdi

	cmp r10, 65
	jl quit

	cmp r10, 90
	jg quit

	jmp up

up:
	add r10, 32

quit:
	mov rax, r10
	ret
