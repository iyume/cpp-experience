#include <iostream>
template <typename TT>
class A {
  public:
    TT func();
};

template <typename TT>
TT A<TT>::func() {
    std::cout << "A::func" << '\n';
    return "sss";
}

// this line of code pushs clangd to check type
// template class A<int>;
