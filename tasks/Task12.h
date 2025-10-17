#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include "../ITask.h"

struct ItemCounts {
    int A = 0;
    int B = 0;
    int C = 0;
};

struct Worker {
    std::string lastName;
    std::string workshopName;
    ItemCounts items;
};

struct Rate {
    double Sa;
    double Sb;
    double Sc;
};

struct WorkshopReport {
    std::string workshopName;
    ItemCounts totalItems;
    std::map<std::string, double> salary;
};

class Task12 : public ITask {
public:
    void execute() override {
        const std::string fileName = "workers.txt";
        const Rate rates = {10, 12, 8};

        std::vector<Worker> workers = getDataFromFile(fileName);
        if (workers.empty()) {
            std::cerr << "No data found\n";
            return;
        }

        std::string targetWorshop = getUserInput();

        WorkshopReport report = getReportData(workers, targetWorshop, rates);

        displayReport(report);
    }

private:
    std::vector<Worker> getDataFromFile(const std::string &file) const {
        std::ifstream in(file);
        if (!in) {
            std::cerr << "!!!\n";
            return {};
        }

        std::vector<Worker> data;
        Worker temp;

        while (in >> temp.lastName >> temp.workshopName >> temp.items.A >> temp.items.B >> temp.items.C) {
            data.push_back(temp);
        }
        return data;
    }

    std::string getUserInput() const {
        std::string input;
        std::cout << "Enter workshop: \n";
        std::cin >> input;
        return input;
    }

    WorkshopReport getReportData(const std::vector<Worker> &workers,
                                 const std::string &workshop,
                                 const Rate &rates) const {
        WorkshopReport data;
        data.workshopName = workshop;
        for (const auto &worker: workers) {
            if (worker.workshopName == workshop) {
                data.totalItems.A += worker.items.A;
                data.totalItems.B += worker.items.B;
                data.totalItems.C += worker.items.C;

                double salary = worker.items.A * rates.Sa +
                                worker.items.B * rates.Sb +
                                worker.items.C * rates.Sc;
                data.salary[worker.lastName] = salary;
            }
        }
        return data;
    }

    void displayReport(const WorkshopReport &report) const {
        std::cout << "Report for workshop: " << report.workshopName << '\n';

        std::cout << "Total items: \n";
        std::cout << "\tA: " << report.totalItems.A << '\n';
        std::cout << "\tB: " << report.totalItems.B << '\n';
        std::cout << "\tC: " << report.totalItems.C << '\n';

        std::cout << "Salary info: \n";
        for (const auto &pair: report.salary) {
            std::cout << "\t" << pair.first << ": " << pair.second << " rub\n";
        }
    }
};
