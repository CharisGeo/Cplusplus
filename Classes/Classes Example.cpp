/* Classes are an expanded concept of data structures: like data structures, they can contain data members,
but they can also contain functions as members.
An object is an instantiation of a class.
*/

#include <iostream>
#include <math.h>       
using namespace std;

/* An access specifier is one of the following three keywords: private, public or protected.
These specifiers modify the access rights for the members that follow them:
1. private members of a class are accessible only from within other members of the same class (or from their "friends").
2. protected members are accessible from other members of the same class (or from their "friends"),
   but also from members of their derived classes.
3. Finally, public members are accessible from anywhere where the object is visible.
*/
class Rectangle
{

    int width, height;
public:
    Rectangle(int a, int b) { width = a; height = b; };
    int area() { return width * height; };
};

class Circle
{
    double radius;
public:
    Circle(double r) { radius = r; };
    double area() { return 3.14159265 * pow(radius, 2); };
};

class Triangle
{
    int base, height;
public:
    Triangle(int a, int b) : base(a), height(b) {}
    int area() { return (base * height) / 2; };
};

class Cylinder
{
    Circle base;
    double height;
public:
    Cylinder(double r, double h) : base(r), height(h) {};
    double volume() { return base.area() * height; };

};

int main() {
    int rect_x, rect_y;
    cout << "Enter dimensions for rectangle: " << endl;
    cin >> rect_x >> rect_y;
    Rectangle rect(rect_x, rect_y);
    cout << "Rectangle's area: " << rect.area() << endl;

    double radius;
    cout << "Enter a radius: " << endl;
    cin >> radius;
    Circle crcl(radius);
    cout << "Circle's area: " << crcl.area() << endl;

    int trngl_x, trngl_y;
    cout << "Enter dimensions for triangle: " << endl;
    cin >> trngl_x >> trngl_y;
    Triangle trngl(trngl_x, trngl_y);
    cout << "Triangle's area: " << trngl.area() << endl;

    Cylinder foo(10, 20);
    cout << "Cylinder's volume: " << foo.volume() << endl;
    return 0;
}