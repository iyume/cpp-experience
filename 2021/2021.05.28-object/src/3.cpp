#include <cmath>
#include <iostream>
using namespace std;

class Shape {
  public:
    virtual void showArea() const { cout << volumn; };
    [[nodiscard]] virtual double getVolumn() const { return volumn; };

  protected:
    double volumn = 0;
};

class Circle : public Shape {
  public:
    explicit Circle(int r) { volumn = r * r * 3.14; };
};

class Rectangle : public Shape {
  public:
    explicit Rectangle(int length, int width) { volumn = length * width; };
};

class Triangle : public Shape {
  public:
    explicit Triangle(int a, int b, int c) {
        double p = 0.5 * (a + b + c);
        volumn = sqrt(p * (p - a) * (p - b) * (p - c));
    };
};

class Square : public Shape {
  public:
    explicit Square(int x) { volumn = x * x; };
};

class Trapezoid : public Shape {
  public:
    explicit Trapezoid(int a, int b, int c) { volumn = (a + b) * c * 0.5; };
};

int main() {
    Circle circle(2);
    Square square(5);
    Rectangle rectangle(12, 2);
    Trapezoid trapezoid(10, 40, 5);
    Triangle triangle(3, 4, 5);
    Shape* parray[5]{&circle, &rectangle, &triangle, &square, &trapezoid};
    double sum = 0;
    for (auto* i : parray) {
        sum += i->getVolumn();
    };
    cout << "sum=" << sum;
    return 0;
}
