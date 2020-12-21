/* passing by reference: access an external variable from within a function.
passing by value: any modification of the variables within the function has no effect on the values of the variables
outside it, because the variables themselves are not passed to the function on the call, 
but only copies of their values at that moment.*/
#include <iostream>
using namespace std;

void duplicate_ref (int &x, int &y, int &z)
{
    x *= 2;
    y *= 2;
    z *= 2;
}

void duplicate_val (int x, int y, int z)
{
    x *= 2;
    y *= 2;
    z *= 2;
}

int main() {
    //passing by reference
    int x = 1, y = 4, z = 8;
    duplicate_ref(x,y,z); // values duplicated
    cout << x << endl; //2
    cout << y << endl; //8
    cout << z << endl; //16
    //passing by value
    int a = 1, b = 4, c = 8;
    duplicate_val(a,b,c); // values not duplicated
    cout << a << endl; //1
    cout << b << endl; //4
    cout << c << endl; //8
    return 0;
}
