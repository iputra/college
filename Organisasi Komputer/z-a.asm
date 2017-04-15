.model small
.code
org 100h

mov cx,1Ah
mov dl,5Ah

proses:   
mov ah,02h
int 21h

ulang:
dec dl
loop proses 

int 20h