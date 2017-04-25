.model small
.code
org 100h

data: 
jmp proses
border db '----------------------------------------',13,10,'$' 
sprtor db '|$'
newlne db 13,10,'$'
no1 db '|  1 |$'
no2 db '|  2 |$'
header db '| NO |        NAMA           |   NIM   |',13,10,'$'
nama1 db ' Ikhsan Putra Arisandi $'
nama2 db ' Ilham Taufik Arisandi $'
nim1 db 'J3D116069$'
nim2 db 'J3D116070$'

proses:
mov ah,09h
lea dx,border
int 21h

lea dx,header
int 21h

lea dx,border
int 21h

mov ah,09h
lea dx,no1
int 21h

mov bh,00
mov bl,00001100b
mov cx,22
int 10h

lea dx,nama1
int 21h

lea dx, sprtor
int 21h

mov bl,00001011b
mov cx,9
int 10h 

lea dx,nim1
int 21h

lea dx,sprtor
int 21h 

lea dx,newlne
int 21h

lea dx,border
int 21h

lea dx,no2
int 21h

mov bl,00001100b
mov cx,22
int 10h

lea dx,nama2
int 21h

lea dx,sprtor
int 21h

mov bl,00001011b
mov cx,9
int 10h

lea dx,nim2
int 21h

lea dx,sprtor
int 21h

lea dx,newlne
int 21h

lea dx,border
int 21h


int 20h
end proses
