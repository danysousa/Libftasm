section .text
extern _ft_isascii

global _ft_isdigit

_ft_isdigit:
	xor al, al

	call _ft_isascii
	cmp rax, 0
	je isnt

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
