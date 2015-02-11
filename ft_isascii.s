section .text

global _ft_isascii

_ft_isascii:
	xor al, al

	mov r10, rdi

	cmp r10, 0
	jl isnt

	cmp r10, 127
	jg isnt

	jmp is

is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
