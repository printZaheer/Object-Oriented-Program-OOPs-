#include <iostream>
using namespace std;

struct student {
	int rollno ;
	int marks ;
	float avg;
	char grade ;
};
  void display (student Abbas ){                                          //passing structure to a fuction 
 		cout << "You Entered a following detail of Abbas  \n";
	cout << "Rollno : "<<Abbas.rollno<<endl;
	cout << "Marks : "<< Abbas.marks<<endl;
	cout << "Average : "<< Abbas.avg<<endl;
	cout<< "Grade : "<<Abbas.grade;
 }

int main(){
	student zaheer,Abbas ; 
//	student Abbas={3059,85,72.2,'A'};
	cout<< "Enter  Rollno : ";
	cin >> zaheer.rollno;
	cout<< "Enter  Marks : ";
	cin >> zaheer.marks;
	cout<<"Enter Average : ";
	cin>> zaheer.avg;
	cout<< "Enter Grade:  ";
	cin >> zaheer.grade;
		Abbas =zaheer;                             // used to assiging one variable to another variable of structure
	cout << "You Entered a following detail of Zaheer  \n";
	cout << "Rollno : "<<zaheer.rollno<<endl;
	cout << "Marks : "<< zaheer.marks<<endl;
	cout << "Average : "<< zaheer.avg<<endl;
	cout<< "Grade : "<<zaheer.grade<<endl;
	
	display (Abbas);
	return 0;
}
