#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle(){
        cout << "Vehicle is created." << endl;
    }

    ~Vehicle(){
        cout << "Vehicle is destroyed." << endl;
    }
};

class Car : public Vehicle
{
public:
    Car(){
        cout << "Car is ready." << endl;
    }

    ~Car(){
        cout << "Car is being destroyed." << endl;
    }
};

int main()
{
    Car myCar;

    return 0;
}