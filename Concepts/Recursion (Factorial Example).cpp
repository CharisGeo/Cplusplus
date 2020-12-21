/* Recursivity is the property that functions have to be called by themselves.
It is useful for some tasks, such as sorting elements, or calculating the factorial of numbers.*/
#include <iostream>
using namespace std;

int factorial(int a)
{
    int answer = 0;
    if (a == 1)
    {
        answer = 1;
    }
    else
    {
        answer = a * factorial(a - 1);
    }
    return answer;
}

int main() {
    int d;
    cout << "Enter a number: " << endl;
    cin >> d;
    int result = factorial(d);
    cout << "Factorial of: " << d << " is: " << result << endl;
    return 0;
}