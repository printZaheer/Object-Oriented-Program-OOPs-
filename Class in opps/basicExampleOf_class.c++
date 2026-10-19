#include <iostream>
#include <string>
using namespace std;

class Student{
public:                        // access specefier which can be acess anywhere
    string name;              // data member or attributes 
    int age;         
    
    void display(){                             // member function or behaviour         
        cout << "Name: " << name << endl;            
        cout << "Age: " << age << endl;
    }
};
int main(){
    Student s1;
    s1.name = "Ali";                         // . operator using for accesing 
    s1.age = 20;
    s1.display();
    return 0;
}