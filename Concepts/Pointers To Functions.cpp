/* Pointer functions: for passing a function as an argument to another function.
*/
#include <iostream>
using namespace std;

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int operation(int x, int y, int (*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return g;

}

int main() {
    int m, n;
    int (*minus)(int, int) = subtraction; //minus is a pointer to a function that has two parameters of type int.
                                          //It is directly initialized to point to the function subtraction

    m = operation(20, 10, addition); //30
    n = operation(50, m, minus); //20
    cout << n;

    return 0;
}