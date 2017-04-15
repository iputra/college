.model small
.code
org 100h

data:
jmp proses
msg1 DB 'Ikhsan Putra Arisandi',13,10,'$'
msg2 DB 'J3D116069',13,10,'$'

proses:
mov ah,09h
mov dx, offset msg1
int 21h

lea dx,msg2
int 21h

int 20h
end proses