/* Friends are functions or classes declared with the friend keyword.
A non-member function can access the private and protected members of a class if it is declared a friend of that class.
Typical use cases of friend functions are operations that are conducted between two different classes accessing private or protected members of both.
*/
#include <iostream>
using namespace std;

class Rectangle
{
	int width, height;
public:
	Rectangle() {};
	Rectangle(int a, int b) { width = a; height = b; };
	int area() { return width * height; };
	friend Rectangle duplicate(const Rectangle&);
};

Rectangle duplicate(const Rectangle& param)
{
	Rectangle foo;
	foo.width = param.width * 2;
	foo.height = param.height * 2;
	return foo;
}

int main()
{
	Rectangle rect(10, 5);
	cout << rect.area() << endl; // 50
	Rectangle rect2;
	rect2 = duplicate(rect);
	cout << rect2.area() << endl; // 200

}