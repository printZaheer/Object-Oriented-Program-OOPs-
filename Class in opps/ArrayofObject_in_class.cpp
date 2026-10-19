#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int marks;

public:
    Student()
    {
        name = "Unknown";
        marks = 0;
    } 
    void set(string n, int m){
        name = n;
        marks = m;
    }
    int getMarks() {
        return marks;
    }
    void display() {
        cout << name << ": " << marks << endl;
    }
};

int main(){
    Student s[3]; 
    s[0].set("Ali", 85);
    s[1].set("Hassan", 90);
    s[2].set("Hussain", 78);
    int total = 0;
    for (int i = 0; i < 3; i++){
        s[i].display();
        total = total + s[i].getMarks();
    }
    cout << "Total: " << total << endl;
    return 0;
}