#include <iostream>
#include <string>

int main() {
    int n = 0;
    auto cal_papers = [](int wage) -> int {
        // std::string wage_str = std::to_string(wage);
        // wage_str.erase(0);
        int result = 0;
        for (int i : {100, 50, 10, 5, 2, 1}) {
            result += wage / i;
            wage %= i;
        }
        return result;
    };
    while (std::cin >> n) {
        if (n == 0) {
            exit(0);
        }
        int tmp = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> tmp;
            result += cal_papers(tmp);
        }
        std::cin.clear();
        std::cout << result << std::endl;
    }
    return 0;
}
