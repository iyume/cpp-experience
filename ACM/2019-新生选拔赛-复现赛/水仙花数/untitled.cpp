#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int m, n;
    int hundreds, tens, ones, checke;
    while (cin >> m >> n)
    {
        checke = 0;
        for (int i = m; i <= n; i++)
        {
            ones = i % 10;
            tens = i / 10 % 10;
            hundreds = i / 100 % 10;
            if (pow(ones, 3) + pow(tens, 3) + pow(hundreds, 3) == i && checke == 0)
            {
                cout << i;
                checke += 1;
            }
            else if (pow(ones, 3) + pow(tens, 3) + pow(hundreds, 3) == i)
            {
                cout << ' ' << i;
                checke += 1;
            }
        }
        if (checke == 0)
            cout << "no";
        cout << endl;
    }
    return 0;
}