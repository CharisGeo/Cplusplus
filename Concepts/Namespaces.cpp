/* Namespaces allow us to group named entities that otherwise would have global scope
into narrower scopes, giving them namespace scope.
Namespaces are particularly useful to avoid name collisions.*/
#include <iostream>
using namespace std;

namespace first
{
    int x = 5;
    int y = 10;
}

namespace second
{
    double x = 5.45;
    double y = 8.76;
}

int main() {
    using namespace first; //by declaring using namespace first, uses of x and y without name qualifiers were also looked up in namespace first.
    cout << x << endl;
    cout << y << endl;
    cout << second::x << endl;
    cout << second::y << endl;
    return 0;
}