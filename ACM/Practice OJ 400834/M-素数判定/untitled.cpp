#include <iostream>
#include <cmath>
using namespace std;

int judge(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int x, y;
    while (cin >> x >> y)
    {
        int count = 0;
        if (x == 0 && y == 0)
            break;
        for (int n = x; n <= y; n++)
        {
            int med = pow(n, 2) + n + 41;
            count += judge(med);
        }
        if (count == y - x + 1)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "Sorry" << endl;
        }
    }
    return 0;
}