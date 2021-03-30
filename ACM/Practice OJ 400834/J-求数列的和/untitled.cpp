#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int m;
    double n, result;
    while (cin >> n >> m)
    {
        result = 0;
        for (int i = 1; i <= m; i++)
        {
            result += n;
            n = sqrt(n);
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << result << endl;
    }
    return 0;
}