/* An enum variable takes only one value out of many possible values.
Enum is a good choice whwn working with flags.
*/
#include <iostream>
using namespace std;

enum seasons { spring = 10, summer = 40, autumn = 20, winter = 30 };

enum designFlags {
    BOLD = 1,
    ITALICS = 2,
    UNDERLINE = 4
};

int main() {
    seasons s;
    s = summer;
    cout << s << endl; //40

    int myDesign = BOLD | UNDERLINE;
    cout << myDesign; //When the output is 5, you always know that bold and underline is used.

    return 0;
}