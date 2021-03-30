#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float x_1, y_1, x_2, y_2;
    while (cin >> x_1 >> y_1 >> x_2 >> y_2)
    {
        cout << setiosflags(ios::fixed) << setprecision(2) << sqrt(pow((x_1 - x_2), 2) + pow((y_1 - y_2), 2)) << endl;
    }
    return 0;
}