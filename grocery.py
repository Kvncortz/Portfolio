"""Create a simple grocery list manager where users can:

Add items to the list (item name, quantity).
View all items in the grocery list.
Delete an item from the list.
Update the quantity of an existing item.
Exit the program.

1: Add an item
2: View grocery list
3: Update an item quantity
4: Delete an item
Q: To quit

"""
list = []
action = ""

while not action == "q":
    print ("1: Add an item")
    print ("2: View grocery list")
    print ("3: Update an existing quantity")
    print ("4: Delete an item")
    print ("Q: To quit")

    action = input("What would you like to do? ").lower()

    if action == "1":
        while True:
            name = input("What item would you like to add? ")
            quant = float(input("What is the quantity: "))
            price = float(input("What is the price per item? $"))

            item = {
                "name": name,
                "quant": quant,
                "price": price
            }

            list.append(item)

            another = input("Would you like to add another item? Y/N: ").lower()

            if not another == "y":
                break

    if action == "2":
        for item in list:
            total_price = item["quant"] * item["price"]
            print(f"Name of item: {item['name']} Quantity: {item['quant']} Price: {item['price']} total: ${total_price}")

    
    if action == "3":
        search = input("What item would you like to update: ").lower()
        found = False

        for item in list:
            while True:
                if item["name"].lower() == search:
                    print(f"Name of item: {item['name']} Quantity: {item['quant']} Price: {item['price']} total: ")
                    print("1. Change Name: ")
                    print("2. CHange Quantity: ")
                    print("3. Change Price")
                    print("4. No change") 

                    change_choice = input(("Do you want to change anything? "))
                
                    if change_choice == "1":
                        new_name = input("What would you like the new name to be? ")
                        item['name'] = new_name
                        print(f"Item renamed to {new_name}")

                    if change_choice == "2":
                        new_quant = float(input("What is the new quantity? "))
                        item['quant'] = new_quant
                        print(f"Item quantity changed to {new_quant}")

                    if change_choice == "3":
                        new_price = float(input("What is the new price? $"))
                        item['quant'] = new_price
                        print(f"Item quantity changed to {new_price}")
                
                another_change = input("Would you like to make another change? Y/N: ")
                
                if not another_change == "y":
                    break

    if action == "4":
        search = input("What item would you like to delete: ")
        found = False

        for item in list:
            if item["name"] == search:
                list.remove(item)
                print(f"{search} has been removed")
                found = True
            if not found:
                print("Sorry item not found")
    
    if action == "5":
        print("Thank you have a great day! 😎")

            
        

                    
    
                  
            


                    






