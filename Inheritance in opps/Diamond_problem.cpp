#include <iostream>
using namespace std;

class Person{
public:
    void show(){
        cout << "I am a person." << endl;
    }
};

class Student : virtual public Person{
};

class Employee : virtual public Person{
};

class Researcher : public Student, public Employee{
};

int main(){
    Researcher r;

    r.show();

    return 0;
}