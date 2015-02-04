section .text

global _ft_isdigit

_ft_isdigit:
	mov r10, rdi

	cmp r10, 48
	jl isnt

	cmp r10, 57
	jg isnt

	jmp is
is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
