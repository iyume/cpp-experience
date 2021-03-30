#include <iostream>
#include <iomanip>
using namespace std;

double sum(double num)
{
    double result = 0;
    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            result -= double(1) / i;
        if (i % 2 == 1)
            result += double(1) / i;
    }
    return result;
}

int main()
{
    int m, *n_list;
    while (cin >> m)
    {
        n_list = new int[m];
        for (int i = 0; i <= m - 1; i++)
        {
            cin >> n_list[i];
            cout << setiosflags(ios::fixed) << setprecision(2) << sum(n_list[i]) << endl;
        }
    }
    return 0;
}