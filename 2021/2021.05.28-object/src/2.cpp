#include <cmath>
#include <iostream>
using namespace std;

class Shape {
  public:
    void showArea() const { cout << volumn; };

  protected:
    double volumn;
};

class Circle : virtual public Shape {
  public:
    explicit Circle(int r) : Shape() { volumn = r * r * 3.14; };
};

class Rectangle : virtual public Shape {
  public:
    explicit Rectangle(int length, int width) : Shape() {
        volumn = length * width;
    };
};

class Triangle : virtual public Shape {
  public:
    explicit Triangle(int a, int b, int c) : Shape() {
        double p = 0.5 * (a + b + c);
        volumn = std::sqrt(p * (p - a) * (p - b) * (p - c));
    };
};

int main() {
    Circle circle(2);
    Rectangle rectangle(12, 2);
    Triangle triangle(3, 4, 5);
    circle.showArea();
    cout << endl;
    rectangle.showArea();
    cout << endl;
    triangle.showArea();
    return 0;
}
