#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string m, n;
    while (cin >> m >> n)
    {
        vector<int> seq_sum_list;
        // char *m_char = &m[0]; you can convert string to char* by this way.
        for (int i = 0; i < m.length(); i++)
        {
            for (int j = 0; j < n.length(); j++)
            {
                if (m[i] == n[j])
                    seq_sum_list.push_back(i + j);
            }
        }
        if (seq_sum_list.size())
        {
            cout << *min_element(seq_sum_list.begin(), seq_sum_list.end()) << endl;
        }
        else
        {
            cout << "I was angry!" << endl;
        }
    }
    return 0;
}