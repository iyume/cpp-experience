#include <iostream>
using namespace std;

class Point {
  public:
    Point(int a, int b, int c) {
        one = a;
        two = b;
        three = c;
    };
    virtual ~Point() { cout << "executing Point destructor" << endl; };

  protected:
    int one;
    int two;
    int three;
};

class Circle : public Point {
  public:
    Circle(int a, int b, int c) : Point(a, b, c){};
    ~Circle() override { cout << "executing Circle destructor" << endl; };
};

int main() {
    Circle* p = new Circle(2, 5, 7);
    delete p;
    return 0;
}
