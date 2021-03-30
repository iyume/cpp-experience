#include <iostream>
using namespace std;

int main()
{
    int n, m, *n_list;
    while (cin >> n >> m)
    {
        n_list = new int[n];
        for (int i = 0; i < n; i++)
            n_list[i] = (i + 1) * 2;
        int count = n / m;
        int latter = n % m;
        for (int c = 0; c < count; c++)
        {
            int seq_sum = 0;
            for (int i = m * c; i < m * c + m; ++i)
            {
                seq_sum += n_list[i];
            }
            if (n == m)
            {
                cout << seq_sum / m;
            }
            else
            {
                if (latter == 0 && c == count - 1)
                {
                    cout << seq_sum / m;
                }
                else
                {
                    cout << seq_sum / m << ' ';
                }
            }
        }
        if (latter == 0)
        {
            cout << endl;
        }
        else
        {
            int latter_sum = 0;
            for (int i = 0; i < latter; i++)
            {
                latter_sum += n_list[n - latter + i];
            }
            cout << latter_sum / latter << endl;
        }
    }
    return 0;
}