#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int year, month, day, result;
    char spliter = '/';
    int month_in_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // stringstream, vector, std::string::find() function can split string
    while (cin >> year >> spliter >> month >> spliter >> day)
    {
        result = 0;
        for (int i = 0; i <= month - 1; i++)
        {
            if (month == 1)
            {
                break;
            }
            if (i == month - 1)
                continue;
            result += month_in_days[i];
        }
        result += day;
        if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && result >= 60)
            result += 1;
        cout << result << endl;
    }
    return 0;
}