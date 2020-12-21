/* Overloaded functions: two functions with the same name but with entirely different definitions
Function templates: define functions with generic types */
#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b)
{
    T result;
    result = a + b;
    return result;
}

int main() {
    int a = 2, b = 4;
    double k = 2.13, l = 4.56;
    int integer_answer = sum(a, b);
    double double_answer = sum(k, l);
    cout << integer_answer << endl;
    cout << double_answer << endl;
    return 0;
}