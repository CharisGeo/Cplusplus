/*When an object of a class is qualified as a const object the access to its data members from outside the class is restricted to read-only.
The constructor is still called and is allowed to initialize and modify these data members.
const members shall not modify the state of an object.
non-const objects are not restricted and thus can access both const and non-const member functions alike.
Most functions taking classes as parameters actually take them by const reference, and thus, these functions can only access their const members.
*/
#include <iostream>
using namespace std;

class MyClass
{
public:
	int x;
	MyClass(int val) { x = val; };
	void get() { cout << x; }; // this function cannot be called from foo
	void get() const { cout << x; }; //this function can be called from foo
	const int& print() const { return x; };
};

void Print(const MyClass& param)
{
	cout << param.print() << endl;
}

int main()
{
	const MyClass foo(10);
	//foo.x = 20 not valid operation
	cout << foo.x << endl; // 10
	foo.get();//10 //The member functions of a const object can only be called if they are themselves specified as const members
	cout << endl;
	MyClass non_constant(30);
	Print(non_constant); // 30
	return 0;
}