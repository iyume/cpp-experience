#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double data;
    while (cin >> data)
    {
        cout << setiosflags(ios::fixed) << setprecision(2) << abs(data) << endl;
    }
    return 0;
}