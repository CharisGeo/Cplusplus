#include <iostream>
#include <math.h>       
using namespace std;

class Rectangle
{
    int width, height;
public:
    Rectangle(int a, int b) : width(a), height(b) {};
    int area() { return width * height; };
};

int main() {
    Rectangle rect(5, 4);
    Rectangle* foo, * baz, * col;
    foo = &rect;
    baz = new Rectangle(5, 6);
    col = new Rectangle[2]{ {2,5}, {6,3} };
    cout << "rect's area: " << rect.area() << endl; //20
    cout << "foo's area: " << foo->area() << endl; //20
    cout << "baz's area: " << baz->area() << endl; //30
    cout << "col[0] area: " << col[0].area() << endl; //10
    cout << "col[1] area: " << col[1].area() << endl; //18
    delete baz;
    delete[] col;

    return 0;
}