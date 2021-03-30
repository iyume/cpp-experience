#include <iostream>
using namespace std;

int main()
{
    int n, *n_list;
    while (cin >> n)
    {
        int min, min_sub, t;
        n_list = new int[n];
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> n_list[i];
        min = n_list[0];
        for (int i = 0; i < n; i++)
        {
            if (min > n_list[i])
                min = n_list[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (min == n_list[i])
                min_sub = i;
        }
        t = n_list[0];
        n_list[0] = min;
        n_list[min_sub] = t;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                cout << n_list[i] << ' ';
            }
            else
            {
                cout << n_list[i] << endl;
            }
        }
    }
    return 0;
}