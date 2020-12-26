/* A class may inherit from more than one class by simply specifying more base classes, separated by commas, in the list of a class's base classes.
For example, if the program had a specific class to print on screen called Output,
and we wanted our classes Rectangle and Triangle to also inherit its members in addition to those of Polygon.
*/
#include <iostream>
using namespace std;

class Polygon
{
public:
	Polygon(int a, int b) { width = a; height = b; };
protected:
	int width, height;
};

class Output
{
public:
	static void print(int i);
};

void Output::print(int i)
{
	cout << i << endl;
}

class Rectangle : public Polygon, public Output
{
public:
	Rectangle(int a, int b) : Polygon(a, b) {
		width = a; height = b;
	};
	int area() { return width * height; };

};

class Triangle : public Polygon, public Output
{
public:
	Triangle(int a, int b) : Polygon(a, b) {
		width = a; height = b;
	};
	int area() { return (width * height) / 2; };
};

int main()
{
	Rectangle rect(4, 5);
	Triangle trgl(4, 5);
	rect.print(rect.area()); // 20
	Triangle::print(trgl.area()); // 10
	return 0;
}