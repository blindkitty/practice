#pragma once
#include <iostream>
#include <cmath>
#include "../ITask.h"

struct Product {
    std::string _name;
    int _yearOfRelease;
    double _unitPrice;
    int _quantity;

    Product(std::string name, int yearOfRelease, double unitPrice, int quantity) {
        _name = name;
        _yearOfRelease = yearOfRelease;
        _unitPrice = unitPrice;
        _quantity = quantity;
    }
};

class Task10 : public ITask {
public:
    void execute() override {
        int numberOfProducts;
        std::cout << "Enter number of products: " << '\n';
        std::cin >> numberOfProducts;

        std::vector<Product> storage;
        for (int i = 0; i < numberOfProducts; i++) {
            std::cout << "Enter data for product (name, year, price, quantity): \n";
            std::string name;
            std::cin >> name;

            int yearOfRelease;
            std::cin >> yearOfRelease;

            double unitPrice;
            std::cin >> unitPrice;

            int quantity;
            std::cin >> quantity;
            storage.push_back(Product(name, yearOfRelease, unitPrice, quantity));
        }

        double totalCost = 0;
        for (auto &p: storage) {
            totalCost += p._unitPrice * p._quantity;
        }
        std::cout << "Total cost: " << totalCost << '\n';
    }
};
