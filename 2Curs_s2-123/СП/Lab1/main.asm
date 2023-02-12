model small
.data
tm  db 255,255,255 dup("$")
testm   db "Entered string: $"
.code
main proc
    mov ax,@data
    mov ds,ax
    mov dx,offset tm
    mov ah,0ah
    int 21h
    mov dx,offset testm
    mov ah,09h
    int 21h
    mov dx,offset tm
    add dx,2h
    mov ah,09
    int 21h
main endp
end main
code ends