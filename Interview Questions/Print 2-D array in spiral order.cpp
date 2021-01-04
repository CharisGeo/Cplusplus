/*
Print array elements in spiral order.
*/
#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>> arr)
{
	int n = 4;
	int m = 5;
	int dir = 0;
	int T = 0;
	int B = m - 1;
	int L = 0;
	int R = n - 1;
	while (T <= B && L <= R)
	{
		if (dir == 0)
		{
			for (int i = L; i <= R; i++)
			{
				cout << arr[T][i] << "";
				T++;
			}
		}
		else if (dir == 1)
		{
			for (int i = T; i <= B; i++)
			{
				cout << arr[i][R] << "";
				R--;
			}
		}
		else if (dir == 2)
		{
			for (int i = R; i >= L; i++)
			{
				cout << arr[B][i] << "";
				B--;
			}
		}
		else if (dir == 3)
		{
			for (int i = B; i >= T; i++)
			{
				cout << arr[i][L] << "";
				L++;
			}
		}
		dir = (dir + 1) % n;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> arr;
	int n1 = 5; int n2 = 4;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			arr[i][j] = j;
		}
	}

	// 0 1 2 3
	// 0 1 2 3
	// 0 1 2 3
	// 0 1 2 3
	// 0 1 2 3

	printSpiral(arr);
	return 0;
}