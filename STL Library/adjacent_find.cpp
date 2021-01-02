/* Check if a vector of integers has any duplicates or not, and return true if it does.
* std::adjacent_find *
1. std::adjacent_find doesn't modify the container.
2. std::adjacent_find returns an iterator to the first element in the duplicate "pair"
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // The container must be sorted!
    const vector<int> sortedVector = { 1,2,3,3,4,5 };
    const bool hasDuplicates = adjacent_find(sortedVector.begin(), sortedVector.end()) != sortedVector.end();
    if (hasDuplicates == true)
    {
        cout << "Duplicates detected." << endl;
    }
    else
    {
        cout << "No Duplicates detected." << endl;
    }

    // more uses
    vector<int> v1{ 0, 1, 2, 3, 40, 40, 41, 41, 5 };

    auto i1 = adjacent_find(v1.begin(), v1.end());

    if (i1 == v1.end()) {
        cout << "no matching adjacent elements\n";
    }
    else {
        cout << "the first adjacent pair of equal elements at: "
            << distance(v1.begin(), i1) << '\n';
    }

    auto i2 = adjacent_find(v1.begin(), v1.end(), greater<int>());
    if (i2 == v1.end()) {
        cout << "The entire vector is sorted in ascending order\n";
    }
    else {
        cout << "The last element in the non-decreasing subsequence is at: "
            << distance(v1.begin(), i2) << '\n';
    }
}