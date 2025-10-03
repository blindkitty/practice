#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

class Task7 : public ITask {
public:
    void execute() override {
        int n;
        std::cout << "Enter even number n: \n";
        std::cin >> n;

        std::cout << "Enter n numbers: \n";
        std::vector<double> a;
        for (int i = 0; i < n; i++) {
            double value;
            std::cin >> value;
            a.push_back(value);
        }

        std::vector<double> products;
        for (int i = 0; i < n / 2; i++) {
            products.push_back(a[i] * a[n - 1 - i]);
        }
        std::cout << *std::min_element(products.begin(), products.end()) << '\n';
    }
};
