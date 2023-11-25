#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    auto a = fs::path("./../aaa");
    std::cout << fs::absolute(a) << '\n';
    auto b = fs::path("./../aaa");
    std::cout << fs::weakly_canonical(b) << '\n';  // canonical needs file to exist
}
