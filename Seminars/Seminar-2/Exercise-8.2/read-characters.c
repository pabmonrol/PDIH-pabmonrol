#include <dos.h>
#include <stdio.h>

int main() {
    union REGS inregs, outregs;
    char key;

    // Loop stop when user press ESC
    do {
        inregs.h.ah = 0x00;
		
		// Read keyboard
        int86(0x16, &inregs, &outregs);  
		
		// Get the pushed characters
        key = outregs.h.al;             

        // Show key on screen
        inregs.h.ah = 0x0E;
        inregs.h.al = key;
        int86(0x10, &inregs, &inregs);  

    }
	
	// 27 = ESC in ASCII
	while (key != 27);  

    return 0;
}
