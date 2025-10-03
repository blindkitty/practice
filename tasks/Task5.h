#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

class Task5 : public ITask {
public:
    void execute() override {
        int n;
        int k;
        std::cout << "Enter two numbers: \n";
        std::cin >> n >> k;

        int numerator = 1;
        for (int i = 0; i < k; i++) {
            numerator *= n - i;
        }
        std::cout << numerator / fact(k) << '\n';
    }

private:
    int fact(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * fact(n - 1);
    }
};
