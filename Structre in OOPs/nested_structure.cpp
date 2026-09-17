#include <iostream>
using namespace std ;

struct Date {
	int day, mounth, year ;
};
struct student{
	string name ;
	Date dob;
};

int main (){
	student s1,s2;
	cout <<"Enter the name : ";
	cin >> s1.name;
	cout << "Enter the dob(DD-MM-YY): ";
	cin >> s1.dob.day>>s1.dob.mounth>> s1.dob.year;
	cout <<"Enter the name : ";
	cin >> s2.name;
	cout << "Enter the dob(DD-MM-YY): ";
	cin >> s2.dob.day>>s2.dob.mounth>> s2.dob.year;
	
	cout << "You entered the following details:-\n";

	cout << "The name of s1 is : "<< s1.name<<endl;
	cout << "The dob of s1 is : "<< s1.dob.day<<"-"<<s1.dob.mounth<<"-"<<s1.dob.year<<endl;
	cout << "The name of s2 is : "<< s2.name<<endl;
	cout << "The dob of s2 is : "<< s2.dob.day<<"-"<<s2.dob.mounth<<"-"<<s2.dob.year;
	
	
	return 0;
}
