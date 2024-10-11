# conditional expression = A one-line shortcut for the if-else statement (ternary operator)
#                          print or assign one of two values based on a condition
#                          X if condition else Y

num = -5
a = 6
b = 7
age = 16
user_role = "admin"

# print("Positive" if num > 0 else "Negative")
# result = "Even" if num % 2 == 0 else "Odd"
# max_num = a if a > b else b
# min_num = a if a < b else b
# status = "Adult" if age > 18 else "child"
access_level = "Full Access" if user_role == "admin" else "Limited Access"

print(access_level)