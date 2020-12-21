/*stringstream allows extraction or insertion operations 
from/to strings in the same way as they are performed on cin and cout.
Useful for converting strings to numerical values and vice versa. */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string mystr;
	float price;
	int quantity;

	cout << "Enter price: " << endl;
	getline(cin, mystr); //get an entire line from cin ignoring spaces
	stringstream(mystr) >> price;
	cout << "Enter quantity: " << endl;
	getline(cin, mystr);
	stringstream(mystr) >> quantity;
	cout << "Total price: " << price * quantity << endl;
	return 0;
}