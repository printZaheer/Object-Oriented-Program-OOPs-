#include <iostream>
#include <string>
using namespace std;

class human 
{
    private:
        char gender;
        int  age ;      

    public :
        string  name , religion,country;
        int lucky_number;

        void setData(char g, int a);//g-->Gender,a--->age
        void getData();
};
void human :: setData(char gen,int ag){
    gender  = gen;
    age = ag;
}
void human :: getData(){
    cout<<name<<":\n";
    cout<<"\tGender :"<<gender<<endl;
    cout << "\t Age  :" << age<<endl;
    cout << "\tCountry :" << gender<<endl;
    cout << "\treligion :" << religion<<endl;
}

int main (){
    human Ali, Noor ,Parkash;
    Ali.name = "Ali";
    Ali.religion = "Islam";
    Ali.country = "Pakistan";
    Ali.lucky_number = 7;

    Ali.setData('M', 20);

    Ali.getData();

    Noor.name = "Noor";
    Noor.religion = "Islam";
    Noor.country = "Iran";
    Noor.lucky_number = 4;

    Noor.setData('F', 15);

    Noor.getData();

    Parkash.name = "Parkash";
    Parkash.religion = "Hindu";
    Parkash.country = "India";
    Parkash.lucky_number = 5;

    Parkash.setData('M', 32);

    Parkash.getData();
    return 0;
}

