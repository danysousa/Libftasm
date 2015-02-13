section .text
global _ft_strcpy
extern _ft_strlen


_ft_strcpy:
	xor al, al

	mov r9, rdi
	mov r10, rsi

	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax
	mov rdi, r9
	mov rsi, r10
	cld
	rep movsb

	mov rax, r9
	ret
