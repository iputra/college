.model small
.code
org 100h

inis:
jmp proses
msg1 db '*','$'
proses:
mov ah,13h
mov bh,00h
mov bl,00001010b
mov dh,00h
mov dl,05h
mov cx,01h
mov bp,offset msg1
int 10h

attr1:
mov dh,01h
mov dl,04h
mov cx,03h
int 10h

ctk1:
mov ah,09h
mov cx,03h
lea dx,msg1

ulang1:
int 21h
loop ulang1

attr2:
mov ah,13h
mov dh,02h
mov dl,03h
mov cx,05h
int 10h

ctk2:
mov ah,09h
mov cx,05h
lea dx,msg1

ulang2:
int 21h
loop ulang2

attr3:
mov ah,13h
mov dh,03h
mov dl,02h
mov cx,07h
int 10h

ctk3:
mov ah,09h
mov cx,07h
lea dx,msg1

ulang3:
int 21h
loop ulang3

attr4:
mov ah,13h
mov cx,07h
mov dl,02h
mov dh,04h
int 10h

ctk4:
mov ah,09h
mov cx,07h
lea dx,msg1

ulang4:
int 21h
loop ulang4

attr5:
mov ah,13h
mov cx,07h
mov dl,02h
mov dh,05h
int 10h

ctk5:
mov ah,09h
mov cx,07h
lea dx,msg1

ulang5:
int 21h
loop ulang5

attr6:
mov ah,13h
mov cx,07h
mov dl,02h
mov dh,06h
int 10h

ctk6:
mov ah,09h
mov cx,07h
lea dx,msg1

ulang6:
int 21h
loop ulang6

attr7:
mov ah,13h
mov cx,07h
mov dl,02h
mov dh,07h
int 10h

ctk7:
mov ah,09h
mov cx,07h
lea dx,msg1

ulang7:
int 21h
loop ulang7

int 20h