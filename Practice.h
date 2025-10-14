#pragma once
#include "ITask.h"
#include "tasks/Homework.h"
#include "tasks/Task1.h"
#include "tasks/Task10.h"
#include "tasks/Task11.h"
#include "tasks/Task12.h"
#include "tasks/Task13.h"
#include "tasks/Task14.h"
#include "tasks/Task15.h"
#include "tasks/Task2.h"
#include "tasks/Task3.h"
#include "tasks/Task4.h"
#include "tasks/Task5.h"
#include "tasks/Task6.h"
#include "tasks/Task7.h"
#include "tasks/Task8.h"
#include "tasks/Task9.h"

class Practice {
public:
    Practice() {
        tasks = {
            new Homework(),
            new Task1(),
            new Task2(),
            new Task3(),
            new Task4(),
            new Task5(),
            new Task6(),
            new Task7(),
            new Task8(),
            new Task9(),
            new Task10(),
            new Task11(),
            new Task12(),
            new Task13(),
            new Task14(),
            new Task15()
        };
    }

    ~Practice() {
        for (const auto task: tasks) {
            delete task;
        }
    }

    void executeTask(int taskNumber) const {
        tasks[taskNumber]->execute();
    }

private:
    std::vector<ITask *> tasks;
};
