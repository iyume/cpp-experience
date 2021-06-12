#include <iostream>

int main() {
    int n = 0;
    int m = 0;
    int* arr = nullptr;
    auto binary_search = [](const int* arr, int size, int to_search) -> int {
        int left = 0;
        int right = size;
        int m = 0;
        while (left < right) {
            m = (left + right) / 2;
            if (arr[m] >= to_search) {
                right = m;
            } else {
                left = m + 1;
            }
        }
        return left;
    };
    // auto will be std::function<int(int)>
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            exit(0);
        }
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::cin.clear();
        int result = binary_search(arr, n, m);
        for (int i = 0; i < n; i++) {
            if (i == result) {
                std::cout << m << ' ';
            }
            std::cout << arr[i];
            if (i == n - 1) {
                if (result == n) {
                    std::cout << ' ' << m;
                }
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
