#include "taskmanager.h"
#include <algorithm>  // For std::sort
#include <fstream>
#include <iostream>
#include <limits>

void TaskManager::addTask(const std::string& desc, int prio) {
    Task newTask;
    newTask.id = nextId++;
    newTask.description = desc;
    newTask.priority = prio;
    newTask.completed = false;
    tasks.push_back(newTask);
}

bool TaskManager::completeTask(int id) {
    for (auto& t : tasks) {
        if (t.id == id && !t.completed) {
            t.completed = true;
            return true;
        }
    }
    return false;
}

bool TaskManager::removeTask(int id) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            return true;
        }
    }
    return false;
}

bool TaskManager::editTask(int id, const std::string& newDesc, int newPrio) {
    for (auto& t : tasks) {
        if (t.id == id) {
            t.description = newDesc;
            t.priority = newPrio;
            return true;
        }
    }
    return false;
}

void TaskManager::displayTasks(bool sortByPriority) {
    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }
    if (sortByPriority) {
        std::sort(tasks.begin(), tasks.end(),
            [](const Task& a, const Task& b) {
                return a.priority > b.priority;
            });
    }
    for (const auto& t : tasks) {
        std::cout << "[ID: " << t.id << "] "
            << (t.completed ? "(Done)  " : "(Pending) ")
            << "Priority: " << t.priority
            << " - " << t.description << "\n";
    }
}

void TaskManager::saveToFile(const std::string& filePath) const {
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& t : tasks) {
        outFile << t.id << '\t'
            << t.description << '\t'
            << t.priority << '\t'
            << t.completed << '\n';
    }
}

void TaskManager::loadFromFile(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    tasks.clear();
    nextId = 1;
    while (true) {
        int id, prio;
        bool done;
        std::string desc;
        inFile >> id;
        if (!inFile) break;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
        std::getline(inFile, desc, '\t');
        inFile >> prio >> done;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Task loadedTask{ id, desc, prio, done };
        tasks.push_back(loadedTask);
        if (id >= nextId) {
            nextId = id + 1;
        }
    }
}
