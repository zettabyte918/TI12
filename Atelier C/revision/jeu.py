import random

count_of_guesses = 0
correct_number = random.randint(0, 20)

while count_of_guesses <= 10:
    user_guess = int(input("Guess: "))
    count_of_guesses += 1

    if user_guess < correct_number:
        print("you guessed too low")
    elif user_guess > correct_number:
        print("you guessed too high")
    else:
        print("you guessed correct!")
        break
else:
    print("Sorry you lost the game")