// tailing return type modernize-use-trailing-return-type
// https://www.ibm.com/docs/en/zos/2.3.0?topic=declarators-trailing-return-type-c11

template <class A, class B>
class K {
  public:
    int i;
};

auto bar() -> K<int, double> (*)() {
    return []() -> K<int, double> { return K<int, double>{}; };
}

auto baz() -> auto (*)() -> K<int, double> (*)() {
    return bar;
}

auto bazz() -> auto (*)() -> auto (*)() -> K<int, double> {
    return bar;
}
