/* A static data member of a class is one common variable for all the objects of that same class, sharing the same value:
i.e., its value is not different from one object of this class to another.
Example: Global Class Objects counter
*/
#include <iostream>
using namespace std;

class Dummy
{
public:
	static int n;
	Dummy() { n++; };
};

int Dummy::n = 0; //to avoid them being declared several times, they cannot be initialized directly in the class, but need to be initialized somewhere outside it

int main()
{
	Dummy a;
	Dummy b[5];
	cout << a.n << endl; //6
	Dummy* c = new Dummy;
	cout << Dummy::n << endl; //7
	delete c;
	return 0;
}