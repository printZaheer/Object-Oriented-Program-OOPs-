#include<iostream>
using namespace std;
class Plant {
    public:
     virtual void  grow(){
        cout << "Plants are growing ...."<<endl;
    }
};
class Mango : public Plant{
    public:
    void grow() override{
        cout << "Mango plants grow and produce Mangoes"<<endl;
    }
};
class Banana: public Plant {
    public:
    void grow ()override{
        cout << "Banana plants grow and produce Bananas"<<endl;
    }
};
int main(){
    Plant p1,*p2;
    p1.grow();                  //normal
    p1.Plant::grow();          // use scope resolution ::  operator to access the hidden based class
    Mango m;
    Banana b;
    p2 = &m;
    p2->grow();
    p2=&b;
    p2->grow();
   
    return 0;
}