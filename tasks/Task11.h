#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include "../ITask.h"

class Task11 : public ITask {
public:
    void execute() override {
        std::vector<std::string> testFiles = {
            "Task11a.txt",
            "Task11b.txt",
            "Task11c.txt"
        };

        for (std::string &testCase: testFiles) {
            std::cout << "File name: " << testCase << '\n';
            runTest(testCase);
            std::cout << '\n';
        }
    }

private:
    std::string readFile(const std::string &fileName) const {
        std::ifstream in(fileName);
        if (!in) {
            std::cerr << "Error opening file " << fileName << '\n';
            return "";
        }
        std::string str;
        std::getline(in, str);
        return str;
    }

    std::vector<int> stringToIntArray(const std::string &line) const {
        if (line.empty()) return {};
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
        for (const auto& item: numbers) {
            result.push_back(std::stoi(item));
        }
        return result;
    }

    int getSumDivisibleBy5(const std::vector<int> &numbers) const {
        int sum = 0;
        for (int num: numbers) {
            if (num % 5 == 0) {
                sum += num;
            }
        }
        return sum;
    }

    void runTest(const std::string &fileName) const {
        std::string line = readFile(fileName);
        std::cout << "Line: " << line << '\n';
        std::vector<int> numbers = stringToIntArray(line);
        int sum = getSumDivisibleBy5(numbers);
        std::cout << "Result: " << sum << '\n';
    }
};
