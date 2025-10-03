#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

class Task3 : public ITask {
public:
    void execute() override {
        double x;
        double a;
        double b;
        std::cout << "Enter value X, A and B\n";
        std::cin >> x >> a >> b;
        double y = b * (1 - exp(-0.5 * a)) * cos(2 * M_PI * x);
        std::cout << "Y = " << y << '\n';
    }
};
