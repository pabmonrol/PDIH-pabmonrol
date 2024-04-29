#include <dos.h>
#include <stdio.h>

int main() {
    union REGS regs;

    // Cambiar al modo de video 0x13
    regs.h.ah = 0x00;
    regs.h.al = 0x13;
	
	// Interrupcion de video
    int86(0x10, &regs, &regs);

    printf("Modo de video cambiado a 0x13");
	printf("\n");
    
    return 0;
}
