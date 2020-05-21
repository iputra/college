SECTION .data
	msg: db "Telolet", 10
	msg2: db "Om ",10
	len: equ $-msg
SECTION .text
global _start
_start:
mov eax, 0
jmp forLoop
forLoop:
	cmp eax, 3
	je finished
	cmp eax, 1
	je tol
	cmp eax, 1
	jg om
om:
	push eax
	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, 2
	int 0x80
pop eax
add eax, 1
jmp forLoop
tol:
	push eax
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, 7
	int 0x80
pop eax
add eax, 1
jmp forLoop	
finished:
mov eax, 1
mov ebx, 0
int 0x80
