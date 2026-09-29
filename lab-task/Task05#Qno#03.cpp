#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    double salary;
};
void raiseSalary(Employee staff[], int size, double percent) {
    for (int i = 0; i < size; i++)
        staff[i].salary += staff[i].salary * (percent / 100);
}
void printEmployees(Employee staff[], int size) {
    for (int i = 0; i < size; i++)
        cout << staff[i].name << ": $" << staff[i].salary << endl;
}
int main() {
    Employee staff[3] = {
        {"Ali", 50000},
        {"Ahmed", 60000},
        {"Hassan", 55000}
    };
    cout << "Before raise:" << endl;
    printEmployees(staff, 3);

    raiseSalary(staff, 3, 10);

    cout << "\nAfter 10% raise:" << endl;
    printEmployees(staff, 3);

    return 0;
}

