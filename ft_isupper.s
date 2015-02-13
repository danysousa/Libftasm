section .text

global _ft_isupper

_ft_isupper:
	xor al, al

	mov r10, rdi

	cmp r10, 65
	jl isnt

	cmp r10, 90
	jg isnt

	jmp is

is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
