#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;
public:
    void setName(string nam){
	name = nam;
	}
    void setMarks(int m){
	marks = m;
	}
    string getName(){
	return name;
	}
    int getMarks(){
	return marks;
	}
};

int main() {
    Student s;
    s.setName("Zaheer");
    s.setMarks(87);
    cout << "Student Name : " << s.getName() << endl;
    cout << "Student Marks: " << s.getMarks() << endl;
    return 0;
}
