#include <iostream>
using namespace std;

int main()
{
    float *num_array;
    int n, minus, zero, positive;
    while (cin >> n && n != 0)
    {
        num_array = new float[n];
        minus = 0;
        zero = 0;
        positive = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num_array[i];
            if (num_array[i] < 0)
                minus += 1;
            if (num_array[i] == 0)
                zero += 1;
            if (num_array[i] > 0)
                positive += 1;
        }
        cout << minus << ' ' << zero << ' ' << positive << endl;
    }
    return 0;
}