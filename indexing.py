# indexing = accessing elements of a sequence using [] (indexing operations)
#           [start : end: step]

credit_number = "1234-5678-9012-3456"

#print(credit_number[0]) # start position is inclusive

# print(credit_number[0:4]) # 4 is exclusive and does not include the "-"

# print(credit_number[5:9])

# print(credit_number[5:])

# print(credit_number[-1]) # going from the end

# print(credit_number[::2]) # will print every second number

# last_digits = credit_number[-4:]

credit_number = credit_number[::-1]

print(f"The credit card number reversed is {credit_number}")

