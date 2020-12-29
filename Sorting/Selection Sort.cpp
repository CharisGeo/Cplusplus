/* Selection Sort:
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
Time Complexity: O(n^2) 
*/
#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
	int temp, iMin;
	for (int i = 0; i < n - 1; i++) // We need to do n - 2 passes since last element will be sorted anyway
	{
		iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[iMin])
			{
				iMin = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[iMin];
		arr[iMin] = temp;
	}
}

void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[6] = { 5,43,23,32,17,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectionSort(arr, n);
	Print(arr, n);
	return 0;
}