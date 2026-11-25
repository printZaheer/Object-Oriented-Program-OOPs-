#include<iostream>
using namespace std;
class Base{
    public:
    Base (){
        cout<<"Base created."<<endl;
    }
    virtual~Base(){
        cout <<"Base distroyed."<<endl;
    }
};
class Derived:public Base{
    int * data;
    public:
    Derived(){
        data =new int [5];
        cout <<"Derived created."<<endl;
    }
    ~Derived(){
        delete[] data;
        cout << "Derived destroyed."<<endl;
    }
};

int main(){
    Base *p=new Derived;
    delete p;
    return 0;
}