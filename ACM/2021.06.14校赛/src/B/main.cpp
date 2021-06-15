#include <cmath>
#include <iostream>
using namespace std;
using ll = unsigned long long;

const ll MOD = 1000000007;

ll powf(ll a, ll b, ll mod = MOD) {
    ll ans = 1;
    for (int i = 0; i < b; i++) {
        ans = (ans * a) % mod;
    }
    ans %= mod;
    return ans;
}

int main() {
    ll n = 0;
    while (cin >> n) {
        ll result = powf(3LL, n / 2);
        printf("%lld", result);
        cout << endl;
    }
    return 0;
}
