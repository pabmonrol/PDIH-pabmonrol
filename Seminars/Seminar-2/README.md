# Seminar 2: Accessing I/O Devices in C

## Description
This seminar focuses on the use of input/output interrupts in the **MS-DOS** operating system, emulated in **DOSBox**, through the C language, utilizing the **Borland C** environment.

## Requirements
To run the programs in this repository, you will need:
- DosBox or any other compatible MS-DOS emulator.
- Borland C 3.1 compiler or any version that supports the `dos.h` library.

## Exercises

### 8.1 *video-mode-change.c*
Change the video mode of the system using the BIOS interrupt `0x10`.

![Exercise 1](/img/Seminars/Seminar-2/Ex1.png)

### 8.2 *read-characters.c*
Read characters from the keyboard using interrupts and display the characters read on the screen.

![Exercise 2](/img/Seminars/Seminar-2/Ex2.png)