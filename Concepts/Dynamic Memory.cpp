/* Dynamic memory: he memory needs of a program can only be determined during runtime.
For example, when the memory needed depends on user input.
*/
#include <iostream>
#include <new>
using namespace std;

int main() {
    int i, n;
    cout << "How many numbers do you want to enter? " << endl;
    cin >> n;
    int* p = new (nothrow) int[n]; // Dynamic array initialized
    if (p == nullptr)
    {
        cout << "Error in allocating memory!" << endl;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            cout << "Enter a number" << endl;
            cin >> p[i];
        }
        cout << "You have entered: ";
        for (i = 0; i < n; i++)
        {
            cout << p[i] << ", ";
        }
    }
    return 0;
}