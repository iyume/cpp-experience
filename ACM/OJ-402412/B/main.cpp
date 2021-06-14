#include <cstdint>
#include <iostream>

int main() {
    int m = 0;
    int n = 0;
    while (std::cin >> m >> n) {
        int** mms = new int*[m];  // m column
        for (int i = 0; i < m; i++) {
            mms[i] = new int[n];  // n row
        }
        int max_col = 0;
        int max_row = 0;
        int max_score = INT32_MIN;
        int max_score_signed = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> mms[i][j];
                if (max_score_signed < std::abs(mms[i][j])) {
                    max_col = i + 1;
                    max_row = j + 1;
                    max_score = mms[i][j];
                    max_score_signed = std::abs(mms[i][j]);
                }
            }
        }
        std::cout << max_col << ' ' << max_row << ' ' << max_score << std::endl;
    }
    return 0;
}
