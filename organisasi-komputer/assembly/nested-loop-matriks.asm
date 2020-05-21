.model small
.code
org 100h

data:
jmp proses
msg db 219,'$'

proses:
  mov ah,02h
  mov dl,1
  mov dh,1
  int 10h
  mov  cx,5
  l1:
    push cx
    mov  cx,10
    l2:
      mov ah,02h    
      mov dl,0dbh
      int 21h
    loop l2
    pop cx
    mov dl,1
    inc dh
    int 10h
    loop l1
    
int 20h
end data