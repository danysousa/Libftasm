section .text
extern _ft_strlen
extern _malloc
extern _ft_memcpy

global _ft_strdup

_ft_strdup:
	xor al, al
	mov r13, rdi

	call _ft_strlen
	mov rdi, rax
	inc rdi
	mov r14, rax

	call _malloc
	test rax, rax
	je return

	mov rdi, rax
	mov rsi, r13
	mov rcx, r14
	cld
	rep movsb

	mov rax, r13
	ret

return:
	ret
