#include<iostream>
#include<cstring>
using namespace std;

class Person{
	public:
		char* name;
	Person(const char* n){
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	Person(const Person& p){
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

int main(){
	cout << "Deep copy:" << endl;
	Person p1("Zaheer");
	Person p2 = p1;
	strcpy(p2.name, "Hassan");
	cout << "p1: " << p1.name << endl;
	cout << "p2: " << p2.name << endl;

	cout << "Shallow copy:" << endl;
	Person p3("Zaheer");
	Person p4("Temp");
	p4 = p3;
	strcpy(p4.name, "Hassan");
	cout << "p3: " << p3.name << endl;
	cout << "p4: " << p4.name << endl;
	return 0;
}
