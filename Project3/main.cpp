#include <iostream>
#include <limits>
#include <string>
#include "taskmanager.h"

int main() {
    TaskManager manager;
    while (true) {
        std::cout
            << "\nTask Manager:\n"
            << "1. Add Task\n"
            << "2. Complete Task\n"
            << "3. Display Tasks\n"
            << "4. Display Tasks (sorted by priority)\n"
            << "5. Remove Task\n"
            << "6. Edit Task\n"
            << "7. Save to File\n"
            << "8. Load from File\n"
            << "0. Exit\n"
            << "Enter choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!std::cin) {
            std::cerr << "Invalid input. Exiting...\n";
            break;
        }
        if (choice == 0) {
            std::cout << "Exiting...\n";
            break;
        }
        switch (choice) {
        case 1: {
            std::string desc;
            int prio;
            std::cout << "Enter task description: ";
            std::getline(std::cin, desc);
            std::cout << "Enter priority (integer): ";
            std::cin >> prio;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            manager.addTask(desc, prio);
            std::cout << "Task added.\n";
            break;
        }
        case 2: {
            int id;
            std::cout << "Enter task ID to complete: ";
            std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (manager.completeTask(id))
                std::cout << "Task " << id << " completed.\n";
            else
                std::cout << "Task " << id << " not found or already completed.\n";
            break;
        }
        case 3: {
            manager.displayTasks(false);
            break;
        }
        case 4: {
            manager.displayTasks(true);
            break;
        }
        case 5: {
            int id;
            std::cout << "Enter task ID to remove: ";
            std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (manager.removeTask(id))
                std::cout << "Task " << id << " removed.\n";
            else
                std::cout << "Task " << id << " not found.\n";
            break;
        }
        case 6: {
            int id, prio;
            std::string desc;
            std::cout << "Enter task ID to edit: ";
            std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "New description: ";
            std::getline(std::cin, desc);
            std::cout << "New priority (integer): ";
            std::cin >> prio;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (manager.editTask(id, desc, prio))
                std::cout << "Task " << id << " updated.\n";
            else
                std::cout << "Task " << id << " not found.\n";
            break;
        }
        case 7: {
            std::string filePath;
            std::cout << "Enter the file path for saving: ";
            std::getline(std::cin, filePath);
            manager.saveToFile(filePath);
            std::cout << "Tasks saved.\n";
            break;
        }
        case 8: {
            std::string filePath;
            std::cout << "Enter the file path for loading: ";
            std::getline(std::cin, filePath);
            manager.loadFromFile(filePath);
            std::cout << "Tasks loaded.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
    return 0;
}
