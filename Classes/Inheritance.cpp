/*Inheritance involves a base class and a derived class.
The derived class inherits the members of the base class, on top of which it can add its own members
This access specifier limits the most accessible level for the members inherited from the base class:
The members with a more accessible level are inherited with this level instead,
while the members with an equal or more restrictive access level keep their restrictive level in the derived class.
When a class inherits another one, the members of the derived class can access the protected members inherited from the base class, but not its private members.
In principle, a publicly derived class inherits access to every member of a base class except:

 1. its constructors and its destructor
 2. its assignment operator members (operator=)
 3. its friends
 4. its private members
 Unless otherwise specified, the constructors of a derived class calls the default constructor of its base classes (i.e., the constructor taking no arguments).
 Calling a different constructor of a base class is possible.
*/
#include <iostream>
using namespace std;

class Mother
{
public:
    Mother() { cout << "Mother:no parameters" << endl; }
    Mother(int a) { cout << "Mother:int parameter" << endl; }
};

class Daughter : public Mother
{
public:
    Daughter(int a) { cout << "Daughter:int parameter" << endl; }
};

class Son : public Mother
{
public:
    Son(int a) : Mother(a)
    {
        cout << "Son:int parameter" << endl;
    }
};

int main()
{
    Daughter Sara(0);
    // Mother:no parameters                                                                                                                         
    // Daughter:int parameter 
    Son Bob(0);
    // Mother:int parameter
    // Son : int parameter
    return 0;
}