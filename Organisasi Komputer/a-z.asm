.model small
.code
org 100h

mov cx,1Ah
mov dl,41h

proses:   
mov ah,02h
int 21h

ulang:
inc dl
loop proses 

int 20h

