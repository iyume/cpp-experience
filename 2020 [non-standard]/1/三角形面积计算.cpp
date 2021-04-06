#include <iostream>
using namespace std;

int main(){
    float h, b, result;
    cout << "请输入三角形的高：";
    cin >> h;
    cout << "请输入三角形的底：";
    cin >> b;
    result = 0.5 * h * b;
    cout << "三角形的面积为：" << result << endl;
    system("pause");
    return 0;
}
