import curses
from time import sleep

# Set the initial usernames
user1 = ""
user2 = ""

# Make paddles & check limits (solving problems with window boundaries)
def draw_paddle(screen, paddle_y, paddle_x, paddle_height, symbol):
    max_y, max_x = screen.getmaxyx()
    for i in range(paddle_height):
        pos_y = paddle_y + i - paddle_height // 2
        # Ensure the y position is within the window boundary before adding the string
        if 0 <= pos_y < max_y and 0 <= paddle_x < max_x:
            try:
                screen.addstr(pos_y, paddle_x, symbol)
            except curses.error:
                # To handle any additional curses errors that may occur
                pass

# Welcome screen & game info
def display_welcome_screen(screen):
    screen.clear()
    screen.addstr(5, 5, "Welcome to Pong!", curses.A_BOLD)
    screen.addstr(7, 5, "Developed by: Pablo Montero")
    screen.addstr(9, 5, "Controls:")
    screen.addstr(10, 7, "Left Paddle - 'W' up, 'S' down")
    screen.addstr(11, 7, "Right Paddle - ↑ (up arrow), ↓(down arrow)")
    screen.addstr(13, 5, "Press any key", curses.A_ITALIC)
    screen.addstr(19, 5, "Press 'M' to finish the play")
    screen.refresh()
    screen.getch()

# Insert usernames screen
def display_users_screen(screen):
    # Use the global variables to store the usernames
    global user1, user2
    screen.clear()
    screen.addstr(5, 5, "Set your usernames")
    screen.addstr(7, 5, "Left Player: ")
    
    # Enable echoing to display user input
    curses.echo()
    user1 = screen.getstr(7, 20, 20).decode('utf-8')
    
    # Disable echoing to hide user input
    curses.noecho()
    screen.addstr(7, 20, user1)
    screen.addstr(8, 5, "Right Player: ")
    curses.echo()
    user2 = screen.getstr(8, 20, 20).decode('utf-8')
    curses.noecho()
    screen.addstr(8, 20, user2)
    screen.addstr(13, 5, "Press any key to start!", curses.A_ITALIC)
    screen.refresh()
    screen.getch()

# Game over screen
def display_game_over_screen(screen, left_score, right_score):
    global user1, user2
    screen.clear()
    screen.addstr(5, 5, "Game Over!", curses.A_BOLD)
    # Display the final score of the game
    screen.addstr(7, 5, f"Final Score: {user1} {left_score} - {user2} {right_score}")
    # Determine the winner of the game
    winner = f"{user1}" if left_score > right_score else f"{user2}"
    # Display the winner of the game
    screen.addstr(9, 5, f"{winner} wins! Congratulations!", curses.A_BOLD)
    screen.addstr(14, 5, "Press 'R' to play again or 'Q' to quit.", curses.A_ITALIC)
    screen.refresh()
    res = screen.getch()
    curses.echo()
    return res

def main(screen):
    curses.curs_set(0)
    screen.keypad(1)

    while True:
        display_welcome_screen(screen)
        display_users_screen(screen)
        screen.nodelay(1)
        
        # Adjusted the maximum score of the game
        max_point = 10

        # Adjusted the height and width of the screen
        height, width = 24, 80
        screen.resize(height, width)
        height, width = screen.getmaxyx()
        
        # Adjusted the initial position of the ball
        ball_x, ball_y = width // 2, height // 2
        
        # Adjusted the initial direction of the ball
        ball_dir_x, ball_dir_y = 1, -1
        
        # Adjusted the initial position of the paddles
        left_paddle_y = right_paddle_y = height // 2
        paddle_height = 5
        left_paddle_x, right_paddle_x = 1, width - 2
        
        # Adjusted the initial score of the game
        left_score, right_score = 0, 0

        while left_score < max_point and right_score < max_point:
            screen.clear()
            # Draw the paddles and ball
            draw_paddle(screen, left_paddle_y, left_paddle_x, paddle_height, '|')
            draw_paddle(screen, right_paddle_y, right_paddle_x, paddle_height, '|')
            screen.addstr(ball_y, ball_x, 'o')
            # Display the score of the game
            screen.addstr(1, width // 2 - 5, f"Score: {left_score} - {right_score}")
            screen.refresh()
            sleep(0.05)
            
            # Adjusted the next position of the ball
            next_x, next_y = ball_x + ball_dir_x, ball_y + ball_dir_y

            # To change the direction of the ball when it hits the paddles
            if (next_x >= right_paddle_x - 1 and right_paddle_y - paddle_height // 2 <= next_y <= right_paddle_y + paddle_height // 2):
                ball_dir_x *= -1
            elif (next_x <= left_paddle_x + 1 and left_paddle_y - paddle_height // 2 <= next_y <= left_paddle_y + paddle_height // 2):
                ball_dir_x *= -1
            elif next_y >= height - 1 or next_y < 1:
                ball_dir_y *= -1

            # To increase the score of the game when the ball hits the left or right wall & reset the ball position
            if next_x >= width - 1:
                left_score += 1
                next_x, next_y = width // 2, height // 2
            elif next_x < 1:
                right_score += 1
                next_x, next_y = width // 2, height // 2            

            # Update the position of the ball
            ball_x, ball_y = next_x, next_y
            
            # Deploy the game over screen when the use types 'm'
            user_input = screen.getch()
            if user_input == ord('m'):
                display_game_over_screen(screen, left_score, right_score)
                sleep(2)
                break
            
            # To move the paddles
            if user_input == curses.KEY_UP and right_paddle_y > paddle_height // 2:
                right_paddle_y -= 1
            elif user_input == curses.KEY_DOWN and right_paddle_y < height - paddle_height // 2:
                right_paddle_y += 1
            elif user_input == ord('w') and left_paddle_y > paddle_height // 2:
                left_paddle_y -= 1
            elif user_input == ord('s') and left_paddle_y < height - paddle_height // 2:
                left_paddle_y += 1
                
        # Deploy the game over screen when the game ends
        user_input = display_game_over_screen(screen, left_score, right_score)
        if user_input == ord('q'):
            break  # Exit the game
        elif user_input == ord('r'):
            left_score = 0
            right_score = 0
            # Skip all the remaining code in the current iteration and return to the beginning in case there are still iterations to complete.
            continue    

    curses.endwin()

if __name__ == "__main__":
    curses.wrapper(main)