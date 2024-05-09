#include <iostream>
#include <vector>
#include <string>

// Structure to represent a task
struct Task {
    std::string description;
    bool completed;
};

// Function prototypes
void addTask(std::vector<Task> &tasks, const std::string &description);
void viewTasks(const std::vector<Task> &tasks);
void markTaskAsCompleted(std::vector<Task> &tasks, int index);
void removeTask(std::vector<Task> &tasks, int index);
void clearScreen();

int main() {
    std::vector<Task> tasks;
    char choice;

    do {
        clearScreen();
        std::cout << "\nTODO LIST MANAGER\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore newline character left in the input buffer
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                int index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                markTaskAsCompleted(tasks, index);
                break;
            }
            case '4': {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                removeTask(tasks, index);
                break;
            }
            case '5':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
        if (choice != '5') {
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
    } while (choice != '5');

    return 0;
}

void addTask(std::vector<Task> &tasks, const std::string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task> &tasks) {
    clearScreen();
    std::cout << "\nTASKS:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << "\n";
    }
}

void markTaskAsCompleted(std::vector<Task> &tasks, int index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task index!\n";
    }
}

void removeTask(std::vector<Task> &tasks, int index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task index!\n";
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

