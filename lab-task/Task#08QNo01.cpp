#include <iostream>
using namespace std;

class Car {
public:
    static int totalCars;
    Car() {
        totalCars++;       
    }
};
int Car::totalCars = 0;
int main() {
    Car c1,c2,c3,c4;
    cout << "Total cars (via class name): " << Car::totalCars << endl;
    cout << "Total cars (via object c1):  " << c1.totalCars << endl;
    cout << "Total cars (via object c3):  " << c3.totalCars << endl;

    return 0;
}

