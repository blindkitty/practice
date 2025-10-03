#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include "../ITask.h"

class Task11 : public ITask {
public:
    void execute() override {
        std::ifstream in("Task11.txt");
        if (in) {
            std::string str;
            std::getline(in, str);

            auto intArray = stringToIntArray(str);
            int sum = 0;
            for (auto &i: intArray) {
                if (i % 5 == 0) {
                    sum += i;
                }
            }
            std::cout << sum << std::endl;
        } else {
            std::cerr << "Failed to open file" << std::endl;
        }
    }

private:
    std::vector<int> stringToIntArray(std::string line) {
        std::vector<std::string> numbers;
        std::vector<int> result;
        std::string temp;
        for (int i = 0; i < line.length() + 1; i++) {
            if (line[i] == ' ' || line[i] == '\0') {
                numbers.push_back(temp);
                temp = "";
            } else {
                temp += line[i];
            }
        }
        for (auto &item: numbers) {
            result.push_back(std::stoi(item));
        }
        return result;
    }
};
