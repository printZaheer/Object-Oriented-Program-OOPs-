#include <iostream>
using namespace std;

class Point{
public:
    int x, y;
    Point(){                     // default constructor
        x = 0;
        y = 0;
    }
    Point(int a, int b){
        x = a;
        y = b;
    }
    void show() { 
        cout << "(" << x << ", " << y << ")" << endl;
     }
};
void byValue(Point p) { 
    p.x = 100;
}                                                         // changed  the copy only
void byRef(Point &p) {
     p.x = 100;
     }                                                    // changed the original
Point addPoints(Point a, Point b){ 
    Point r(a.x + b.x, a.y + b.y);
    return r;
}
int main(){
    Point p1(1, 2), p2(3, 4);
    byValue(p1);
    p1.show();                                  // original unchanged
    byRef(p2);
    p2.show();                                  // original changed
    Point p3 = addPoints(p1, p2);
    p3.show();
    return 0;
}