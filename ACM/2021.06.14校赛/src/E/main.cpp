#include <iostream>
using namespace std;

int main() {
    int n = 0;
    while(cin >> n) {
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        int result_base = n / 3;
        if (n % 3 == 0) {
            cout << result_base << endl;
        } else {
            cout << result_base + 1 << endl;
        }
    }
    return 0;
}
