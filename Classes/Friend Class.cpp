/* Similar to friend functions, a friend class is a class whose members have access to the private or protected members of another class.
Another property of friendships is that they are not transitive: The friend of a friend is not considered a friend unless explicitly specified.
*/
#include <iostream>
#include <math.h>
using namespace std;

class Square; //This is necessary because class Rectangle uses Square

class Rectangle
{
	int width, height;
public:
	Rectangle() {};
	int area() { return width * height; };
	void convert(Square param);
};

class Square
{
	friend class Rectangle; // the member functions of Rectangle can access the protected and private members of Square but not the other way around
private:
	int side;
public:
	Square() {};
	Square(int a) { side = a; };
	int area() { return pow(side, 2); };
};

void Rectangle::convert(Square param)
{
	width = param.side;
	height = param.side;
}

int main()
{
	Square sqr(4);
	cout << sqr.area() << endl; // 16
	Rectangle rect;
	rect.convert(sqr);
	cout << rect.area() << endl; // 16
	return 0;
}