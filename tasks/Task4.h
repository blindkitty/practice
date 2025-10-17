#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "../ITask.h"

struct NumberPair {
    double x;
    double y;
};

class Task4 : public ITask {
public:
    void execute() override {
        std::vector<NumberPair> testCases = {
            {-15.45, -60},
            {-0.5, 0.5},
            {256, 65536},
            {0, 0}
        };

        for (const auto &testPair: testCases) {
            runTest(testPair);
            std::cout << '\n';
        }
    }

private:
    NumberPair transformNumbers(NumberPair pair) {
        if (pair.x < 0 && pair.y < 0) {
            pair.x = std::abs(pair.x);
            pair.y = std::abs(pair.y);
        } else if (pair.x < 0 || pair.y < 0) {
            pair.x += 0.5;
            pair.y += 0.5;
        } else {
            pair.x = std::pow(pair.x, 0.5);
            pair.y = std::pow(pair.y, 0.5);
        }
        return pair;
    }

    void runTest(NumberPair pair) {
        std::cout << "\nInput data:\nx = " << pair.x << "\ny = " << pair.y << '\n';

        NumberPair result = transformNumbers(pair);

        std::cout << "\nResult:\nx = " << result.x << "\ny = " << result.y << '\n';
    }
};
