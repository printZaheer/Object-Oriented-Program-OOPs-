//*********************Simple Run time /Dynamic  Polymorphism example ************************
#include<iostream>
using namespace std;
class Shape {
    public:
    virtual void show (){
        cout<<"Drawing a shape "<<endl;
    } 
};
class Circle : public Shape {
public :
void show (){
    cout << "Drawing a Circle "<< endl;  // it will run this because base pointer points to a derived object   
}
};
int main(){
    Circle c;
    Shape *s= &c;     // base pointer points to a derived object 
    s->show();
    return 0;
}