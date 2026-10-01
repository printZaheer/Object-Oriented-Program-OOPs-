#include <iostream>
using namespace std;

const double Pi = 3.14;

class Circle {
private:
    double radius;
public:
    void setRadius(double r){
	radius = r;
	}
    double getArea() const{
	return Pi * radius * radius;
	}
};

int main() {
    Circle c;
    c.setRadius(5.0);
    cout << "Radius: 5.0" << endl;
    cout << "Area  : " << c.getArea() << endl;
    return 0;
}
