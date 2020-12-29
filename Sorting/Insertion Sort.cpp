/* Selection Sort:
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct position in the sorted part.
Time Complexity: Best case - O(n)
				 Worst case (Reverse sorted array) - O(n^2)
				 Average case - O(n^2)
*/
#include <iostream>
using namespace std;

void InsertionSort(int A[], int n)
{
	int value, hole;
	for (int i = 1; i < n; i++)
	{
		value = A[i];
		hole = i;
		while (hole > 0 && A[hole - 1] > value)
		{
			A[hole] = A[hole - 1];
			hole -= 1;
		}
		A[hole] = value;
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
	int arr[5] = { 1001,32, 314, 653,21 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertionSort(arr, n);
	Print(arr, n);
	return 0;
}