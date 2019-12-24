
.data
firstNo REAL4 ?
second1 REAL4 ?

firs2 qword ?
sec2 qword ?


dis byte "Input 1 for Decimal or 2 for Floating point: ",0
dis1 byte "Result of Decimal is : ",0
dis3 byte "Enter first number: ",0
dis4 byte "Enter Second Number: ",0

Decimalq PROTO, firs2:qword,sec2:qword
floatingCalulation PROTO, first:REAL4,second:REAL4

.code
main PROC

mov edx,offset dis
call writeString
call readInt
cmp eax,1
je l1

mov edx, offset dis3
call writeString

call readFloat
mov firstNo,eax
mov edx, offset dis4
call writeString
call readFloat
mov second1, eax
invoke floatingCalulation,firstNo,second1
ret


l1:
l3:
mov edx, offset dis3
call writeString
call readInt
mov firs2, rax

mov edx, offset dis4
call writeString
call readInt
mov sec2, rax
invoke decimalq,firs2,sec2
ret

exit
main ENDP

floatingCalulation proc ,
first:REAL4,
second:REAL4,


finit
fld first
fimul second
call showFpuStack
ret
floatingCalulation endp

decimalq proc ,
first:qword,
second:qword,


mov rax, first
mov rbx, second
mul rbx
mov rdx, offset dis1
call writeString
call writeInt



ret
decimalq endp

END main
