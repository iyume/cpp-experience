#include <string>
#include <unordered_map>
#include "debugger_symbol_problem.hpp"

// compile by: clang++ -g -o main debugger_*.cpp

int main() {
    std::unordered_map<std::string, std::string> aa{{"1", "1"}};
    // without above line, a problem occurs in debugger_symbol_problem.cpp
    auto a = A{};
    a.func();
}
