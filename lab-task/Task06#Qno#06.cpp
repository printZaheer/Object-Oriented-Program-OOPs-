#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
public:
    void setName(string n){
	name = n;
	}
    void setPrice(double p){
	price = p;
	}
    string getName() const{
	return name;
	}
    double getPrice() const{
	return price;
	}
};
void applyDiscount(Product* p, double percent){
    double newPrice = p->getPrice() - (p->getPrice() * percent / 100.0);
    p->setPrice(newPrice);
}
int main(){
    const int SIZE = 3;
    Product products[SIZE];

    products[0].setName("Laptop");
    products[0].setPrice(1200.0);
    products[1].setName("Headphones");
    products[1].setPrice(150.0);
    products[2].setName("Keyboard");
    products[2].setPrice(80.0);

    applyDiscount(&products[0], 10.0);
    applyDiscount(&products[1], 20.0);
    applyDiscount(&products[2], 15.0);

    cout << "\nProducts after discount    \n";
    for (int i = 0; i < SIZE; i++) {
        cout << products[i].getName() << ": $" << products[i].getPrice() << endl;
    }
    return 0;
}
