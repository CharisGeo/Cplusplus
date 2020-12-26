/* A virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.
The syntax for a function to become virtual is to precede its declaration with the virtual keyword
A class that declares or inherits a virtual function is called a polymorphic class.
*/
#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	int set_values(int a, int b) { width = a; height = b; };
	virtual int area() { return 0; }; // if virtual is removed from the declaration of area all three calls to area would return zero,
	                                  // because in all cases, the version of the base class would have been called instead.
};

class Rectangle : public Polygon
{
public:
	int area() { return width * height; };
};

class Triangle : public Polygon
{
public:
	int area() { return (width * height) / 2; };
};

int main()
{
	Polygon poly;
	Rectangle rect;
	Triangle trgl;
	Polygon* ppoly1 = &poly;
	Polygon* ppoly2 = &rect;
	Polygon* ppoly3 = &trgl;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly3->set_values(4, 5);
	cout << ppoly1->area() << endl; //0
	cout << ppoly2->area() << endl; // 5
	cout << ppoly3->area() << endl; // 1
	return 0;
}