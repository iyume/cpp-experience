#include "template_type_infer.hpp"

// https://en.cppreference.com/w/cpp/language/class_template

int main() {
    A<int> a;
    a.func();  // cannot infer error cast char* -> int
}
