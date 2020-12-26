/* A pointer to a derived class is type-compatible with a pointer to its base class.
Polymorphism is the art of taking advantage of this feature.
*/
#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	int set_values(int a, int b) { width = a; height = b; };
};

class Rectangle : public Polygon
{
public:
	int area() { return height * width; };
};

class Triangle : public Polygon
{
public:
	int area() { return (width * height) / 2; };
};

int main()
{
	Rectangle rect;
	Triangle trgl;
	Polygon* ppoly1 = &rect;
	Polygon* ppoly2 = &trgl;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	cout << rect.area() << endl; // 20
	cout << trgl.area() << endl; // 10
}