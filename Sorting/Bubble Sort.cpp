/* Bubble Sort:
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Bubble sort is an in place and stable algorithm.
After n -1 passes we are guaranteed to be sorted
Time Complexity: Average case - O(n^2)
				 Best Case - O(n)
				 Worst Case - O(n^2(
*/
#include <iostream>
using namespace std;

void BubbleSort(int A[], int n)
{
	int temp, flag;
	for (int i = 1; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

void Print(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}

int main()
{
	int arr[8] = { 3, 56, 23, 57, 89, 4, 13 , 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	Print(arr, n);
	return 0;
}