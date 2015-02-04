section .text
extern _ft_strlen

global _ft_puts

_ft_puts:
	call _ft_strlen
	mov r10, rdi
	mov r11, rax

	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, r10
	mov rdx, r11
	syscall
	ret
