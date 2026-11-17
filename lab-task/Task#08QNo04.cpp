#include <iostream>
using namespace std;

class Fraction {
private:
    const int numerator;
    const int denominator;
public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}
    double getValue() const {
        return static_cast<double>(numerator) / denominator;
    }
    void display() const {
        cout << numerator << "/" << denominator << " = " << getValue() << endl;
    }
};
int main() {
    Fraction f1(3, 4);
    Fraction f2(1, 3);
    f1.display();
    f2.display();

    return 0;
}
