#pragma once
#include "ITask.h"
#include "tasks/Task1.h"

class Practice {
public:
    Practice() {
        tasks.push_back(new Task1());
    }

    ~Practice() {
        for (auto task: tasks) {
            delete task;
        }
    }

    void execute(int taskNumber) {
        tasks[taskNumber - 1]->execute();
    }

private:
    std::vector<ITask *> tasks;
};
