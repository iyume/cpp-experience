#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float data;
    while (cin >> data)
    {
        if (data >= 90 && data <= 100)
            cout << 'A' << endl;
        if (data >= 80 && data < 90)
            cout << 'B' << endl;
        if (data >= 70 && data < 80)
            cout << 'C' << endl;
        if (data >= 60 && data < 70)
            cout << 'D' << endl;
        if (data >= 0 && data < 60)
            cout << 'E' << endl;
        if (data < 0 || data > 100)
            cout << "Score is error!" << endl;
    }
    return 0;
}