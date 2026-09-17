# include <iostream>
using namespace std ;

struct student{
	string name ;
	int age ;
};

int main (){
	student *ptr=new student ;
	ptr->name="Zaheer";
	ptr->age= 21;
	
	cout << ptr->name<<" "<<ptr->age<<endl;
	delete ptr;
	return 0;
}
