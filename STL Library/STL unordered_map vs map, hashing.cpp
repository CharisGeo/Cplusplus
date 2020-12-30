#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	map<char, int> M;
	unordered_map<char, int> U;

	string s = "Hello there!";
	//add(key,value) - Ordered: logN / Unordered: O(1)
	//erase(key) - Ordered: logN / Unordered: O(1)

	for (char c : s) M[c]++; // O(NlogN)

	for (char c : s) U[c]++; // O(N)

	//Codeforces Array Division
	// https://codeforces.com/contest/808/problem/D
	int n;
	cin >> n;
	vector<int> A(n,0);
	long long S = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		S += A[i];
	}

	if (S & 1)
	{
		cut << "NO" << endl;
		return 0;
	}

	// check if we can divide array to two parts
	map<int, int> first, second;

	first[a[0]] = 1;

	for (int i = 1; i < n; i++)
	{
		second[A[i]]++;
	}

	long long sdash = 0;

	for (int i = 0; i < n; i++)
	{
		sdash += A[i]; // first i numbers
		if (sdash == S / 2)
		{
			cout << "YES" << endl;
			return 0;
		}
		if(sdash < S / 2)
		{
			long long x = S / 2 - sdash;
			//delete element from second half and insert into first half
			if (second[x] > 0)
			{
				cout << "YES" << endl;
				return 0;
			}
			else
			{
				long long y = sdash - (S / 2);
				if (first[y] > 0)
				{
					cout << "YES" << nedl;
					return 0;
				}
			}
		}
		//i+1
		first[A[i]]++;
		second[A[i + 1]]++;
	}
	cout << "NO" << endl;
}