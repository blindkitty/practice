#pragma once
#include <bits/stdc++.h>
#include "ITask.h"


class Task1 : ITask {
public:
    std::string decimalToBase(int a, int c) {
        std::string s = "";
        while (a > 0) {
            s += std::to_string(a % c);
            a /= c;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    int digitToDecimal(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        }
        if (c >= 'a' && c <= 'f') {
            return 10 + (c - 'a');
        }
        return 0;
    }


    int convertToDecimal(std::string num, int c) {
        int decimalVal = 0;
        int power = 1;
        for (int i = num.length() - 1; i >= 0; --i) {
            int digit = digitToDecimal(num[i]);
            decimalVal += digit * power;
            power *= c;
        }
        return decimalVal;
    }

    void execute() override {
        // a)
        std::cout << "a)" << "\n";
        //
        std::cout << decimalToBase(0b11100101 + 0b100011, 2) << "\n";
        //
        std::cout << decimalToBase(0b11001101 - 0b1111, 2) << "\n";
        //
        std::cout << decimalToBase(0b1011 * 0b1001, 2) << "\n\n";


        // b)
        std::cout << "b)" << "\n";
        //
        std::cout << decimalToBase(55, 2) << "\n";
        //
        std::cout << pow(2, 8) + pow(2, 7) + pow(2, 6) + pow(2, 5) + pow(2, 1) + pow(2, -2) << "\n";
        //
        std::cout << decimalToBase(convertToDecimal("442", 6), 5) << "\n";

        // c)
        std::cout << "c)" << "\n";
        double a = pow(2, 7) + pow(2, 4) + pow(2, 3) + pow(2, 1) + pow(2, 0) + pow(2, -3) + pow(2, -4);
        double b = convertToDecimal("257", 8);
        double c = convertToDecimal("a28", 16);
        std::cout << a + b + c;
    }
};

