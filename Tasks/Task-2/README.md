# Task 2: Use of programming libraries for text mode user interfaces

## Description
The practice involves using the ncurses programming library to create text-based user interfaces on Unix systems, including developing a "pong" type game.

## Exercises

### Minimum Requirements

#### Install the ncurses library and verify that the provided examples work
The ncurses library is a programming library that provides an API for creating text mode user interfaces. It allows developers to write applications that can interact with the user through a text terminal, providing functions for text manipulation, colors, windows, panels, and more. It is widely used in console applications and Unix-like systems. To work, it uses WSL (Windows Subsystem for Linux).

##### *entrada.py*

![Entrada](/img/Tasks/Task-2/entrada1.png)


![](/img/Tasks/Task-2/entrada1.png)

##### *hello.py*

![](/img/Tasks/Task-2/hello.png)

##### *menu.py*
![](/img/Tasks/Task-2/menu.png)

##### *ventana.py*

![](/img/Tasks/Task-2/ventana1.png)


![](/img/Tasks/Task-2/ventana2.png)

##### Others

![](/img/Tasks/Task-2/p1.gif)

![](/img/Tasks/Task-2/p2.gif)

![](/img/Tasks/Task-2/p3.gif)


#### Create a simple "pong" type game
_Pong_ is a simple two-dimensional sports game that simulates table tennis. Players control paddles on either side of the screen and use them to hit a ball back and forth. The goal is to score points by getting the ball past the opponent's paddle.

![Pong game](/img/Tasks/Task-2/pong_game.png)
![Pong game](/img/Tasks/Task-2/pong_game2.gif)

### Requisitos ampliados

#### Display a welcome screen
Display a welcome screen that shows the information of those who have created the game and explaining the game controls. After a key press, the game will start.

![Welcome screen](/img/Tasks/Task-2/pong_welcome.png)

##### Register the usernames
Display a register screen where users can regiser there usernames.

![Register first user](/img/Tasks/Task-2/pong_user1.png)


![Register second user](/img/Tasks/Task-2/pong_user2.png)


![Register screen](/img/Tasks/Task-2/pong_register.png)

#### Display a summary screen
Display a summary screen showing the final score and congratulating the winner. The option to play again or end the program will be given.

![Game over screen](/img/Tasks/Task-2/pong_gameover.png)
