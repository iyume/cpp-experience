#include <iostream>
using namespace std;

int main()
{
    char ch[3];
    char first, second, third;
    while ((ch[0] = getchar()) != EOF)
    {
        for (int i = 1; i <= 2; i++)
        {
            ch[i] = getchar();
        }

        if (ch[0] > ch[1])
        {
            first = ch[0];
            second = ch[1];
        }
        else
        {
            first = ch[1];
            second = ch[0];
        }

        if (ch[2] <= second)
        {
            third = ch[2];
        }
        else if (ch[2] > second && ch[2] <= first)
        {
            third = second;
            second = ch[2];
        }
        else if (ch[2] > first)
        {
            third = second;
            second = first;
            first = ch[2];
        }
        cout << third << ' ' << second << ' ' << first << endl;
        getchar();
    }
    return 0;
}