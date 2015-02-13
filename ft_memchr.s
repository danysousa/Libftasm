section .text

global _ft_memchr

_ft_memchr:
	xor al, al

	mov r10, rdi

	jmp search

search:
	cmp rdx, 0
	je isnt

	cmp byte [rdi], sil
	je is

	inc rdi
	dec rdx

	jmp search
is:
	mov rax, rdi
	mov rdi, r10
	ret

isnt:
	mov rdi, r10
	mov rax, 0
	ret
