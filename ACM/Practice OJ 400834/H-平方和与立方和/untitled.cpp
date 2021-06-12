#include <iostream>

int main() {
    int m = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    while (std::cin >> m >> n) {
        if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }
        for (int i = m; i <= n; i++) {
            if (i % 2 == 0) {
                x += i * i;
            } else {
                y += i * i * i;
            }
        }
        std::cout << x << ' ' << y << std::endl;
        x = 0;
        y = 0;
    }
    return 0;
}