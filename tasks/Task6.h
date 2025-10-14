#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "../ITask.h"

struct CalculationParams {
    double a;
    double b;
    int n;
};

struct TableEntry {
    double x;
    double fx;
};


class Task6 : public ITask {
public:
    void execute() override {
        CalculationParams params = getUserInput();
        std::vector<TableEntry> table = createTable(params);
        int specialValueCount = analyzeTable(table);
        printResult(table, specialValueCount);
    }

private:
    CalculationParams getUserInput() const {
        CalculationParams params;
        std::cout << "Enter interval (a, b) and number of points (n)\n";
        std::cin >> params.a >> params.b >> params.n;
        return params;
    }

    double calculateFunction(double x) const {
        return std::exp(-0.5 * x) * pow(cos(M_PI * x), 2);
    }

    std::vector<TableEntry> createTable(const CalculationParams &params) const {
        std::vector<TableEntry> table;
        double step = (params.b - params.a) / (params.n - 1);

        for (int i = 0; i < params.n; i++) {
            double x = params.a + i * step;
            double fx = calculateFunction(x);
            table.push_back({x, fx});
        }
        return table;
    }

    int analyzeTable(const std::vector<TableEntry> &table) const {
        int count = 0;
        for (const auto &entry: table) {
            if (std::abs(static_cast<int>(entry.fx)) > 1) {
                count++;
            }
        }
        return count;
    }

    void printResult(const std::vector<TableEntry> &table, int count) const {
        std::cout << "x\t\tf(x)\n";
        for (const auto &entry: table) {
            std::cout << entry.x << "\t\t" << entry.fx << "\n";
        }
        std::cout << "\nNumber of f(x), for which integer part > 1: " << count << '\n';
    }
};
