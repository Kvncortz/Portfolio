list = []
task = ""
action = ""

while not action == "q":
    print ("What would you like to do? ")
    print ("1: Add task")
    print ("2: View tasks")
    print ("3: Delete task")
    print ("Q: To Quit")
    action = input("What would you like to do? ").lower()

    if action == "1":
        print("Enter a task one by one, when done type done")
        while True:
            task = input("Enter your task: ")
            if task.lower() == "done":
                break
            list.append(task)
    if action == "2":
        if not list:
            print("There are not tasks in your to do list!")
        else:
            print("Your tasks:")
            for i, task in enumerate(list, start=1):
                print(f"{i}. {task}")
    if action == "3":
        if not list:
            print("There are not tasks in your to do list!")
        else:
            for i, task in enumerate(list, start=1):
                print(f"{i}. {task}")
            delete = int(input("Enter the task number to delete: "))

            if 1 <= delete <= len(list):
                delete = list.pop(delete - 1)
                print(f"{delete} has been deleted")
            else:
                print("Invalid number choice")
    
    if action == "q":
        print("Thank you, have a great day")