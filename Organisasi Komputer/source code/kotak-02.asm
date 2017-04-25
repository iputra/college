.model small
.code
org 100h

data:
  jmp proses
  msg1 db 176,177,178,176,177,178,176,177,178,'$'
  msg2 db 177,178,176,177,178,176,177,178,176,'$'
  msg3 db 178,176,177,178,176,177,178,176,177,'$'

proses:
  mov ah,13h
  mov bh,00
  mov bl,00001011b
  mov dl,1
  mov dh,1
  mov cx,9
  lea bp,msg1
  int 10h

  mov cx,9
  mov dh,2
  lea bp,msg2
  int 10h

  mov cx,9
  mov dh,3
  lea bp,msg3
  int 10h

  mov cx,9
  mov dh,4
  lea bp,msg1
  int 10h

  mov cx,9
  mov dh,5
  lea bp,msg2
  int 10h

  mov cx,9
  mov dh,6
  lea bp,msg3
  int 10h

  mov cx,9
  mov dh,7
  lea bp,msg1
  int 10h

  mov cx,9
  mov dh,8
  lea bp,msg2
  int 10h

  mov cx,9
  mov dh,9
  lea bp,msg3
  int 10h

int 20h
