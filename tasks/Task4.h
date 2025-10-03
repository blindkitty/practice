#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

class Task4 : public ITask {
public:
    void execute() override {
        double x;
        double y;
        std::cout << "Enter two numbers: \n";
        std::cin >> x >> y;

        if (x < 0 && y < 0) {
            x = abs(x);
            y = abs(y);
        } else if (x < 0 || y < 0) {
            x += 0.5;
            y += 0.5;
        } else {
            x = pow(x, 0.5);
            y = pow(y, 0.5);
        }
        std::cout << x << ' ' << y << '\n';
    }
};
