// 第 10 章第 3 题
#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(int r = 0, int i = 0) : real(r), imagine(i){};
    Complex operator+(const Complex &c)
    {
        return Complex(real + c.real, imagine + c.imagine);
    };
    Complex operator+(const int &i)
    {
        return Complex(real + i, imagine);
    };
    void operator+=(const Complex &c)
    {
        real += c.real;
        imagine += c.imagine;
    };
    friend Complex operator+(int i, const Complex &c)
    {
        return Complex(i + c.real, c.imagine);
    };
    int get_real() const
    {
        return real;
    }
    int get_imagine() const
    {
        return imagine;
    };

private:
    int real;
    int imagine;
};

ostream &operator<<(ostream &out, const Complex &c)
{
    return out << '(' << c.get_real() << ',' << c.get_imagine() << 'i' << ')';
};

int main()
{
    Complex c1(3, 14), c2(5, -10), c3;
    int i = 5;
    cout << "c1+c2=" << c1 + c2 << endl;
    cout << "i+c1=" << i + c1 << endl;
    cout << "c1+i=" << c1 + i << endl;
    return 0;
}
