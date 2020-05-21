.model small
.code
org 100h

data:
jmp proses:
msg db 'ikhsan$'

proses:
mov ah,02h
mov dl,15
mov dh,15
int 10h
mov cx,10
l1:
  push cx
  l2:  
    mov ah,09h
    mov bl,0001011b
    mov bh,00
    mov cx,55
    int 10h    
  pop cx
  mov ah,02h
  inc dh
  int 10h
  loop l1

mov dl,0ah
mov dh,1
int 10h
  
mov ah,09h
mov dx, offset msg
int 21h
  
int 20h
end data
    