#include <iostream>
using namespace std;

const double Pi = 3.141;

class Circle{
private:
    double radius;
    bool validateRadius(double r);

public:
    void setRadius(double r);
    double calculateArea() const;
    double calculatePerimeter() const;
};
bool Circle::validateRadius(double r){
    return r > 0;
}
void Circle::setRadius(double r){
    if (validateRadius(r)){
        radius = r;
    }else
    {
        cout << "Invalid radius (" << r << ").\n";
    }
}

double Circle::calculateArea() const{
    return Pi * radius * radius;
}
double Circle::calculatePerimeter() const{
    return 2 * Pi * radius;
}
int main(){
    Circle c;
    c.setRadius(4.0);
    cout << "Area     : " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;
    cout << "\nTry to put an invalid radius:\n";
    c.setRadius(-3.0);
    cout << "Area     : " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;
    return 0;
}