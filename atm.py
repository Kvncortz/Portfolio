"""Create a simple ATM simulation where users can:

Check their balance.
Deposit money.
Withdraw money.
Exit the ATM.
Features:

Start the user with a balance of $1000.
Display a menu to let the user choose one of the above actions.
For withdrawals, ensure that the user doesn't withdraw more than their current balance.
After every action, return to the main menu until the user chooses to exit."""

print ("Welcome to Cortez Bank")
action = ""
balance = 0
deposit = 0
withdraw = 0

while not action == "q":
        print("1. Check your balance")
        print("2. Deposit money")
        print("3. Withdraw money")
        print("Q. To exit")

        choice = input("What would you like to do? ").lower()
      
        if choice == "1":
            print(f"Your balance is ${balance}")

        elif choice == "2":
            deposit = float(input("How much would you like to deposit? $"))
            balance += deposit
            print(f"You deposited ${deposit}")
            print(f"Your new balance is ${balance}")
        
        elif choice == "3":
            withdraw = float(input("How much money would you like to withdraw? $"))
            if withdraw > balance:
                 print("Transaction cannot be completed, insufficient funds")
            
            if withdraw <= balance: 
                balance -= withdraw
                print(f"You withdrew ${withdraw}")
                print(f"Your new balance is ${balance}")

        elif choice == "q":
            print("Thank you for trusting Cortez Bank")
            break

        else:
             print("Invalid choice, please try again")

