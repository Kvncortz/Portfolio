# format specifiers = {:flags} format a value based on what
#                               flags are inserted

# .(number)f = round to that many decimal places (fixed point)
# :(number) = allocate that many spaces
# .03 = allocate and zero pad that many spaces
# :< = left justify
# :> = right justify
# :^ = center align
# :+ = use a plus sign to indicate positive value
# := = place sign to leftmost position
# :  = insert a space before positive numbers
# :, = comma separator 

price1 = 3.14159
price2 = -987.65
price3 = 12.34

# print(f"Price 1 is ${price1:.2f}") # make it into a float and round to 2 decimal points
# print(f"Price 2 is ${price2:.2f}") # make it into a float and round to 2 decimal points
# print(f"Price 3 is ${price3:.2f}") # make it into a float and round to 2 decimal points

# print(f"Price 1 is ${price1:10}") # allocates 10 spaces
# print(f"Price 2 is ${price2:10}") # allocates 10 spaces
# print(f"Price 3 is ${price3:10}") # allocates 10 spaces

# print(f"Price 1 is ${price1:010}") # allocates 10 spaces and zero pads
# print(f"Price 2 is ${price2:010}") # allocates 10 spaces and zero pads
# print(f"Price 3 is ${price3:010}") # allocates 10 spaces and zero pads

# print(f"Price 1 is ${price1:<10}") # allocates 10 spaces and left justifies
# print(f"Price 2 is ${price2:<10}") # allocates 10 spaces and left justifies
# print(f"Price 3 is ${price3:<10}") # allocates 10 spaces and left justifies

print(f"Price 1 is ${price1:+}") # Puts a plus in front if number is positive
print(f"Price 2 is ${price2:+}") # allocates 10 spaces and left justifies
print(f"Price 3 is ${price3:+}") # allocates 10 spaces and left justifies
