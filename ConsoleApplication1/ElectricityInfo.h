#pragma once
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class ElectricityInfo {
private:
    static const int countmounth = 12;
    int year;
    double tariff;
    double readings[12];
    double payments[12];
    double totalPayments;

    double calculateAverageConsumption() const {
        double totalConsumption = 0;
        for (int i = 0; i < countmounth; ++i) {
            totalConsumption += readings[i];
        }
        return totalConsumption / countmounth;
    }

public:
    ElectricityInfo(double initialTariff);
    int getYear() const;
    double getTariff() const;
    double getTotalPayments() const;
    void displayInfo() const;
    void inputReadings(int month, double newReadings);
    double operator[](int month) const;  // Перегрузка оператора []
    friend ostream& operator<<(ostream& out, const ElectricityInfo& obj);  // Перегрузка оператора вывода
    friend istream& operator>>(istream& in, ElectricityInfo& obj);  // Перегрузка оператора ввода
    ~ElectricityInfo();
};
