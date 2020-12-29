/* Quick Sort:
QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
Frequently used in language library sort.
Efficient, in place algorithm.
Pivot selection is up to user e.g always pick right-most element.
Time complexity: Average or Best Case - O(nlogn)
			     Worst Case - O(n^2);
*/
#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int* A, int start, int end)
{
	int pivot = A[end];
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		if (A[i] <= pivot)
		{
			swap(A[i], A[pIndex]); // swap if element is lesser than pivot
			pIndex += 1;
		}
	}
	swap(A[pIndex], A[end]); // swap pivot with element at partition index
	return pIndex;
}

void QuickSort(int* A, int start, int end)
{
	if (start < end)
	{
		int pIndex = Partition(A, start, end);
		QuickSort(A, start, pIndex - 1);
		QuickSort(A, pIndex + 1, end);
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
	int arr[] = { 8,5,1,65,15,34,12,98,65 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, start, end);
	Print(arr, end);
	return 0;
}