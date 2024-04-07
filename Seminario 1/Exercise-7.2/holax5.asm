pila segment stack 'stack'
	dw 100h dup (?)
pila ends
datos segment 'data'
	msg db 'Hola Mundo$'
datos ends
codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax
		;imprimir N veces una cadena
		mov cx,0
		bucle:
			mov dx,OFFSET msg
			mov ah,9
			int 21h
			;actualizar contador y comprobar condición
			inc cx
			cmp cx,7
			jne bucle
	main ENDP
codigo ends

END main