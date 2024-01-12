#include "Electricityinfo.h"
ElectricityInfo::ElectricityInfo(double initialTariff) : year(0), tariff(initialTariff), totalPayments(0) { // исключение для тарифа >0    
    if (initialTariff <= 0)
    {
        throw out_of_range("значение не может быть < 0");    }
    for (int i = 0; i < countmounth; ++i) {
        readings[i] = 0;
        payments[i] = 0;
    }
}
int ElectricityInfo::getYear() const {
    return year;
}
double ElectricityInfo::getTariff() const {
    return tariff;
}
double ElectricityInfo::getTotalPayments() const {
    return totalPayments;
}
void ElectricityInfo::displayInfo() const {
    cout << "Информация об электроэнергии за год " << year << endl;
    for (int i = 0; i < countmounth; ++i) {
        cout << "Месяц " << i + 1 << ": Показания = " << readings[i] << ", Платежи = " << payments[i] << endl;
    }    cout << "Общие Платежи: " << totalPayments << endl;
    cout << "Тариф: " << tariff << endl;    cout << "Средний Расход: " << calculateAverageConsumption() << endl;
}
void ElectricityInfo::inputReadings(int month, double newReadings) {
    if (month < 1 || month > countmounth) {
        throw out_of_range("Неверный месяц. Месяц должен быть от 1 до countmounth.");
    }
    if (newReadings < 0) {
        throw invalid_argument("Показания не могут быть отрицательными.");
    }
    if (month == 1) {  // если !=1 
        year++;
    }
    readings[month - 1] = newReadings;
    payments[month - 1] = newReadings * tariff;    totalPayments += payments[month - 1];
}
double ElectricityInfo::operator[](int month) const {
    if (month < 1 || month > countmounth) {
        throw out_of_range("Неверный месяц. Месяц должен быть от 1 до countmounth.");
    }
    return payments[month - 1];
}

ElectricityInfo::~ElectricityInfo()
{
}

ostream& operator<<(ostream& out, const ElectricityInfo& obj) {
    out << "Информация об электроэнергии за год " << obj.year << endl;
    for (int i = 0; i < obj.countmounth; ++i) {
        out << "Месяц " << i + 1 << ": Показания = " << obj.readings[i] << ", Платежи = " << obj.payments[i] << endl;
    }    out << "Общие Платежи: " << obj.totalPayments << endl;
    out << "Тариф: " << obj.tariff << endl;    out << "Средний Расход: " << obj.calculateAverageConsumption() << endl;
    return out;
}

istream& operator>>(istream& in, ElectricityInfo& obj) {
    // Введите код для считывания данных, если нужно
    return in;
}