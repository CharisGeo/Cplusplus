/* Abstract base classes cannot be used to instantiate objects.
An abstract base class can be used to create pointers to it, and take advantage of all its polymorphic abilities.
*/
#include <iostream>
using namespace std;

class Polygon
{
protected:
    int width, height;
public:
    Polygon(int a, int b) { width = a; height = b; };
    virtual int area(void) = 0; // Notice that area has no definition; this has been replaced by =0, which makes it a pure virtual function. 
                               // Classes that contain at least one pure virtual function are known as abstract base classes.
    void print_area()
    {
        cout << this->area() << endl;
    }
};

class Rectangle : public Polygon {
public:
    Rectangle(int a, int b) : Polygon(a, b) {}
    int area()
    {
        return width * height;
    }
};

class Triangle : public Polygon {
public:
    Triangle(int a, int b) : Polygon(a, b) {}
    int area()
    {
        return width * height / 2;
    }
};

int main() {
    Polygon* ppoly1 = new Rectangle(4, 5);
    Polygon* ppoly2 = new Triangle(4, 5);
    ppoly1->print_area();
    ppoly2->print_area();
    delete ppoly1;
    delete ppoly2;
    return 0;
}