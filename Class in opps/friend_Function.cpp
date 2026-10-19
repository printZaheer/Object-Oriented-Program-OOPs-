#include<iostream>
using namespace std;
class Rectangle{
    private:
    int  length;
    int width;
    public:
    Rectangle(int l, int w){
        length=l;
        width=w;
    }
friend int print_Area(Rectangle r );
};
int print_Area(Rectangle r){
    int area =r.length*r.width;
    return area;
}

int main(){
  Rectangle R(10,5);
  cout << "Area: "<< print_Area(R)<<endl;  
    return 0;
}