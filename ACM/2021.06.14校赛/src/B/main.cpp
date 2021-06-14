#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

#define res 1000000007;

int main() {
    ll n = 0;
    while(cin >> n) {
        cout << ll(pow(3ll, n / 2)) % res;
        cout << endl;
    }
    return 0;
}
