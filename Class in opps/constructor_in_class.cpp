#include <iostream>
#include <string>
using namespace std ;

class Student {
private:
    string name ;
    int age;
public:
    Student (){                              // defalut constructor
        name = "unkown";
        age= 0;
    }
    Student (string nam,int ag ){          // parameterize constructor ( 2 parameter)
        name =nam;
        age =ag;
    }
    Student (string nam){                 // parameterize constructor ( 1 parameter)
        name =nam;
        age =18;
    }
    void display (){
        cout << name << " "<< age << endl;
    }
};
int main (){
    Student s,s1,s2;
    s1={"Zaheer",20};
    s2={"Hassan"};
    s.display();
    s1.display();
    s2.display();
    return 0;
}
