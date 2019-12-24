Include C:\Irvine\Irvine32.inc
.data
firstNo REAL4 ?
second1 REAL4 ?
firs dword ?
sec dword ?
firs1 word ?
sec1 word ?


vr dword ?




dis byte "Input 1 for Decimal or 2 for Floating point: ",0
dis5 byte "Press 1 for 16bit || press 2 for 32bit: ",0
dis1 byte "Result of Decimal is : ",0
dis3 byte "Enter first number: ",0
dis4 byte "Enter Second Number: ",0


DecimalCalculation PROTO, first:dword,second:dword

Decimalsix PROTO, firs1:word,sec1:word



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

mov edx, offset dis5
call writeString
call readInt
cmp eax,1
je l2



mov edx, offset dis3
call writeString
call readInt
mov firs,eax

mov edx, offset dis4
call writeString
call readInt
mov sec,eax
invoke decimalCalculation,firs,sec

l2:
mov edx, offset dis3
call writeString
call readInt
mov firs,eax
mov ax, word ptr firs
mov firs1, ax

mov edx, offset dis4
call writeString
call readInt
mov sec,eax
mov ax, word ptr sec
mov sec1, ax
invoke decimalsix,firs1,sec1





















exit
main ENDP


floatingCalulation proc ,
first:REAL4,
second:REAL4,
finit

call showFpuStack
fld first
fimul second
call showFpuStack
ret
floatingCalulation endp

decimalCalculation proc ,
first:dword,
second:dword,

mov eax, first
mov ebx, second
mul ebx
mov edx, offset dis1
call writeString
call writeInt



ret
decimalCalculation endp



decimalsix proc ,
first:word,
second:word,

mov eax, 0
mov ax, first
mov bx, second
mul bx
mov edx, offset dis1
call writeString
call writeInt



ret
decimalsix endp

















END main