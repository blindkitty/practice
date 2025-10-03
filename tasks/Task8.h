#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

class Task8 : public ITask {
public:
    void execute() override {
        int n;
        std::cout << "Enter number of rows:" << '\n';
        std::cin >> n;

        int m;
        std::cout << "Enter even number of columns:" << '\n';
        std::cin >> m;

        // массив, содержащий n элементов
        // каждый элемент - массив, который представляет собой строку из m нулей
        std::vector<std::vector<int> > matrix(n, std::vector<int>(m));

        std::cout << "Enter matrix:" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> matrix[i][j];
            }
        }
        printMatrix(matrix);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                std::swap(matrix[i][j], matrix[i][m - 1 - j]);
            }
        }
        printMatrix(matrix);
    }

private:
    void printMatrix(std::vector<std::vector<int> > matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
};
