.386

PUBLIC @equal_int@8
.model flat

.code

@equal_int@8 proc
	; ecx - 1 parameter
	; edx - 2 parameter
	cmp ecx, edx
	je  m_equal
	mov	eax, 0
	jmp m_end
m_equal:
	mov eax, 1

m_end:	
	ret
@equal_int@8 endp

end