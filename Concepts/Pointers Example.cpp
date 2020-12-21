/*Pointer: variable that stores the address of another variable.
Constant pointer: can access the pointed value to read it, but not to modify it.
Pointers can also be themselves const.
*/
#include <iostream>
using namespace std;

void increment_all(int* start, int* end)
{
    int* current = start;
    while (current != end)
    {
        (*current)++; //increment value pointed
        current++; //increment pointer
    }
}

void print_all(int* start, int* end)
{
    const int* current = start; // non-const pointer to const int
    while (current != end)
    {
        cout << *current << endl;
        current++; // increment pointer
    }
}

int main() {
    int arr[] = { 10, 100, 1000, 10000, 100000 };
    increment_all(arr, arr + 5);
    print_all(arr, arr + 5); // 11 101 1001 10001 100001
    return 0;
}