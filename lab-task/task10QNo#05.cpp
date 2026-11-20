#include <iostream>
#include <vector>
using namespace std;
class DrawableShape {
public:
    virtual double area() = 0;
    virtual void render() = 0;
    virtual ~DrawableShape() {}
};
class CircleShape : public DrawableShape {
    double radius;
public:
    CircleShape(double r) {
        radius = r;
    }
    double area() {
        return 3.14159 * radius * radius;
    }
    void render() {
        cout << "Drawing circle with radius " << radius << endl;
    }
};
class RectangleShape : public DrawableShape {
    double width, height;
public:
    RectangleShape(double w, double h) {
        width = w;
        height = h;
    }
    double area() {
        return width * height;
    }
    void render() {
        cout << "Drawing rectangle " << width << " x " << height << endl;
    }
};
int main() {
    vector<DrawableShape*> shapes;
    shapes.push_back(new CircleShape(3));
    shapes.push_back(new RectangleShape(4, 5));
    shapes.push_back(new CircleShape(1.5));
    shapes.push_back(new RectangleShape(2, 2));
    double total = 0;
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->render();
        cout << "Area = " << shapes[i]->area() << endl;
        total = total + shapes[i]->area();
    }
    cout << "Total area = " << total << endl;
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    return 0;
}
