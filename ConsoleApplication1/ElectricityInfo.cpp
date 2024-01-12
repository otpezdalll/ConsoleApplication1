#include "Electricityinfo.h"
ElectricityInfo::ElectricityInfo(double initialTariff) : year(0), tariff(initialTariff), totalPayments(0) { // ���������� ��� ������ >0    
    if (initialTariff <= 0)
    {
        throw out_of_range("�������� �� ����� ���� < 0");    }
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
    cout << "���������� �� �������������� �� ��� " << year << endl;
    for (int i = 0; i < countmounth; ++i) {
        cout << "����� " << i + 1 << ": ��������� = " << readings[i] << ", ������� = " << payments[i] << endl;
    }    cout << "����� �������: " << totalPayments << endl;
    cout << "�����: " << tariff << endl;    cout << "������� ������: " << calculateAverageConsumption() << endl;
}
void ElectricityInfo::inputReadings(int month, double newReadings) {
    if (month < 1 || month > countmounth) {
        throw out_of_range("�������� �����. ����� ������ ���� �� 1 �� countmounth.");
    }
    if (newReadings < 0) {
        throw invalid_argument("��������� �� ����� ���� ��������������.");
    }
    if (month == 1) {  // ���� !=1 
        year++;
    }
    readings[month - 1] = newReadings;
    payments[month - 1] = newReadings * tariff;    totalPayments += payments[month - 1];
}
double ElectricityInfo::operator[](int month) const {
    if (month < 1 || month > countmounth) {
        throw out_of_range("�������� �����. ����� ������ ���� �� 1 �� countmounth.");
    }
    return payments[month - 1];
}

ElectricityInfo::~ElectricityInfo()
{
}

ostream& operator<<(ostream& out, const ElectricityInfo& obj) {
    out << "���������� �� �������������� �� ��� " << obj.year << endl;
    for (int i = 0; i < obj.countmounth; ++i) {
        out << "����� " << i + 1 << ": ��������� = " << obj.readings[i] << ", ������� = " << obj.payments[i] << endl;
    }    out << "����� �������: " << obj.totalPayments << endl;
    out << "�����: " << obj.tariff << endl;    out << "������� ������: " << obj.calculateAverageConsumption() << endl;
    return out;
}

istream& operator>>(istream& in, ElectricityInfo& obj) {
    // ������� ��� ��� ���������� ������, ���� �����
    return in;
}