#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double r, pi = 3.1415927;
    while (cin >> r)
    {
        cout << setiosflags(ios::fixed) << setprecision(3) << double(4) / double(3) * pi * pow(r, 3) << endl;
    }
    return 0;
}