"""Create a number guessing game where:

The program randomly selects a number between 1 and 50.
The user has to guess the number.
If the guess is too high or too low, the program provides a hint.
The game continues until the user guesses the correct number.
After the user guesses correctly, the program asks if they want to play again.
Features to include:

Use a while loop to keep the game running until the user guesses correctly.
Use an if statement to compare the user’s guess to the correct number and provide feedback.
Use another while loop after the game finishes to ask if the user wants to play again."""


import random

while True:
    number = random.randint(0,50)
    guess = 0
    while True:
        guess = int(input("What is your guess: "))
        #print(guess)

        if guess > number:
            print("You are a little high, try again")
        
        if guess < number:
            print("You are a little low, try again")

        if guess == number:
            print("Congrats you guessed correctly!!")
            another = input("Would you like to play again? Y/N: ").lower()

            if another == "y":
                break
            else:
                print("Thank you for playing!")
                exit()
    



