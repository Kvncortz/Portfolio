# while loop = execute some code WHILE some condition remains true

"""age = int(input("enter your age: "))

while age < 0:
    print("Age cannot be negative")
    age = int(input("enter your age: "))

print(f"You are {age} years old")"""

"""food = input("Enter your favorite food: (q to quit): ")

while not food == "q":
    print(f"you like {food}")
    food = input("Enter your favorite food: (q to quit): ")

print("bye")"""

number = int(input("Enter a number between 1 - 10: "))

while number < 1 or number > 10:
    print(f"{number} is not valid")
    number = int(input("Enter a number between 1 - 10: "))

print(f"Your number is {number}")