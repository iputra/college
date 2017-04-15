.model small
.code
org 100h

data:
jmp proses
msg db 219,219,219,219,219,219,219,219,219,'$'

proses:
  mov ah,13h
  mov dl,1
  mov dh,1
  mov bl,00001011b
  mov cx,9
  lea bp,msg
  int 10h
  mov  cx,5
  l1:
    push cx
    mov  cx,10
    l2:
      push cx
      mov cx,9
      lea bp,msg
      int 10h
      pop cx
    loop l2
    pop cx
    mov dl,1
    inc dh
    int 10h
  loop l1
    
int 20h
end data