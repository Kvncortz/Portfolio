contacts = []
choice = ""

while not choice == "q":
    print("1: Add a contact")
    print("2: View your entire contact list")
    print("3: Find a name by phone number")
    print("4: Find a phone number by name")
    print("Q: To Quit")

    choice = input("What would you like to do? ").lower()

    if choice == "1":
        while True:
            print("Add a Contact")
            name = input("Enter the name of the Contact: ")
            phone = input("Enter the number of the contact xxx-xxx-xxxx: ")

            contact = {
            "name": name,
            "phone": phone
             }
            print(f"{contact['name']} has been added")
            contacts.append(contact)

            another = input("Would you like to add another contact Y/N: ").lower()

            if not another == "y":
                break

    if choice == "2":
        for contact in contacts:
            print("Your Contact Book:")
            print(f"Name: {contact['name']}, Phone#: {contact['phone']}")
    
    if choice == "3":
        number = input("Enter the number you would like to search for: " )
        found = False
        number = number.replace("-", "")

        for contact in contacts:
            if contact["phone"] == number:
                print(f"Name: {contact['name']}")
                found = True
                break
        if not found:
            print("Sorry, no contact found with that number")
    
    if choice == "4":
        name_lookup = input("Enter the name you would like to search for: " ).lower()
        found = False

        for contact in contacts:
            if contact["name"] == name_lookup:
                print(f"Phone#: {contact['phone']}")
                found = True
                break
        if not found:
            print("Sorry, no number found with that name")