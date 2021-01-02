/* Exception Example:
- Read a string and print its integer value; if cannot be converted to an integer, print Bad String.
*/
#include <iostream>
using namespace std;

int main()
{
	string mystr;
	cout << "Enter string: " << endl;
	cin >> mystr;

	try {
		int a = stoi(mystr); // try to convert string to integer
		cout << a << endl;
	}
	catch (exception a)
	{
		cout << "Bad String" << endl; // cout bad string if conversion is not possible
	}
}