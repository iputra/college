.model small
.code
org 100h

data:
jmp proses
border db 219,219,219,219,219,'$'

proses:
mov ah,09h
mov bl,00001011b
mov bh,00
mov cx,msglend - offset border
int 10h 

mov dx,offset border
int 21h

msglend:  

int 20h
end data