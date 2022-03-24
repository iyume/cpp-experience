#include <iostream>
using namespace std;

struct Foo {
    Foo() = default;
    ~Foo() { cout << bar << endl; }

    int bar;
};

int main() {
    Foo buzz[2];
    buzz[0].bar = 1;
    buzz[1].bar = 2;
    // output: 2 1
    return 0;
}
