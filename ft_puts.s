section .text
extern _ft_strlen

global _ft_puts

_ft_puts:
	xor al, al

	cmp rdi, 0
	je nul

	call _ft_strlen
	mov r11, rdi
	mov r12, rax

	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, r11
	mov rdx, r12
	syscall


	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, eol
	mov rdx, 1
	syscall


	ret

nul:
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, null_str
	mov rdx, null_str.len
	syscall
	ret

section .data

eol : db 10
null_str: db "(null)", 10
.len : equ $ - null_str
