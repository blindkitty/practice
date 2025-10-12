#pragma once
#include <iostream>
#include <vector>
#include "../ITask.h"

class Task7 : public ITask {
public:
    void execute() override {
        std::vector<std::vector<double> > testCases = {
            {1, 2, 3, 4, 5, 6},
            {10, -21.2, 5, 12},
            {20, 30, 40, 50, 1, 5},
            {0, 0}
        };

        for (const auto &testCase: testCases) {
            runTest(testCase);
            std::cout << '\n';
        }
    }

private:
    double getMinSymmetricProduct(const std::vector<double>& numbers) {
        std::vector<double> products;
        int n = numbers.size();
        for (int i = 0; i < n / 2; i++) {
            products.push_back(numbers[i] * numbers[n - 1 - i]);
        }
        return *std::min_element(products.begin(), products.end());
    }

    void runTest(std::vector<double> a) {
        std::cout << "Input data: \n";
        for (const auto &el: a) {
            std::cout << el << ' ';
        }
        std::cout << "\nResult: \n" << getMinSymmetricProduct(a) << '\n';
    }
};
