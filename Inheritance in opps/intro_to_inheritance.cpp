#include <iostream>
#include <string>
using namespace std;

class Person{ // base class
public:
    string name;
    int age;
    void introduce(){
        cout << "I am " << name << " and my  age is " << age << endl;
    }
};

class Student : public Person{              // derived class
public:
    int rollNo;
    void showRoll(){
        cout << " My Roll no is : " << rollNo << endl;
    }
};

int main(){
    Student s1;
    s1.name = "Ali"; 
    s1.age = 20;     
    s1.rollNo = 101;
    s1.introduce();
    s1.showRoll();   
    return 0;
}