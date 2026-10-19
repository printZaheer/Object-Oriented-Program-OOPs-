#include<iostream>
using namespace std;

class Student {
    private:
    string name;                //  static members are declare inside the  class
    static int  count ;

    public:
    Student(string n){
        name=n;
        count++;
    }
    static int getCount(){       //static function 
        return count;
    }
};
 int Student :: count =0;        // and define or initialize  outside the class

int main(){
    cout << "Count: " << Student::getCount() << endl;
    Student s1("Ali");
    Student s2("Hassan");
    Student s3("Kamran");
    
    cout << "Count: "<< Student :: getCount() << endl;

    return 0;
}