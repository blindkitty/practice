#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"


class Task8 : public ITask {
public:
    using Matrix = std::vector<std::vector<int> >;

    void execute() override {
        std::vector<Matrix> testCases = {
            {
                {1, 4, 7, 0},
                {2, 5, 8, 0},
                {3, 6, 9, 0}
            },
            {
                {1, 2, 3, 4, 5, 6},
                {7, 8, 9, 10, 11, 12},
                {13, 14, 15, 16, 17, 18}
            },
            {
                {1, 2}
            }
        };
        for (auto &testCase: testCases) {
            runTest(testCase);
        }
    }

private:
    Matrix swapColumns(const Matrix &originalMatrix) const {
        Matrix newMatrix = originalMatrix;
        int numRows = originalMatrix.size();
        int numCols = originalMatrix[0].size();
        for (int j = 0; j < numCols / 2; j++) {
            for (int i = 0; i < numRows; i++) {
                std::swap(newMatrix[i][j], newMatrix[i][numCols - 1 - j]);
            }
        }
        return newMatrix;
    }

    void printMatrix(const Matrix &matrix) const {
        for (const auto &row: matrix) {
            for (int element: row) {
                std::cout << element << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    void runTest(const Matrix &matrix) const {
        std::cout << "Original matrix:\n";
        printMatrix(matrix);

        Matrix newMatrix = swapColumns(matrix);

        std::cout << "Final matrix:\n";
        printMatrix(newMatrix);
    }
};
