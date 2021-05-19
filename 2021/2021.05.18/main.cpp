#include <iostream>
#include <string>
#include "./orderedCircularQueue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 队列模拟舞伴配对问题
// 在舞会上，男、女各自排成一队，舞会开始时，依次从男队和女队的队头各出一人配成舞伴，如果两队初始人数不等，则较长的那一队中未配对者等待下一轮舞曲。
// 假设初始男女人数及性别已经固定，舞会的轮数从键盘输入，试模拟解决上述舞伴配对问题。
// 从屏幕输出每一轮舞伴配对名单，如果在该轮有未配对的，能够从屏幕上显示下一轮第一个出场的未配对者的姓名。

// 测试输入
// John F
// Yhh F
// Amy M
// Then F
// You M
// YYY M
// Male M

int main() {
    OrderedCircularQueue<string> man;
    OrderedCircularQueue<string> woman;
    string name;
    char sex{};
    cout << "请输入所有参会的人员名单（格式：John F）：输入 0 结束" << endl;
    while (cin >> name) {
        if (name == "0") {
            break;
        };
        cin >> sex;
        if (sex == 'F') {
            man.push(name);
        } else if (sex == 'M') {
            woman.push(name);
        } else {
            cout << "输入格式有误" << endl;
            return 1;
        };
    };
    // int man_size = man.size();
    // int woman_size = woman.size();
    // while (!man.empty()) {
    //     std::cout << man.pop() << std::endl;
    // };
    // while (!woman.empty()) {
    //     std::cout << woman.pop() << std::endl;
    // };
    int round = 0;
    cout << "舞会轮数：";
    cin >> round;
    for (int i = 0; i < round; i++) {
        cout << "第 " << i + 1 << " 轮: " << man.front() << ' ' << woman.front()
             << endl;
        man.push(man.pop());
        woman.push(woman.pop());
    }
    return 0;
}