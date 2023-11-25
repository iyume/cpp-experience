#include <string>
#include <unordered_map>
#include "debugger_symbol_problem.hpp"

int main() {
    std::unordered_map<std::string, std::string> aa{{"1", "1"}};
    auto a = A{};
    a.func();
}
