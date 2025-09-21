#pragma once
#include "ITask.h"
#include "Task1.h"

class Practice {
private:
    std::vector<ITask> tasks;
public:
    Practice() {
        tasks.push_back(new Task1);
    }

};
