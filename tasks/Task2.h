#pragma once
#include "../ITask.h"
#include <iostream>

class Task2 : public ITask {
public:
    void execute() override {
        std::cout << "x y z F" << '\n';
        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                for (int z = 0; z <= 1; z++) {
                    std::cout << x << ' ' << y << ' ' << z << ' '
                            << !(x && ((y && !z) || (x && !z))) << '\n';
                }
            }
        }
        system("pause");
        std::cout << "\nx y z F" << '\n';
        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                for (int z = 0; z <= 1; z++) {
                    std::cout << x << ' ' << y << ' ' << z << ' '
                            << !(x && (y && !z || (x && !z))) << '\n';
                }
            }
        }
    }
};
