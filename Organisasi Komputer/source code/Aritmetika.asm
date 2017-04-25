.model small 
.code 
org 100h 

;OA: 
;jmp proses
;a dw 10
;b dw 2
;hasil dw ?   ; dw jumlah penampungannya lebih besar dari db, tanda tanya digunakan untuk menyediakan tempat menammpung jawabannya tapi hanya 1 nilai
;sisa dw ?    ; digunakan untuk menampung pembagian. tanda tanya nampung sisanya

;proses: 
;mov ax, a 
;mul b  ; perkalian, b = pengalinya 
;div b  ; pembagian 
;mov hasil, ax
;mov sisa, dx
;int 20h 
;end 0A  

;cara lain 
;proses: 
;mov ax,10
;mov bx,2 
;div bx

;int 20h 
;end 0A

;5*2+3 

;10/2*(5+3)
data:
jmp proses
a dw 10
b dw 2
hasil dw ?
sisa dw ?

proses:
mov ax,a
div b

push ax
mov bl,5
mov bh,3
add bl,bh

pop ax
mul bl



