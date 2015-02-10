; section .text

; global _ft_strlen

; _ft_strlen:
; 	mov r10, 0
; 	cmp rdi, 0
; 	je end
; 	jmp strlen_loop

; strlen_loop:
; 	cmp byte [rdi + r10], 0
; 	je end
; 	inc r10
; 	jmp strlen_loop

; end:
; 	mov rax, r10
; 	ret


section .text
global _ft_strlen

_ft_strlen:
	mov r8, rdi
	mov rax, 0

	cld
	repne scasb

	mov rax, rdi
	sub rax, r8
	dec rax ; caca
	mov rdi, r8
	ret
