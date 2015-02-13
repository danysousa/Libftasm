section .bss

%define BUFF_SIZE 1024

buff: resb BUFF_SIZE

section .text

global _ft_cat

_ft_cat:
	mov r12, rdi
	jmp read

read:
	mov rax, 0x2000003
	mov rdi, r12
	mov rsi, buff
	mov rdx, BUFF_SIZE
	syscall

	jc return

	cmp rax, 0
	jle return

	mov rdx, rax
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, buff
	syscall

	jmp read

return:
	mov rax, 0
	ret
