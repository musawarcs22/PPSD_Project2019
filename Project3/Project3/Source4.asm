Include C:\Irvine\Irvine32.inc
.data
firstNo byte ?
second1 byte ?

.code

call add

exit
main endp

add proc
mov eax, 32
mov ebx, 45
add eax, ebx

call writeInt
ret
add endp


END main