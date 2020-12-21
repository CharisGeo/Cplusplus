/* Structures can be pointed to by its own type of pointers.
a.b = member b of object
a->b = member b of any object pointed to by a = (*a).b
*a.b = value pointed to by member b of object a = *(a.b)
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t
{
    string title;
    int year;
};

int main() {
    string mystr;

    movies_t movie;
    movies_t* pmovie = &movie; //pointer to newly created structure named movie

    cout << "Enter a movie: " << endl;
    getline(cin, pmovie->title); //The arrow operator (->) serves to access the member of an object directly from its address
    cout << "Enter a year: " << endl;
    getline(cin, mystr);
    stringstream(mystr) >> pmovie->year;

    cout << "You have entered: " << endl;
    cout << pmovie->title << "(" << pmovie->year << ")" << endl;

    return 0;
}