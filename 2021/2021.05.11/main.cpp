#include "lib/linkedCircularList.hpp"
#include "lib/pch.hpp"
using std::cout;
using std::endl;

// 约瑟夫环问题求解

int main() {
    CircularChain<int> chain;
    const int test_n = 10;
    const int test_k = 0;  // start from
    const int test_m = 17;
    for (int i = 0; i < test_n; i++) {
        // init data for chain
        chain.append(i);
    };
    int count = 1;
    const int m = test_m;
    int start = test_k;
    auto* p_head = chain.begin();
    for (int i = 0; i < start; i++) {
        // move p to start
        p_head = p_head->next;
    };
    int p_position = 0;
    int p_data = 0;
    while (chain.length() != 1) {
        for (int i = 0; i < m - 1; i++) {
            p_head = p_head->next;
        };
        p_data = p_head->data;
        p_position = chain.indexOf(p_data);
        p_head = p_head->next;
        chain.erase(p_position);
        cout << "第" << count++ << "次: "
             << "删除点" << p_position << ',' << " 序号n=" << p_data << endl;
    };
    cout << "最后一个人的序号 n: " << chain.get(0);
    return 0;
}
