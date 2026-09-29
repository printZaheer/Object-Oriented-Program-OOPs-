#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    double x;
    double y;
};
double distanceBetween(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
Point midpoint(Point p1, Point p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2.0;
    mid.y = (p1.y + p2.y) / 2.0;
    return mid;
}
int main() {
    Point a = { 2.0, 3.0 };
    Point b = { 8.0, 11.0 };
    cout << "Distance between A and B: " << distanceBetween(a, b) << endl;
    Point m = midpoint(a, b);
    cout << "Midpoint: (" << m.x << ", " << m.y << ")" << endl;
    return 0;
}

