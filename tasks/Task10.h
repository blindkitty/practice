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
        std::vector<Product> storage = getUserInput();
        double totalCost = calculateTotalCost(storage);
        std::cout << "Total cost: " << totalCost << std::endl;
    }

private:
    std::vector<Product> getUserInput() const {
        int numberOfProducts;
        std::cout << "Enter number of products: \n";
        std::cin >> numberOfProducts;
        std::vector<Product> products;
        for (int i = 0; i < numberOfProducts; i++) {
            std::cout << "Enter data for " << i + 1 << " product (name, year, price, quantity): \n";

            std::string name;
            int yearOfRelease;
            double unitPrice;
            int quantity;

            std::cin >> name >> yearOfRelease >> unitPrice >> quantity;

            products.push_back(Product(name, yearOfRelease, unitPrice, quantity));
        }
        return products;
    }

    double calculateTotalCost(const std::vector<Product> &products) const {
        double totalCost = 0;
        for (auto &p: products) {
            totalCost += p._unitPrice * p._quantity;
        }
        return totalCost;
    }
};
