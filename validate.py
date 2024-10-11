"""username = input("Enter a username: ")
result = username.isalpha()
length = len(username)

if result == False or length > 12:
   print("Please enter a valid username, it cannot contain spaces or digits")

else:
    print(f"Welcome {username}!")
"""

username = input("Enter a username: ")

if len(username) > 12:
    print("Invalid username, can't be more than 12 characters")

elif not username.find(" ") == -1:
    print("Invalid username, can't have any spaces")
elif not username.isalpha():
    print("Invalid username, can't contain numbers")
else:
    print(f"Welcome to the club {username}!")