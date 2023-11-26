#include <iostream>
#include <string>
#include <utility>

class A {
  public:
    A() = default;
    // with next line, std::move not work because move constructor is not generated
    // ~A() { a = "sss"; }
    void func(A&& a) { *this = std::move(a); }
    int* b = new int[]{};

  private:
    std::string a{"sss"};  // let move works
};

int main() {
    A a{};
    A b = std::move(a);  // a.a will be new empty string
    A c = a;
    std::cout << a.b << ' ' << c.b << '\n';
    a.func(A{});
}