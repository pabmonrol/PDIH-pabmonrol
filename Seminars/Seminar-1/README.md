# Seminar 1: Low-Level Device Programming

## Description
This project includes the source code files for an assembler program that executes a "Hello World" and a variant that prints the message seven times in a loop. This delivery was made using **DOSBox** to emulate the MS-DOS environment and the **Turbo Assembler** and **Turbo Linker** tools to compile the code in C.

## DOSBox Installation and Configuration
DOSBox was installed and configured to emulate an MS-DOS environment, following the steps in section 5 *Emulating MS-DOS with DOSBox* of the [guide](./S1-Guide.pdf).
![Set the keyboard to Spanish and mount the folder with all the necessary software on the C: drive](/img/Seminars/Seminar-1/mod2.png)
![Change the terminal resolution](/img/Seminars/Seminar-1/mod1.png)

## Compilation Environment
To simplify the program compilation, a .BAT script is created that receives the name of the program to compile [c.bat](./holax7.asm).

## Exercises

### 7.1 Game
Run MS-DOS applications, such as the game _VBALL_.
![Assembler program displaying the string _hello_](/img/Seminars/Seminar-1/game.png)

### 7.2 Hola
Assembler program that displays the string "Hola Mundo" on the screen.

- Source code: [hola.asm](./Exercise 7.1/hola.asm)
- Compilation command: `c hola`
- Execution command: `hola`

![Assembler program displaying the string _hello_](/img/Seminars/Seminar-1/hola.png)

### 7.3 Hola with Loop
The `hola.asm` program was modified to print the string "Hola Mundo" seven times, using a loop controlled by the CX register.

- Modified source code: [holax5.asm](./Exercise 7.2/holax7.asm)
- Compilation command: `c holax7`
- Execution command: `holax7`

![Assembler program displaying the string _hello_ 7 times](/img/Seminars/Seminar-1/holax7.png)
