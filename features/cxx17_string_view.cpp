#include <iostream>
#include <string_view>

int main() {
    std::string_view view("abcdefg");
    view = view.substr(0, 4);
    std::cout << "size:" << view.size() << "length:" << view.length() << "data:" << view.data()
              << '\n';
}