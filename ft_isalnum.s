extern _ft_isdigit
extern _ft_isalpha
section .text


global _ft_isalnum

_ft_isalnum:
	call _ft_isdigit
	cmp rax, 1
	je is

	call _ft_isalpha
	cmp rax, 1
	je is

	jmp isnt

is:
	mov rax, 1
	ret

isnt:
	mov rax, 0
	ret
