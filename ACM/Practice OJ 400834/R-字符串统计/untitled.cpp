#include <iostream>
using namespace std;

int main()
{
    int m, i;
    char c;
    int count;
    cin >> m;
    getchar();
    while (m--)
    {
        count = 0;
        c = getchar();
        while (c != 10)
        {
            if (c >= '0' && c <= '9')
            {
                count++;
            }
            c = getchar();
        }
        cout << count << endl;
    }
    return 0;
}