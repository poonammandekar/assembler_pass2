section .data
	msg db "addition is %d",10,0
	num1 dd 20,30,40,50
	22num2 dd 30
	m dd 10
section .bss
	1n resw 13
	a resb 20
	m resd 4
section .text
	global main
	extern printf
	mov ecx,dword[num1]
	mov ebx,dword[num2]
	add1 ecx,ebx
	push ecx
	push msg
	call printf
	add esp,8
        jmp end
1end:
        ret
