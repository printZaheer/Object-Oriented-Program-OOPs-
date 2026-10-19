#include <iostream>
#include <string>
using namespace std;

class Student{
private:
	string name;
	int rollNumber;
	string section;
	float cgpa;
public:
	Student(){                                                  // default constructor 
		name = "NULL";
		rollNumber = 0;
		section = "NULL";
		cgpa = 0;
	}
	Student(string n, int roll, string sec, float cg){          //parameterized constructor
		name = n;
		rollNumber = roll;
		section = sec;
		cgpa = cg;
	}
	void insert(){
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter roll: ";
		cin >> rollNumber;
		cout << "Enter section: ";
		cin >> section;
		cout << "Enter cgpa: ";
		cin >> cgpa;
	}
	void print(){
		cout << "Name: " << name << endl;
		cout << "Roll Number: " << rollNumber << endl;
		cout << "Section: " << section << endl;
		cout << "CGPA: " << cgpa << endl;
	}
};
int main(){
	Student s1("zaheer", 3058, "SE-3A", 2.7);
	Student s2;
	s2.insert();
	cout <<endl<< "Student 1  detail" << endl;
	s1.print();
	cout << "Student 2 detail" << endl;
	s2.print();

	return 0;
}
