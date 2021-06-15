using ll = unsigned long long;

ll powf(ll a, ll b, ll mod) {
    ll ans = 1;
    for (int i = 0; i < b; i++) {
        ans = (ans * a) % mod;
    }
    ans %= mod;
    return ans;
}
