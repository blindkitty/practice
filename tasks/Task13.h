#pragma once
#include <iostream>
#include <vector>
#include "../ITask.h"

constexpr int ASCII_CASE_OFFSET = 'a' - 'A';

class Task13 : public ITask {
public:
    struct charSequence {
        std::string text;
        int n = text.size();
    };

    void execute() override {
        std::vector<charSequence> testCases = {
            {"hello world!"},
            {"dQw4w9WgXcQ"},
            {"65 963 56    6"},
            {""}
        };

        for (const auto &testCase: testCases) {
            runTest(testCase);
            std::cout << '\n';
        }
    }

private:
    charSequence toUpper(const charSequence &sequence) const {
        charSequence result = sequence;
        for (int i = 0; i < sequence.n; i++) {
            if (sequence.text[i] >= 'a' && sequence.text[i] <= 'z') {
                result.text[i] -= ASCII_CASE_OFFSET;
            }
        }
        return result;
    }

    void runTest(const charSequence &sequence) const {
        std::cout << "Input data: " << sequence.text << '\n';
        charSequence result = toUpper(sequence);
        std::cout << "Result: " << result.text << '\n';
    }
};
