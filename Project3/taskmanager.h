#pragma once
#include <vector>
#include <string>
#include "task.h"

class TaskManager {
public:
    void addTask(const std::string& desc, int prio);
    bool completeTask(int id);
    bool removeTask(int id);
    bool editTask(int id, const std::string& newDesc, int newPrio);
    void displayTasks(bool sortByPriority = false);
    void saveToFile(const std::string& filePath) const;
    void loadFromFile(const std::string& filePath);

private:
    std::vector<Task> tasks;
    int nextId = 1;
};
