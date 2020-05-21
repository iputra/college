.model small
.code
org 100h

data:
  jmp proses
  msg db 176,177,178,176,177,178,176,177,178,'$'
  
proses:
  mov ah,13h
  mov bh,00
  mov bl,10111011b
  mov dl,1
  mov dh,1
  mov cx,9
  int 10h
 
  mov dh,2
  int 10h
  
  mov dh,3
  int 10h
  
  mov dh,4
  int 10h
  
  mov dh,5
  int 10h
  
  mov dh,6
  int 10h 
  
  mov dh,7
  int 10h
  
  mov dh,8
  int 10h
  
int 20h
end data