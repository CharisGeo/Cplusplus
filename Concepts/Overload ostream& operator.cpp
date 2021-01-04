#include<bits/stdc++.h>

using namespace std;

//Implement the class Box 
class Box
{
private:
    long l, b, h;
    //l,b,h are private integers representing the dimensions of the box

    // The class should have the following functions : 
public:
    // Constructors: 
    // Box(); intialize dimensions to 0
    Box() { l = 0; b = 0; h = 0; };

    // Box(int,int,int); initialize dimensions to length breadth and height
    Box(int length, int breadth, int height)
    {
        l = length; b = breadth; h = height;
    };

    // Box(Box);
    Box(Box& B) { l = B.l; b = B.b; h = B.h; };

    // int getLength(); // Return box's length
    int getLength() { return l; };
    // int getBreadth (); // Return box's breadth
    int getBreath() { return b; };
    // int getHeight ();  //Return box's height
    int getHeight() { return h; };
    // long long CalculateVolume(); // Return the volume of the box
    long long CalculateVolume()
    {
        long long volume;
        volume = l * b * h;
        return volume;
    };

    //Overload operator < as specified
    //bool operator<(Box& b)
    bool operator<(Box& B)
    {
        bool result;
        if (l < B.l)
        {
            result = true;
        }
        else if (l == B.l)
        {
            if (b < B.b)
            {
                result = true;
            }
            else if (b == B.b)
            {
                if (h < B.h)
                {
                    result = true;
                }
                else {
                    result = false;
                }
            }
            else {
                result = false;
            }
        }
        return result;
    };

    //Overload operator << as specified
    //ostream& operator<<(ostream& out, Box& B)
    friend ostream& operator<<(ostream& out, const Box& B)
    {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    };
};


void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

int main()
{
    check2();
}