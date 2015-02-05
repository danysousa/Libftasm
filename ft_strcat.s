section .text

extern _ft_strlen
global _ft_strcat

_ft_strcat:
	call _ft_strlen
	add rdi, rax
	mov r11, 0

strcat_loop:
	cmp byte [rsi + r11], 0
	je end

	mov r12, [rsi + r11]
	mov [rdi + r11], r12
	inc r11

	jmp strcat_loop

end:
	sub rdi, rax
	mov rax, rdi
	ret
