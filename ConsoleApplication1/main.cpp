#include "Electricityinfo.h"
int main() {
    setlocale(LC_ALL, "ru");
    try {
        ElectricityInfo electricity(0.15);
        electricity.inputReadings(1, 500);        
        electricity.inputReadings(2, 600);
        cout << "Платёж за февраль " << electricity[2] << endl;
        
        //electricity.displayInfo();
        cout << electricity;
    }
    catch (const exception& e) {
        cerr << "Исключение: " << e.what() << endl;
    }
    return 0;
}