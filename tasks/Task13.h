#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

class Task13 : public ITask {
public:
    void execute() override {
        int n;
        std::cout << "Enter natural n: \n";
        std::cin >> n;

        std::string sequence;
        for (int i = 0; i < n; i++) {
            char ch;
            std::cout << "Enter any character: \n";
            std::cin >> ch;
            sequence.push_back(ch);
            sequence.push_back(' ');
        }

        for (int i = 0; i < sequence.size(); i++) {
            if (sequence[i] >= 'a' && sequence[i] <= 'z') {
                sequence[i] = sequence[i] - 32; // 32 - разница в ascii table между малой и большой буквой
            }
        }

        for (auto &item: sequence) {
            std::cout << item << ' ';
        }
    }
};
