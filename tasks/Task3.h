#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

struct FuncParams {
    double x;
    double a;
    double b;
};

class Task3 : public ITask {
public:
    void execute() override {
        FuncParams params = getUserInput();

        double y = calculateY(params);

        printResult(params, y);
    }

private:
    FuncParams getUserInput() const {
        FuncParams p;
        std::cout << "Enter value X, A and B\n";
        std::cin >> p.x >> p.a >> p.b;
        return p;
    }

    double calculateY(FuncParams p) const {
        return p.b * (1 - std::exp(-0.5 * p.a)) * std::cos(2 * M_PI * p.x);
    }

    void printResult(FuncParams p, double y) const {
        std::cout << "For input data: " << p.x << ", " << p.a << ", " << p.b << '\n';
        std::cout << "Result: Y = " << y << '\n';
    }
};
