#include <iostream>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    Point(int x,int y){
    this->x=x;
    this->y=y;
   }
    void show(){
    cout<<"Point("<<x<<", "<<y<<")"<<endl;
   }
};
int main(){
    Point p(3,7);
    p.show();
    return 0;
}
