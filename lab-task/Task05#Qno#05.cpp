#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    string street;
};
struct Employee {
    string name;
    Address address;
};
Employee* findEmployeeByCity(Employee arr[], int size, string city) {
    for (int i = 0; i < size; i++) {
        if (arr[i].address.city == city)
            return &arr[i];
    }
    return NULL;
}
void printAll(Employee arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i].name << " - " << arr[i].address.street
             << ", " << arr[i].address.city << endl;}
int main() {
    Employee staff[3] = {
        {"Ali", {"Peshawar", "Main Street"}},
        {"Ahmed", {"Lahore", "Mall Road"}},
        {"Hassan", {"Peshawar", "Old Road"}}
    };
    cout << "Before update:" << endl;
    printAll(staff, 3);
    Employee* found = findEmployeeByCity(staff, 3, "Peshawar");
    if (found != NULL) {
        cout << "\nFound: " << found->name
             << " living on " << found->address.street << endl;
        found->address.street = "Updated Boulevard";
    }
    cout << "\nAfter update:" << endl;
    printAll(staff, 3);
    return 0;
}

