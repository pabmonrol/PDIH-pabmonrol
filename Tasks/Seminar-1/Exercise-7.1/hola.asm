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
		mov dx,OFFSET msg ; mostrar por pantalla una cadena de texto
		mov ah,9
		int 21h
		mov ax,4C00h ; terminar y salir al S.O.
		int 21h
	main ENDP
codigo ends

END main