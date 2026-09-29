#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

double totalCost(const Item items[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++)
        total += items[i].quantity * items[i].price;

    return total;
}

int main() {
    Item cart[3] = {
        {"Notebook", 5, 2.50},
        {"Pen", 10, 0.75},
        {"Eraser", 3, 0.30}
    };

    cout << "Total cost of items in cart: "
         << totalCost(cart, 3) << endl;

    return 0;
}
