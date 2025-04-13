#pragma once
#include <string>

struct Task {
    int id;
    std::string description;
    int priority;
    bool completed;
};
