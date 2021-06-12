#include <algorithm>
#include <iostream>

int main() {
    int n = 0;
    int* arr = nullptr;
    while (std::cin >> n) {
        if (n == 0) {
            exit(0);
        }
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::sort(arr, arr + n,
                  [](int a, int b) { return std::abs(a) > std::abs(b); });
        for (int i = 0; i < n; i++) {
            std::cout << arr[i];
            if (i == n - 1) {
                std::cout << std::endl;
            } else {
                std::cout << ' ';
            }
        }
        delete arr;
        arr = nullptr;
    }
    return 0;
}
