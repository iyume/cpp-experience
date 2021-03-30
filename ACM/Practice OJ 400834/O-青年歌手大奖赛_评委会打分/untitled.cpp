#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, *score_list;
    while (cin >> n)
    {
        int max = 0, min = 0, max_sub = 0, min_sub = 0;
        double sum = 0;
        score_list = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> score_list[i];
        }
        max, min = score_list[0];
        for (int i = 0; i < n; i++)
        {
            if (max < score_list[i])
                max = score_list[i];
            if (min > score_list[i])
                min = score_list[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (score_list[i] == max)
                max_sub = i;
            if (score_list[i] == min)
                min_sub = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != max_sub && i != min_sub)
            {
                sum += score_list[i];
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << sum / double(n - 2) << endl;
    }
    return 0;
}