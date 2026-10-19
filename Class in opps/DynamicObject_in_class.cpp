#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    string name;
public:
    Student(string n){
        name = n;
        cout << "Created " << name << endl;
    }
    ~Student()
    {
        cout << "Destroyed " << name << endl;
    }
    void display() { cout << "Name: " << name << endl; }
};

int main(){
    Student *p = new Student("Ali");
    p->display();
    cout << "Before delete" << endl;
    delete p;
    cout << "After delete" << endl;
    return 0;
}