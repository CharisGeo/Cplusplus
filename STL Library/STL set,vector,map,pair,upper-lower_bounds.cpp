#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std;

bool f(int x, int y)
{
	return x > y;
}

void vectorDemo()
{
	vector<int> A = { 11,2,3,14 };

	cout << A[1] << endl;
	sort(A.begin(), A.end()); // O(NlogN)

	bool present = binary_search(A.begin(), A.end(), 2); // true - O(NlogN)
	present = binary_search(A.begin(), A.end(), 5); // false

	A.push_back(100);
	//present = binary_search(A.begin, A.end(), 100); // true

	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);
	//2,3,11,14,100,100,100,100,100,123

	// find first occurence of 100
	vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // >= (index = 5)
	auto it2 = upper_bound(A.begin(), A.end(), 100); // > first element which is strictly greater (index = end (123))

	cout << *it << " " << *it2 << endl;
	cout << it2 - it << endl; //5 indices difference - O(1) time (5 is also the count of 100's in vector)

	//sort vector in reverse order
	sort(A.begin(), A.end(), f); // f is comparator function - returns true or false

	//Print vector using iterator
	vector<int>::iterator it3;
	for (it3 = A.begin(); it3 != A.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;

	// Iterate by reference on a vector
	for (int& x : A)
	{
		x++;
	}
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;
}

void setDemo()
{
	set<int> S;
	S.insert(1); // Insert operation is O(NlogN)
	S.insert(2); // set maintains ascending order (advantage over vector)
	S.insert(-1);
	S.insert(-10);

	for (int x : S)
	{
		cout << x << " ";
	}
	cout << endl;

	//-10 -1 1 2
	auto it = S.find(-1);
	// if element is not present: it == S.end()
	if (it == S.end())
	{
		cout << "Value not present" << endl;
	}
	else
	{
		cout << "Present" << endl;
		cout << *it << endl;
	}

	// Find the first number in the set which is greater or equal than -1
	auto it2 = S.lower_bound(-1);
	// Find the first number in the set which is  strictly greater than -1
	auto it3 = S.upper_bound(-1); //1
	cout << *it2 << *it3 << endl;

	// Try to find upper bound of 2 which doe not exist in this case
	auto it4 = S.upper_bound(2); // will return S.end();
	if (it4 == S.end())
	{
		cout << "Cant find this value!" << endl;
	}
}

void mapDemo()
{
	map<int, int> A;
	A[1] = 100;
	A[2] = -1;
	A[3] = 200;
	A[102341] = 1;

	map<char, int> cnt;
	string x = "you lost";

	for (char c : x)
	{
		cnt[c]++;
	}

	cout << cnt['o'] << " " << cnt['z'] << endl;

}

void PowerOfStl()
{
	// shout intervals problem
	set<pair<int, int>> S;

	S.insert({ 2,3 });
	S.insert({ 10,20 });
	S.insert({ 30,400 });
	S.insert({ 401,450 }); //pairs also stored in ascending order automatically

	int point = 1;
	auto it = S.upper_bound({ point, INT_MAX });
	if (it == S.begin())
	{
		cout << "The given point is not lying in any interval. " << endl;
		return;
	}

	it--;
	pair<int, int> current = *it;
	if (current.first <= point && point <= current.second)
	{
		cout << "Yes, it is present" << current.first << " " << current.second << endl;
	}
	else
	{
		cout << "The given point is not lying in any interval. " << endl;
	}

}

int main()
{
	vectorDemo();
	setDemo();
	mapDemo();
	PowerOfStl();
}
