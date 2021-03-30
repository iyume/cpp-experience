#include <iostream>
using namespace std;

int main()
{
    int n, *num_array;
    while (cin >> n)
    {
        num_array = new int[n];
        int result = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> num_array[i];
            if (num_array[i] % 2 == 1)
            {
                result *= num_array[i];
            }
        }
        cout << result << endl;
    }
    return 0;
}