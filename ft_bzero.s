section .text
global _ft_bzero

_ft_bzero:
	xor al, al

	mov r9, 0
	jmp loop_bzero

loop_bzero:
	cmp r9, rsi
	je end

	mov byte [rdi + r9], 0
	inc r9
	jmp loop_bzero

end:
	ret
