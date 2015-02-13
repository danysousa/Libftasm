section .text

global _ft_strncat

_ft_strncat:
	xor al, al
	mov r9, rdi

first_loop:
	cmp byte [rdi], 0
	je second_loop

	inc rdi

	jmp first_loop

second_loop:
	cmp byte [rsi], 0
	je end

	cmp rdx, 0
	je end

	mov rax, [rsi]
	mov [rdi], al

	inc rsi
	inc rdi
	dec rdx

	jmp second_loop
end:
	mov byte [rdi], 0
	mov rax, r9
	ret
