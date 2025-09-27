#pragma once
#include <bits/stdc++.h>
#include "../ITask.h"


class Homework : public ITask {
public:
    void execute() override {
        const int a = 10;
        const int b = 20;
        std::cout << "1) " << a + b << '\n';
        std::cout << "2) " << pow(a + b, 2) << '\n';
        std::cout << "3) " << pow(a + b, 0.5) << '\n';
        std::cout << "4) " << ((a + b) * (a - b)) / (a + b) << '\n';
        std::cout << "5) " << pow(a, 2) + pow(b, 2) << '\n';
        std::cout << "6) " << pow(a, 0.5) + pow(b, 0.5) << '\n';
        std::cout << "7) " << (a + b) / pow(a + b, 0.5) << '\n';
        std::cout << "8) " << (a + b) / (pow(a, 2) + pow(b, 2)) << "\n\n";
        system("pause");

        const double x = M_PI / 4;
        std::cout << "9) " << sin(x) + tan(x) << '\n';
        std::cout << "10) " << sin(pow(x, 2)) << '\n';
        std::cout << "11) " << pow(sin(x), 0.5) << '\n';
        std::cout << "12) " << sin(x) + tan(pow(x, 5)) << '\n';
        std::cout << "13) " << pow(tan(x), 3) + sin(x) / cos(x) << '\n';
        std::cout << "14) " << pow(sin(x), 2) << '\n';
        std::cout << "15) " << pow(sin(x), 2) << '\n';
        std::cout << "16) " << (tan(x) + 1 / tan(x)) / (sin(x) + cos(x)) << '\n';
        std::cout << "17) " << pow(sin(x) + cos(x), 2) << '\n';
        std::cout << "18) " << pow(sin(x), 0.25) << "\n\n";
        system("pause");

        std::cout << calculateСircumference() << '\n';
        system("pause");
        std::cout << calculateСylinderVolume() << '\n';
    }

private:
    double calculateСircumference() {
        double radius;
        std::cout << "Enter radius of circle: ";
        std::cin >> radius;
        return 2 * M_PI * radius;
    }

    double calculateСylinderVolume() {
        double area;
        double height;
        std::cout << "Enter area of cylinder: ";
        std::cin >> area;
        std::cout << "Enter height of cylinder: ";
        std::cin >> height;
        return area * height;
    }
};
