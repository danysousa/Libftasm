section .text

global _ft_isprint

_ft_isprint:
	mov r10, rdi

	cmp r10, 32
	jl isnt

	cmp r10, 126
	jg isnt

	jmp is
is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
