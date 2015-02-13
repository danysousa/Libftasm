section .text

global _ft_islower

_ft_islower:
	xor al, al

	mov r10, rdi

	cmp r10, 97
	jl isnt

	cmp r10, 122
	jg isnt

	jmp is

is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
