/* A data structure is a group of data elements grouped together under one name.
These data elements, known as members, can have different types and different lengths.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//array of structures
struct film
{
    string title;
    int year;
}movies[3];

void printmovie(film movie)
{
    cout << movie.title;
    cout << "(" << movie.year << ")" << endl;
}

int main() {
    string mystr;
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a movie: " << endl;
        getline(cin, movies[i].title);
        cout << "Enter a year: " << endl;
        getline(cin, mystr);
        stringstream(mystr) >> movies[i].year;
    }

    cout << "You have entered these movies: " << endl;
    for (int i = 0; i < n; i++)
        printmovie(movies[i]);


    return 0;
}