/* Just like we can create function templates, we can also create class templates,
allowing classes to have members that use template parameters as types.
*/
#include <iostream>
using namespace std;

template <class T>
class  mypair
{
	T a, b;
public:
	mypair(T val1, T val2) { a = val1; b = val2; };
	T getmax();
};

template <class T>
T mypair<T>::getmax()
{
	T value;
	value = a > b ? a : b;
	return value;
}


int main()
{
	mypair <int> foo(100, 75);
	auto result = foo.getmax();
	cout << result << endl; //100
	return 0;
}