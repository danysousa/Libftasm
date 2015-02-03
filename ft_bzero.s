section .text
global _ft_bzero

_ft_bzero:
	mov r9, 0				; Creation d'un compteur
	mov r10, rdi			; On enregistre le 1er et 2e parametre
	mov r11, rsi
	jmp loop_bzero			; On boucle sur le 1er param

	ret

loop_bzero:
	cmp r9, r11				; si r9 == r11 on return
	je end

	mov dword [r10], 0		; sinon on assigne 0 a la valeur de r10
	add r10, 1				; on incremente le r10 (le pointeur) et r9 (le compteur)
	inc r9
	jmp loop_bzero			; on recommence

end:
	ret
