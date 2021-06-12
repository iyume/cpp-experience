#include <iostream>

int main() {
    int year = 0;
    std::function<int(int)> count_cow;
    count_cow = [&count_cow](int year) -> int {
        if (year <= 0) {
            exit(0);
        }
        if (year <= 4) {
            return year;
        }
        return count_cow(year - 1) + count_cow(year - 3);
    };
    while (std::cin >> year) {
        std::cout << count_cow(year) << std::endl;
    }
    return 0;
}
