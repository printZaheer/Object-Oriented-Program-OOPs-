#include <iostream>
#include <string>
using namespace std;

class Vehicle{                     // base class
private:
    int id;                     // hidden from  derived class
protected:
    int speed;                     // visible to derived also hide form main 
public:
    string brand;                     // visible everywhere
    void setId(int i) {
        id = i;
    }
    int getId() {
        return id;
    }
    void setSpeed(int s) {
        speed = s;
    }
};

class Car : public Vehicle{             // derived class
public:
    int doors; 
    void show(){
        cout << brand << ", speed " << speed
             << ", doors " << doors
             << ", id " << getId() << endl;
    }
};

int main(){
    Car c;
    c.brand = "Honda"; 
    c.setId(7);       
    c.setSpeed(120);
    c.doors = 4; 
    c.show();
    
    return 0;
}