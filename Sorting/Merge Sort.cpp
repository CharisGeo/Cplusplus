/* Merge Sort:
 Merge Sort is a Divide and Conquer algorithm.
 It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
 The merge() function is used for merging two halves.
 The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
 Time complexity: O(nlogn)
*/
#include <iostream>
using namespace std;

void Merge(long int Left[], long int Right[], long int A[], int n_L, int n_R)
{
    int i, j, k = 0;
    while (i < n_L && j < n_R)
    {
        if (Left[i] < Right[j])
        {
            A[k] = Left[i];
            i += 1;
        }
        else
        {
            A[k] = Right[j];
            j += 1;
        }
        k += 1;
    }
    while (i < n_L) // check if subarrays have leftovers or not
    {
        A[k] = Left[i];
        i += 1;
        k += 1;
    }
    while (j < n_R)
    {
        A[k] = Right[i];
        j += 1;
        k += 1;
    }
}

void MergeSort(long int A[], long int n)
{
    if (n < 2)
    {
        return; // exit condition
    }
    long int mid = n / 2;
    long int L[mid];
    long int R[n - mid];
    for (int i = 0; i < mid; i++)
    {
        L[i] = A[i]; // create left subarray
    }
    for (int i = mid; i < n; i++)
    {
        R[i - mid] = A[i]; // create right subarray
    }
    MergeSort(L, mid); // recursive call - sort the left subarray
    MergeSort(R, n - mid); // recursive call - sort the right subarray
    Merge(L, R, A, mid, n - mid); // merge sorted halves
}

void Print(long int A[], long int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    long int arr[6] = { 65,32,6,7,16,0 };
    long int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, n);
    Print(arr, n);
    return 0;
}