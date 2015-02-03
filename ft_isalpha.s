section .text

global _ft_isalpha

_ft_isalpha:
	mov r10, rdi

	cmp r10, 65
	jl isnt

	cmp r10, 91
	jl is

	cmp r10, 97
	jl isnt

	cmp r10, 123
	jl is
	jmp isnt

is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
