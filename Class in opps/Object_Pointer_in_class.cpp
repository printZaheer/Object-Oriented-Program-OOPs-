#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    int age;
    void display() {
        cout << name << ", " << age << endl;
    }
};

int main(){
    Student s1;
    s1.name = "Ali"; 
    s1.age = 20;

    Student *p = &s1; 

    p->display(); 
    p->age = 21;  
    s1.display();
    (*p).display(); 
    return 0;
}