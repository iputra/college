.model small
.code
org 100h

data:
jmp proses
msg1 db 'Ikhsan Putra Arisandi',13,10,'$'
msg2 db '   Teknik Komputer   ',13,10,09,'  $'        

proses:
    mov ah,09h
    mov dx, offset msg1
    int 21h
    
    mov dx, offset msg2
    int 21h
    
    mov bl,00001101b
    mov bh,00
    mov al,01h
    mov cx,1
    int 10h
    
int 20h
end data