# include <iostream>
using namespace std ;

struct student {
	string name ;
	int rollno;
	float gpa ;
};

int main (){
	student s[3];
	for (int i=0; i<3;i++){
		cout <<"Enter Name,Rollno and Gpa of student"<<i+1<<": ";
		cin>> s[i].name>>s[i].rollno>>s[i].gpa;
	}
	cout << "You entered the following detail : \n";
	for (int i=0 ;i<3;i++){
		cout<<"The  Name of student"<<i+1<<" is :  " <<s[i].name<<endl;
		cout<<"The Rollno of student"<<i+1<<" is :  "<<s[i].rollno<<endl;
		cout<<"The Gpa is of student"<<i+1<<" is :  " <<s[i].gpa<<endl;
		
	}
		return 0;
}


//**********************Another Method*****************************
//#include <iostream>
//using namespace std;
//
//struct Student {
//    string name;
//    int marks;
//};
//
//int main() {
//    Student s[5];  // array of 3 students
//    for (int i = 0; i < 5; i++) {
//        cout << "Enter name and marks of student " << i + 1 << ": ";
//        cin >> s[i].name >> s[i].marks;
//    }
//    cout << "\n--- Student Records ---\n";
//    for (int i = 0; i < 5; i++) {
//        cout << s[i].name << " - " << s[i].marks << endl;
//    }
  //  return 0;
//}
	

