import math

a = float(input("Enter the length of side a: "))
b = float(input("Enter the length of side b: "))

c = math.sqrt(math.pow(a,2) + math.pow(b,2))

print(f"The hypotenuse of the right triangle where 'A' measures {a} and 'B' measures {b} is {round(c,2)}")