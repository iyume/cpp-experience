#include <iostream>
using namespace std;
using ll = long long;

// 1.编写函数，函数功能是：计算k以内（包括k）最大的5个（不足5个则是所有的）能被13或17整除的自然数之和。要求输入输出均在主函数中完成。
// 2.本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如-21252中，2出现了3次，则该函数应该返回3。用递归和循环两种方式进行实现，并比较两者异同。

int q1(int k){
    int sum, count = 0;
    for(int i=k;i>=1;i--){
        if(i % 13 == 0 || i % 17 == 0){
            sum += i;
            count += 1;
        }
        if(count == 5) break;
    }
    return sum;
}

int q2w1(ll k, int digit){
    int digit_list[20], num_count=0, digit_count=0;
    for(int i=0;i<20;i++){
        if(k == 0) break;
        digit_list[i] = k % 10;
        k /= 10;
        num_count += 1;
    }
    for(int i=0;i<num_count;i++){
        if(digit_list[i] == digit) digit_count += 1;
    }
    return digit_count;
}

int digit_count = 0;
int q2w2(ll k, int digit){
    int digit_list[20];
    if(k == 0){
        return 0;
    }else{
        if(digit == k % 10) digit_count += 1; //也可以使用静态变量但需要想办法销毁，不能多次调用函数
        k /= 10;
        q2w2(k, digit);
    }
    return digit_count;
}

int main(){
    int q;
    cout << "intput the question number(1-2): ";
    while(cin >> q){
        if(q == 1){
            ll k;
            cout << "number k: ";
            cin >> k;
            cout << "the sum of biggest 5 numbers divided by 13 or 17: " << q1(k) << endl;
        }else if(q == 2){
            int p;
            cout << "choose a implement: (1)iteration (2)recursion" << endl;
            cin >> p;
            ll k;
            int digit;
            cout << "number k and one digit: ";
            cin >> k >> digit;
            if(p == 1){
                cout << "the digit " << digit << " appears " << q2w1(abs(k), digit) << " times in number " << k << endl;
            }else if(p == 2){
                cout << "the digit " << digit << " appears " << q2w2(abs(k), digit) << " times in number " << k << endl;
                digit_count -= digit_count; //清除全局变量
            }else break;
        }else break;
        cout << "intput the question number(1-2): "; // iterate the process
    }
    return 0;
}