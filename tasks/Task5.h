#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "../ITask.h"

struct ValuePair {
    int n;
    int k;
};

class Task5 : public ITask {
public:
    void execute() override {
        std::vector<ValuePair> testCases = {
            {5, 1},
            {4, 2},
            {20, 10},
            {0, 0}
        };

        for (auto testCase: testCases) {
            runTest(testCase);
            std::cout << '\n';
        }
    }

private:
    long long calculate(ValuePair pair) const {
        long long numerator = 1;
        for (int i = 0; i < pair.k; i++) {
            numerator *= pair.n - i;
        }
        return numerator / fact(pair.k);
    }

    long long fact(int num) const {
        if (num == 0 || num == 1) {
            return 1;
        }
        return num * fact(num - 1);
    }

    void runTest(ValuePair pair) const {
        std::cout << "Input data:\nn = " << pair.n << "\nk = " << pair.k << '\n';
        long long result = calculate(pair);
        std::cout << "Result: " << result << '\n';
    }
};
