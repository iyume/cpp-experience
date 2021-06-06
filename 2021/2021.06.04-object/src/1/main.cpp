#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    const char* f1 = "./f1.dat";
    const char* f2 = "./f2.dat";
    // 1）从键盘输入 10 个整数，分别存放在两个磁盘文件中，每个文件中放 5 个整数
    ofstream fb1(f1);
    ofstream fb2(f2);
    int tmp = 0;
    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        if (i == 4) {
            fb1 << tmp;
            break;
        }
        fb1 << tmp << ' ';
    }
    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        if (i == 4) {
            fb2 << tmp;
            break;
        }
        fb2 << tmp << ' ';
    }
    fb1.close();
    fb2.close();
    // 2）从 f1.dat 读入 5 个数，然后存放在 f2.dat 文件原有数据后面
    ifstream read_array5(f1);
    int* parray = new int[10];
    for (int i = 0; i < 5; i++) {
        read_array5 >> parray[i];
    }
    read_array5.close();
    ifstream update_f2(f2);
    string f2buf;
    getline(update_f2, f2buf);
    update_f2.close();
    ofstream update_f2_o(f2);
    update_f2_o << f2buf;
    // question delay
    for (int i = 0; i < 5; i++) {
        update_f2_o << ' ' << parray[i];
    }
    update_f2_o.close();
    // 3）从 f2.dat 中读入 10 个整数，对它们进行从小到大的顺序存放在 f2.dat
    // 中（不保留原来的数据）
    ifstream r_fb2(f2);
    for (int i = 0; i < 10; i++) {
        r_fb2 >> parray[i];
    }
    r_fb2.close();
    sort(parray, parray + 10);
    ofstream o_fb2(f2);
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            o_fb2 << parray[i];
            cout << parray[i];
            break;
        }
        o_fb2 << parray[i] << ' ';
        cout << parray[i] << ' ';
    }
    o_fb2.close();
    return 0;
}
