#include<iostream>
using namespace std;
class Student {
    private : 
    string name ;
    int age ;

    public:
    Student (string name,int age ){

        // name =name ;      this is wrong method  because set garbage value or
        // age =age;         parameter = parameter. Data member which will  never set 

        this->name = name; // This will show no error because
        this->age = age;   // left side the object data member and right side parameter
    }
    void display (){
        cout<< "Name : "<<this->name<<endl;
        cout<< "Age : "<< this->age<<endl;
    }
};


int main(){
    Student s1("Zaheer", 20);
    Student s2("Zahra", 19);
    s1.display();
    s2.display();

    return 0;
}