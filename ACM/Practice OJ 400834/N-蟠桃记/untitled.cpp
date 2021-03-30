#include <iostream>
using namespace std;

int peach_note(int m)
{
    int peach_sum;
    if (m == 1)
    {
        return 1;
    }
    else
    {
        peach_sum = peach_note(m - 1);
        return (peach_sum + 1) * 2;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << peach_note(n) << endl;
    }
    return 0;
}