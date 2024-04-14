#include <dos.h>
#include <stdio.h>

#define INVISIBLE 0
#define NORMAL 1
#define THICK 2

#define BYTE unsigned char

BYTE SMALL=3;
BYTE BIG=4;

// Global variables created for the correct operation of the functions related to exercises 4, 5, and 6
unsigned char textColor = 7;
unsigned char textBackground = 0;
unsigned char currentVideoMode;

// Helper function to wait for user interaction. If the ESC key is pressed, the program exits.
void waitForKey() {
    union REGS regs;
    regs.h.ah = 0x00;
    int86(0x16, &regs, &regs);
	
	if (regs.h.al == 0x1B) { 
        printf("\nESC key pressed. Exiting the program...\n");
        exit(0);
    }
}

// Exercise 1: Places the cursor at a specified position
void gotoxy(int x, int y) {
    union REGS regs;
    regs.h.ah = 0x02;
    regs.h.dh = y;
    regs.h.dl = x;
    regs.h.bh = 0x00;
    int86(0x10, &regs, &regs);
}

// Exercise 2: Sets the cursor appearance, it must accept three values: INVISIBLE, NORMAL, and THICK.
void setcursortype(int cursor_type) {
    union REGS regs;
    regs.h.ah = 0x01;
    switch(cursor_type) {
        case INVISIBLE:
            regs.h.ch = 0x20;
		break;
        case NORMAL:
            regs.h.ch = 0x06;
            regs.h.cl = 0x07;
            break;
        case THICK:
            regs.h.ch = 0x00;
            regs.h.cl = 0x0B;
            break;
    }
    int86(0x10, &regs, &regs);
}

// Exercise 3: Sets the desired video mode
void setvideomode(BYTE mode) {
    union REGS inregs, outregs;
	 inregs.h.ah = 0;
	 inregs.h.al = mode;
	 int86(0x10,&inregs,&outregs);
	 return;
}

// Exercise 4: Gets the current video mode
unsigned char getvideomode() {
    int mode;
    union REGS inregs, outregs;
    inregs.h.ah = 15;
    int86(0x10, &inregs, &outregs);
    mode = outregs.h.al;
    return mode;
}

// Exercise 5: Changes the foreground color of the characters to be displayed
// It is expected that the user enters the numeric value of the color they want to change to.
void textcolor() {
    unsigned char color;
    printf("\nEnter the color number for the text and press Enter: ");
    scanf("%hhu", &color);
    textColor = color;
}

// Exercise 6: Changes the background color of the characters to be displayed
// It is expected that the user enters the numeric value of the color they want to change to.
void textbackground() {
    unsigned char color;
    printf("\nEnter the color number for the background and press Enter: ");
    scanf("%hhu", &color);
    textBackground = color;
}

// Exercise 7: Clears the entire screen
void clrscr() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

// Exercise 8: Writes a character on the screen with the currently indicated color
void cputchar(char c) {
    union REGS regs;
    regs.h.ah = 0x09;
    regs.h.al = c;
    regs.h.bl = (textBackground << 0x04) | textColor;
    regs.h.bh = 0x00;
    regs.x.cx = 0x01;
    int86(0x10, &regs, &regs);
}

// Exercise 9: Gets a character from the keyboard and displays it on the screen
int getche() {
    union REGS regs;
    regs.h.ah = 0x00;
    int86(0x16, &regs, &regs);
    printf("%c", regs.h.al); // Displays the read character
    return regs.h.al;
}

int main() { 
	printf("\nYou can exit the program by pressing the ESC key. Press any key to continue...");
	waitForKey();
	
	// Exercise 7: 
	printf("\nBy pressing a key you will execute the function of exercise 7. Press another key to execute the next exercise.");
	waitForKey();
	clrscr();
	waitForKey();
	
	// Exercise 8
    printf("\nWriting a character 'A' at the current position | Exercise 8. Press a key to continue...");
	cputchar('A');
    waitForKey();
	
	// Exercise 1
	gotoxy(10, 10);
	cputchar('X');
    printf("\nMoving the cursor to position (10, 10) | Exercise 1. Press a key to continue...");
    waitForKey();
	
	// Exercise 9
    printf("\nReading a character from the keyboard and displaying it on the screen | Exercise 9. Press the letter you want to display...");
    getche();
    
	// Exercise 5
	printf("\nChanging text color | Exercise 5.");
	textcolor();
	cputchar('T');

	// Exercise 6
    printf("\nChanging background color | Exercise 6.");
	textbackground();
    cputchar('F');
	
	// Exercise 3.1
	printf("\nChanging the cursor type | Exercise 3. Press a key to continue...");
	waitForKey();
	setcursortype(INVISIBLE);
	printf("\nChanging the cursor type to INVISIBLE. Press a key to continue...");
    waitForKey();
	
	// Exercise 3.2
    setcursortype(THICK);
	printf("\nChanging the cursor type to THICK. Press a key to continue...");
    waitForKey();
	
	// Exercise 3.3
    setcursortype(NORMAL);
	printf("\nChanging the cursor type to NORMAL. Press a key to continue...");
    waitForKey();
	
	// Exercise 4
    printf("\nSetting the video mode to text | Exercise 4. Press a key to continue...");
    waitForKey();
    setvideomode(BIG);
    printf("\nThe video mode has been changed");
	waitForKey();
	
	// Exercise 2
	printf("\nGetting the new video mode | Exercise 2. Press a key to continue...");
    waitForKey();
    currentVideoMode = getvideomode();
    printf("\nThe new video mode is: 0x%X", currentVideoMode);
	setvideomode(SMALL);
	
	// Exercise 7
	printf("\nClearing the screen. Press a key to continue...");
    waitForKey();
    clrscr();

    return 0;
}
