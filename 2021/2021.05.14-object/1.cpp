#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Matrix2R3C {
    Matrix2R3C() { arr = new int{0}; }
    explicit Matrix2R3C(const int* in_arr) {
        arr = new int[6];
        for (int i = 0; i < 6; i++) {
            arr[i] = in_arr[i];
        };
    };
    Matrix2R3C operator+(const Matrix2R3C& m2) const {
        int* arr_2 = new int[6];
        for (int i = 0; i < 6; i++) {
            arr_2[i] = arr[i] + m2.arr[i];
        };
        return Matrix2R3C(arr_2);
    };
    Matrix2R3C operator+=(const Matrix2R3C& m) {
        for (int i = 0; i < 6; i++) {
            arr[i] += m.arr[i];
        };
        return *this;
    };
    friend std::ostream& operator<<(std::ostream& out, const Matrix2R3C& m) {
        out << m.arr[0] << ' ' << m.arr[1] << ' ' << m.arr[2] << endl;
        out << m.arr[3] << ' ' << m.arr[4] << ' ' << m.arr[5];
        return out;
    };
    friend std::istream& operator>>(std::istream& in, const Matrix2R3C& m) {
        for (int i = 0; i < 6; i++) {
            in >> m.arr[i];
        };
        return in;
    };

    int* arr;
};

int main() {
    Matrix2R3C matrix_a;
    Matrix2R3C matrix_b;
    cin >> matrix_a;
    cin >> matrix_b;
    cout << "a:" << endl << matrix_a << endl;
    cout << "b:" << endl << matrix_b << endl;
    cout << "c=a+b:" << endl;
    cout << matrix_a + matrix_b;
    return 0;
}
