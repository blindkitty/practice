#pragma once
#include <iostream>
#include <vector>
#include "../ITask.h"

class Task14 : public ITask {
public:
    void execute() override {
        std::vector<std::string> testCases = {
            "hello world !!  !!!     !",
            "dd 334 fgh",
            "fgffgfgd",
            ""
        };

        for (const auto &testCase: testCases) {
            runTest(testCase);
            std::cout << '\n';
        }
    }

private:
    int getMaxSpaces(const std::string &text) const {
        int maxSpaces = 0;
        int currSpaces = 0;
        for (const char c: text) {
            if (c == ' ') {
                currSpaces++;
            } else {
                currSpaces = 0;
            }
            if (currSpaces > maxSpaces) {
                maxSpaces = currSpaces;
            }
        }
        return maxSpaces;
    }

    void runTest(const std::string &text) const {
        std::cout << "Input data: " << text << '\n';
        int result = getMaxSpaces(text);
        std::cout << "Max spaces: " << result << '\n';
    }
};
