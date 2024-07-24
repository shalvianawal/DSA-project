Task task(description, category);
    NotesAdded.push_back(task);
}

void displayMenu() {
    int choice; // Variable to store the user's menu choice
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Filter Tasks by Category\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice; // Read the user's choice

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                filterTaskByCategory();
                break;
            case 6:
                cout << "Goodbye! Please do the tasks on time.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6); // Loop until the user chooses to exit
}

int main() {
    displayMenu(); // Display the menu to the user
    return 0; // End of the program
}