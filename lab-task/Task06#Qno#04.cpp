#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
public:
    void setName(string nam){
        name = nam;
    }
    void setSalary(double s){
        salary = s;
    }
    string getName(){ 
        return name;
    }
    double getSalary(){ 
        return salary;
    }
};
int main(){
    Employee emp1;
    emp1.setName("Hassan");
    emp1.setSalary(50000);
    Employee* empPtr = new Employee();
    empPtr->setName("Zahra");
    empPtr->setSalary(65000);
    Employee& empRef = emp1;
    cout << " object or using dot notation:\n";
    cout << "  Name  : " << emp1.getName() << endl;
    cout << "  Salary: " << emp1.getSalary() << endl;
    cout << "\n pointer or  using arrow operator:\n";
    cout << "  Name  : " << empPtr->getName() << endl;
    cout << "  Salary: " << empPtr->getSalary() << endl;
    cout << "\n reference or aliases emp1:\n";
    cout << "  Name  : " << empRef.getName() << endl;
    cout << "  Salary: " << empRef.getSalary() << endl;
    empRef.setSalary(55000);
    cout << "\nAfter updating salary through the reference, emp1.getSalary() = "<< emp1.getSalary() << endl;
    delete empPtr;
    empPtr = nullptr;
    return 0;
}
