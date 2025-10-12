#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"


class Task3 : public ITask {
public:
    struct FuncParams {
        double x;
        double a;
        double b;
    };

    void execute() override {
        FuncParams params = getUserInput();

        double y = calculateY(params);

        printResult(params, y);
    }

private:
    FuncParams getUserInput() {
        FuncParams p;
        std::cout << "Enter value X, A and B\n";
        std::cin >> p.x >> p.a >> p.b;
        return p;
    }

    double calculateY(FuncParams p) {
        return p.b * (1 - std::exp(-0.5 * p.a)) * std::cos(2 * M_PI * p.x);
    }

    void printResult(FuncParams p, double y) {
        std::cout << "For input data: " << p.x << ", " << p.a << ", " << p.b << '\n';
        std::cout << "Result: Y = " << y << '\n';
    }
};
