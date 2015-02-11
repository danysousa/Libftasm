section .text
global _ft_strlen

_ft_strlen:
	xor al, al

	mov r8, rdi
	mov rax, 0
	mov rcx, 0
	not rcx

	cld
	repne scasb

	mov rax, rdi
	sub rax, r8
	dec rax
	mov rdi, r8
	ret
