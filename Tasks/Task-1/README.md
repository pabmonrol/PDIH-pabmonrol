# Task 1: Input/Output using interrupts with C language

## Description
The objective of the practice is to learn software interruption programming, understand the interface for accessing input/output resources, and develop a basic I/O function library.

## Exercises

### Minimum Requirements

#### 6.1 *gotoxy(int x, int y)*: Place the cursor at a specific position
Positions the cursor at the specified coordinates (x, y) on the screen. This function is useful for controlling where text or characters are displayed on the screen.

#### 6.2 *setcursortype(int cursor_type)*: To set the appearance of the cursor, it must support three values: INVISIBLE, NORMAL and THICK.
Changes the cursor's appearance based on the given cursor_type, which can be INVISIBLE, NORMAL, or THICK. This allows for customization of the cursor's visibility and shape according to the user's preference or the application's requirements.

#### 6.3 *setvideomode(BYTE mode)*: Set the desired video mode
Sets the video mode to the specified mode. This function enables switching between different video modes (e.g., text mode, graphics mode) supported by the DOS system.

#### 6.4 *getvideomode()*: Gets the current video mode
Returns the current video mode. This function is useful for retrieving the current state of the video mode, which can be helpful for conditional logic based on the video mode or for restoring a previous video mode.

#### 6.5 *textcolor()*: Modifies the foreground color with which the characters will be displayed
Prompts the user to enter a color number for the text and sets the text color to that value. This function enhances the visual aspect of text output by allowing different colors.

#### 6.6 *textbackground()*:Modifies the background color with which the characters will be displayed
This function prompts the user to enter a color number but sets the background color of the text to that value. It provides a way to customize the background color of text for better readability or aesthetic purposes.

#### 6.7 *clrscr()*: Clear the entire screen
Clears the screen by printing a series of newline characters. This simple approach to clearing the screen is used for creating a fresh view or removing previous outputs from the screen.

#### 6.8 *cputchar(char c)*: Writes a character on the screen with the currently indicated color
Writes a single character c to the screen using the currently set text and background colors. This function is essential for displaying characters with specific color attributes.

#### 6.9 *getche()*: Gets a keyboard character and displays it on the screen
Gets a character from the keyboard and displays it immediately on the screen. It combines input reading and output display in a single step, useful for interactive applications.


### Expanded Requirements

#### 7.1

#### 7.2
