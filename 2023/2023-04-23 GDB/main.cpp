#include <iostream>
#include <vector>

using namespace std;

int main() {
    printf("Hello %d%s\n", 201301102, "名字");
    puts("我的简介");
    cout << "我的更多简介" << endl;
    auto list = vector<int>();
    for (int i = 0; i <= 10; i++) {
        if (i == 5) {
            break;
        }
        list.push_back(i);
    }
    return 0;
}
