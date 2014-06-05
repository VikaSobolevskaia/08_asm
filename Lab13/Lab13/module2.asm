.386
PUBLIC _greater_int
PUBLIC _less_int@8

.model flat

.code
_greater_int proc
	push ebp
	mov ebp,esp
	mov eax,[ebp+8]		; 1 parameter
	mov ebx,[ebp+12]	; 2 parameter
	
	cmp eax, ebx
	jg  m_greater
	mov eax, 0
	jmp m_end
m_greater:
	mov	eax, 1

m_end:
	pop ebp
	ret
_greater_int endp

_less_int@8 proc
	push ebp
	mov ebp,esp
	mov eax,[ebp+8]		; 1 parameter
	mov ebx,[ebp+12]	; 2 parameter
	
	cmp eax, ebx
	jl  m_less
	mov eax, 0
	jmp m_end1
m_less:
	mov	eax, 1

m_end1:
	pop ebp
	ret 8
_less_int@8 endp

end