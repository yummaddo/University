model tiny 
.code
.startup
     mov dx, offset Sos ; встановлюємо вказівник на строку
     mov ah,0Ah 
     int 21h ; введення строки

     mov cx,[bx + 1] ; встановлюємо лічильник
  lst: ; початок циклу   
     mov di,cx
      cmp Sos[di+1],60h ; перевірка, чи літера маленька
      jl next ; якщо літера велика – йдемо далі
      sub Sos[di+1],20h ; якщо маленька – змінюємо її
   next:
      loop lst ; перехід на початок циклу
      mov dx, offset Sos + 2 ; кінець циклу, встановити вказівник на рядок
      mov ah,9
      int 21h ; виведення строки
      ret
   Sos     db 20 dup($) ; змінна-рядок
      end