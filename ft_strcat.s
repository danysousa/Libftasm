section .text

extern _ft_strlen
global _ft_strcat

_ft_strcat:
	cmp rsi, 0
	je end

	mov r10, 0
	mov r11, 0

first_loop:
	cmp byte [rdi + r10], 0
	je second_loop

	inc r10

	jmp first_loop

second_loop:
	cmp byte [rsi + r11], 0
	je end

	mov r12, [rsi + r11]
	mov [rdi + r10], r12
	inc r10
	inc r11

	jmp second_loop
end:
	mov byte [rdi + r10], 0
	mov rax, rdi
	ret
