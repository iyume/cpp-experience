#include <iostream>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (m == 3)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == n)
                {
                    for (int a = 1; a <= n * 2 - 1; a++)
                        cout << '*';
                    cout << endl;
                }
                else
                {
                    for (int j = 1; j < i; j++)
                    {
                        cout << ' ';
                    }
                    cout << '*';
                    for (int j = n - 1; j > i; j--)
                    {
                        cout << ' ';
                    }
                    cout << '*';
                    for (int j = n - 1; j > i; j--)
                    {
                        cout << ' ';
                    }
                    cout << '*' << endl;
                }
            }
            for (int i = n - 1; i >= 1; i--)
            {
                for (int j = 1; j < i; j++)
                {
                    cout << ' ';
                }
                cout << '*';
                for (int j = n - 1; j > i; j--)
                {
                    cout << ' ';
                }
                cout << '*';
                for (int j = n - 1; j > i; j--)
                {
                    cout << ' ';
                }
                cout << '*' << endl;
            }
        }
        if (m == 2)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == n)
                {
                    for (int j = 1; j <= n - 1; j++)
                        cout << ' ';
                    cout << '*';
                    cout << endl;
                }
                else
                {
                    for (int j = 1; j < i; j++)
                    {
                        cout << ' ';
                    }
                    cout << '*';
                    for (int j = n - 1; j > i; j--)
                    {
                        cout << ' ';
                    }
                    cout << ' ';
                    for (int j = n - 1; j > i; j--)
                    {
                        cout << ' ';
                    }
                    cout << '*' << endl;
                }
            }
            for (int i = n - 1; i >= 1; i--)
            {
                for (int j = 1; j < i; j++)
                {
                    cout << ' ';
                }
                cout << '*';
                for (int j = n - 1; j > i; j--)
                {
                    cout << ' ';
                }
                cout << ' ';
                for (int j = n - 1; j > i; j--)
                {
                    cout << ' ';
                }
                cout << '*' << endl;
            }
        }
        if (m == 1)
        {
            for (int i = 1; i <= n * 2 - 1; i++)
            {
                if (i == n)
                {
                    for (int j = 1; j <= n * 2 - 1; j++)
                        cout << '*';
                    cout << endl;
                }
                else
                {
                    for (int j = 1; j <= n - 1; j++)
                        cout << ' ';
                    cout << '*';
                    cout << endl;
                }
            }
        }
    }
    return 0;
}