#include<iostream>
using namespace std;
class Shape {
    public:
    virtual void draw(){
        cout << "Draw a Shape."<<endl;
    }
};
class Circle: public Shape {
    public:
    void draw()override {
        cout <<"Draw a Circle."<<endl;
    }
};
class Square : public Shape{
    public :
    void draw ()override {
        cout <<"Draw a Square."<<endl;        
    }
};
class Rectangle : public Shape{
    public:
    void draw () override{
        cout << "Draw a Rectangle."<<endl;
    } 
};
class Triangle : public Shape{
    public:
    void draw ()override {
        cout <<"Draw a Trianle."<<endl;
    }
};
int main(){
    Shape s;
    Circle c;
    Square q;
    Rectangle r;
    Triangle t;

    Shape *list[5] = {&s, &c, &q, &r, &t};
    //list[5]= { &s, &c, &q, &r, &t};                 // Error
    for(int i =0; i<5 ; i++){
        list[i]->draw();
    }
    return 0;
}