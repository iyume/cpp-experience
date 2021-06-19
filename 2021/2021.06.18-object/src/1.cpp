#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    while (cin >> a >> b >> c) {
        double theta = sqrt(b * b - 4 * a * c);
        cout << "x1=" << (-b + theta) / (2 * a) << ',';
        cout << "x2=" << (-b - theta) / (2 * a) << endl;
    }
    return 0;
}
