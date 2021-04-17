// 第 10 章第 3 题
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Complex {
  public:
    explicit Complex(int r = 0, int i = 0) : m_real(r), m_imagine(i){};
    Complex operator+(const Complex& c) const {
        return Complex(m_real + c.m_real, m_imagine + c.m_imagine);
    };
    Complex operator+(const int& i) const {
        return Complex(m_real + i, m_imagine);
    };
    void operator+=(const Complex& c) {
        m_real += c.m_real;
        m_imagine += c.m_imagine;
    };
    friend Complex operator+(int i, const Complex& c) {
        return Complex(i + c.m_real, c.m_imagine);
    };
    friend ostream& operator<<(ostream& out, const Complex& c) {
        return out << '(' << c.m_real << ',' << c.m_imagine << 'i' << ')';
    };

  private:
    int m_real;
    int m_imagine;
};

int main() {
    const int c1_real = 3;
    const int c1_imagine = 14;
    const int c2_real = 5;
    const int c2_imagine = -10;
    Complex c1(c1_real, c1_imagine);
    Complex c2(c2_real, c2_imagine);
    Complex c3;
    const int i = 5;
    cout << "c1+c2=" << c1 + c2 << endl;
    cout << "i+c1=" << i + c1 << endl;
    cout << "c1+i=" << c1 + i << endl;
    return 0;
}
