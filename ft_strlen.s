section .text

global _ft_strlen

_ft_strlen:
	mov r10, 0
	cmp rdi, 0
	je end
	jmp strlen_loop

strlen_loop:
	cmp byte [rdi + r10], 0
	je end
	inc r10
	jmp strlen_loop

end:
	mov rax, r10
	ret
