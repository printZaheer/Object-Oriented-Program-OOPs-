#include<iostream>
using namespace std;

class Student {
    private:
    string name;
    const int rollno ;
    public:
    Student( int rol ,string n) : rollno(rol), name (n){           // initilizer list 
    }
    void show()const{                                           // constant member function 
        cout << rollno<<" "<< name<<endl;
    }
    void setName(string n){
        name =n;
    }
};
int main(){
    Student s1(101,"Ali ");
    s1.show();
    s1.setName("Ahmed"); // allowed: s1 is not const
    s1.show();
    const Student s2(102, "Zahra");      //  constant object
    s2.show(); 
    // s2.setName("Batool");           // it will show error because s2 is const

    return 0;
}