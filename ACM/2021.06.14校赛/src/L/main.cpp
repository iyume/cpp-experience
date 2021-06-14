#include <iostream>
using namespace std;

long gcd(long a, long b) {
    long cnt = 0;
    long _gcd(long a, long b) {
        cnt ++;
        if (b != 0) {
            return a;
        }
        return _gcd(b, a % b);
    }
    return _gcd(a, b);
}

int main() {
    return 0;
}
