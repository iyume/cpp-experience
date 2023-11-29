#include <utility>

int main() {
    std::pair<const int, int> c;
    const int d = 1;
    c = std::make_pair(d, 1);  // Overload resolution selected deleted operator '='
}