/* The keyword this represents a pointer to the object whose member function is being executed. 
It is used within a class's member function to refer to the object itself.
Uses:
1. to check if a parameter passed to a member function is the object itself.
2. frequently used in operator= member functions that return objects by reference
*/
#include <iostream>
using namespace std;

class Dummy
{
public:
    bool isitme(Dummy& param);
};

bool Dummy::isitme(Dummy& param)
{
    if (&param == this)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Dummy a;
    Dummy* b = &a;
    if (b->isitme(a))
    {
        cout << "&a is b"  << endl;
    }
    return 0;
}