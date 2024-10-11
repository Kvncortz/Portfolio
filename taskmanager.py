"""Create a task manager where users can:

Add a task (with a name, due date, and priority level: high, medium, or low).
View all tasks sorted by priority (high, medium, low).
Mark a task as completed and remove it from the list.
Search for tasks by name to view details (task name, due date, and priority).
Exit the program.
The task manager should allow the user to keep adding, viewing, and completing tasks until they choose to quit.

Features to include:

Use a list of dictionaries to store tasks with keys like "name", "due date", and "priority".
Allow the user to input and store tasks in any priority order but display them sorted.
After completing a task, remove it from the list.
Ensure user flexibility in searching tasks by name."""

tasks = []
action = ""
priority_map = {"high":1, "medium":2, "low":3}

while action != "q":
    print("1: Add a task")
    print("2: View your tasks")
    print("3: Mark a task complete")
    print("4: Search task by name")
    print("Q: To Quit")
    action = input("What would you like to do? ").lower() 

    if action == "1":
        while True:
            name = input("Enter the name of the task: ")
            date = input("Enter the due date: ")
            priority_level = input("Enter the priority level (High, Medium, Low): ").lower()

            task = {
                "name": name,
                "date": date,
                "priority_level": priority_level
            }

            tasks.append(task)
            print(f"{task['name']} has been added!")

            another = input("Would you like to add another task Y/N: ").lower()

            if another != "y":
                break
    if action == "2":
        if tasks:
            sorted_tasks = sorted(tasks, key=lambda t: priority_map[t["priority_level"]])
            print("\nYour Tasks (sorted by priority):")
            for task in sorted_tasks:
                print(f"Task Name: {task['name']}, Due Date: {task['date']}, Priority: {task['priority_level'].capitalize()}")
            print("")
        else:
            print("No tasks available.")

    if action == "3":
        name_lookup = input("Search for a task: ")
        found = False

        for task in tasks:
            if task["name"] == name_lookup:
                tasks.remove(task)
                print(f"{name_lookup} has been completed")
                found = True
                break
        if not found:
            print("Sorry, no task found with that name found")


    if action == "3":
        name_lookup = input("Search for a task: ")
        found = False

        for task in tasks:
            if task["name"] == name_lookup:
                print(f"Due Date: {task['date']}, Priority: {task['priority_level'].capitalize()}")
                found = True
                break
        if not found:
            print("Sorry, no task found with that name found")

