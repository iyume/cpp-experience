#include <iostream>
#include <cmath>
using namespace std;

// 1. 超长正实数减法
// 一．编写程序
// 【问题描述】
// 编写程序实现两个超长正实数（每个整数最长80位数字，小数最长80位数字）的减法运算。提示：用数组来存储数字。
// 【输入形式】
// 从键盘读入两个数，要考虑输入高位可能为0的情况（如00083）。
// 1. 第一行是超长数A；
// 2. 第二行是超长数B；
// 【输出形式】 
// 输出只有一行，是长数A减去长数B的运算结果，从高到低依次输出各位数字。要求：
// 1、若结果大于0，则只输出结果数字，不输出正号；若结果为负，则输出负号；若结果为0，则只输出一个0。
// 2、除非结果为0，否则输出的结果的最高位不能为0，并且各位数字紧密输出。
//  【输入样例】
// 234098.98
// 134098703578230056.50
// 【输出样例】
//  -134098703577995957.52
// 【样例说明】
// 进行两个正数减法运算， 234098.98 – 134098703578230056.50 = -134098703577995957.52。

char judgeSizeOfNum(char *p, char *q, int len){ // 传入相同长度的数组的头部指针判断大小
    for(int i=0;i<len;i++){
        //cout << *(p+i) << ' ';
        if(*(p + i) > *(q + i)) return 'y';
        if(*(p + i) < *(q + i)) return 'f';
        if(i == len - 1) return 'e';
    }
    return 'e';
}

int fixPointerAtZero(char *p, int len){ // 返回头部 0 的数目
    for(int i=0;i<len;i++){
        if(*(p + i) != '0') return i;
        if(i == len - 1) return i + 1;
    }
    return 0;
}

void sameSubtraction(char *p, char *q, int len, int *result){ // 相同长度的数组相减，必须大减小
    for(char i=len-1;i>=0;i--){
        if(*(p + i) - *(q + i) >= 0){
            *(result + i) = *(p + i) - *(q + i); // char inter reduce to int ! No need convert
        }else{
            *(q + i - 1) += 1;
            *(result + i) = 10 - *(q + i) + *(p + i);
        }
    }
}

void reduceOne(char *p, int head_len, int *result){ // 当整数长度不等并且等长度部分相减小于零，在较长数组的多余头部进位
    char *q;
    q = new char [head_len];
    for(int i=0;i<head_len-1;i++) q[i] = '0'; // zero_append = {48, 48, 48...49}
    q[head_len - 1] = '1';
    sameSubtraction(p, q, head_len, result); // ww
    delete[] q;
}

// 小数部分 减法
void interSubtractionDec(char *p_dec, char *q_dec, int large_dec_size, int small_dec_size, int *result){
    int tail_len = large_dec_size - small_dec_size;
    for(int i=small_dec_size;i<large_dec_size;i++) *(q_dec + i) = '0'; // expand zeros
    sameSubtraction(p_dec, q_dec, large_dec_size, result);
}

// 大数减去小数，不同长度 require
void interSubtractionInt(char *p_int, char *q_int, int a_int_size, int b_int_size, int *result){
    int head_size = a_int_size - b_int_size;
    char *p_int_2 = p_int + head_size;
    char yfe = judgeSizeOfNum(p_int_2, q_int, b_int_size);
    if(yfe == 'y'){ // 等长度部分 a > b
        sameSubtraction(p_int_2, q_int, b_int_size, result + head_size); // 等长度部分相减并读入结果
        for(int i=0;i<head_size;i++) *(result  + i) = *(p_int + i) - '0'; // 补全结果前面的部分，不涉及进位 type(a_int)=char
    }else if(yfe == 'f'){ // 等长度部分 a < b
        sameSubtraction(q_int, p_int_2, a_int_size, result + head_size); // 必须大减小
        for(int i=head_size;i<a_int_size;i++) *(result + i) = 9 - *(result + i); // 因为减法方向相反，所以结果 10 - x
        *(result + a_int_size - 1) += 1; // 最后一位修正
        if(head_size == 1) *result = *p_int - '1'; // 头部长度等于 1 char to int and reduce 1
        else reduceOne(p_int, head_size, result); // else 给前面部分减一并读入结果
    }else if(yfe == 'e'){
        for(int i=0;i<head_size;i++) *(result + i) = *(p_int + i) - '0'; // char to int
        for(int i=head_size;i<a_int_size;i++) *(result + i) = 0;
    }
}

int main(){
    char c;
    while(c = cin.get()){
        char a_int[80] = {'0'}, a_dec[80] = {'0'};
        char *p_int = &a_int[0], *p_dec = &a_dec[0];
        a_int[0] = c; p_int += 1;
        while((c = cin.get()) != '.'){
            *p_int = c;
            p_int += 1;
        }
        while((c = cin.get()) != '\n'){
            *p_dec = c;
            p_dec += 1;
        }
        char b_int[80] = {'0'}, b_dec[80] = {'0'};
        char *q_int = &b_int[0], *q_dec = &b_dec[0];
        while((c = cin.get()) != '.'){
            *q_int = c;
            q_int += 1;
        }
        while((c = cin.get()) != '\n'){
            *q_dec = c;
            q_dec += 1;
        }
        int a_int_size = p_int - &a_int[0], a_dec_size = p_dec - &a_dec[0]; // invalid within zero count
        int b_int_size = q_int - &b_int[0], b_dec_size = q_dec - &b_dec[0]; // invalid within zero count
        p_int = &a_int[0]; p_dec = &a_dec[0]; q_int = &b_int[0]; q_dec = &b_dec[0]; // reset pointer
        int a_pre_zeros = fixPointerAtZero(p_int, a_int_size);
        int b_pre_zeros= fixPointerAtZero(q_int, b_int_size);
        p_int += a_pre_zeros; q_int += b_pre_zeros; // 指针全部指在开头，以下不变
        bool a_int_null = false, b_int_null = false;
        if(a_pre_zeros == a_int_size){
            a_int_size = 0;
            a_pre_zeros = 1;
            a_int_null = true;
            p_int = &a_int[0];
        }
        if(b_pre_zeros == b_int_size){
            b_int_size = 0;
            b_pre_zeros = 1;
            b_int_null = true;
            q_int = &b_int[0];
        }
        a_int_size -= a_pre_zeros; b_int_size -= b_pre_zeros; // 尺寸标准化
        char int_compare = 'n', dec_compare = 'n';
        int subtract_int[80], subtract_dec[80];
        if(a_int_size == b_int_size) int_compare = judgeSizeOfNum(p_int, q_int, a_int_size);
        dec_compare = judgeSizeOfNum(p_dec, q_dec, a_dec_size);
        if(int_compare == 'e' && dec_compare == 'e'){
            cout << 0 << endl;
            continue;
        }
        if(a_int_size == b_int_size){
            if(int_compare == 'y') sameSubtraction(p_int, q_int, a_int_size, &subtract_int[0]);
            if(int_compare == 'f') sameSubtraction(q_int, p_int, a_int_size, &subtract_int[0]);
            if(int_compare == 'e') for(int i=0;i<a_int_size;i++) subtract_int[i] = 0;
            //for(int i=0;i<a_int_size;i++) cout << subtract_int[i] << ' ';
            //return 0;
        }else if(a_int_size > b_int_size){ // a 整数部分的尺寸大于 b 整数部分
            interSubtractionInt(p_int, q_int, a_int_size, b_int_size, subtract_int);
        }else if(a_int_size < b_int_size){
            interSubtractionInt(q_int, p_int, b_int_size, a_int_size, subtract_int);
            //for(int i=0;i<b_int_size;i++) cout << subtract_int[i] << ' ';
        }
        if(a_dec_size == b_dec_size){ // 这里实现很蠢，我不想改了
            if(dec_compare == 'y'){
                sameSubtraction(p_dec, q_dec, a_dec_size, subtract_dec);
                if(a_int_size < b_int_size || int_compare == 'f'){
                    for(int i=0;i<a_dec_size;i++) subtract_dec[i] = 9 - subtract_dec[i];
                    subtract_dec[a_dec_size - 1] += 1;
                }
            }
            if(dec_compare == 'f'){
                sameSubtraction(q_dec, p_dec, a_dec_size, subtract_dec);
                if(int_compare != 'e'){
                    for(int i=0;i<a_dec_size;i++) subtract_dec[i] = 9 - subtract_dec[i];
                    subtract_dec[a_dec_size - 1] += 1;
                }
            }
            if(dec_compare == 'e'){
                for(int i=0;i<a_dec_size;i++) subtract_dec[i] = 0;
            }
        }else if(a_dec_size > b_dec_size){ // a 小数部分的尺寸大于 b 小数部分
            interSubtractionDec(p_dec, q_dec, a_dec_size, b_dec_size, subtract_dec);
            if(a_int_size < b_int_size || int_compare == 'f'){
                for(int i=0;i<a_dec_size;i++) subtract_dec[i] = 9 - subtract_dec[i];
                subtract_dec[a_dec_size - 1] += 1;
            }
        }else if(a_dec_size < b_dec_size){
            interSubtractionDec(q_dec, p_dec, b_dec_size, a_dec_size, subtract_dec);
            if(judgeSizeOfNum(p_dec, q_dec, b_dec_size) == 'f' || a_int_null){
                for(int i=0;i<b_dec_size;i++) subtract_dec[i] = 9 - subtract_dec[i];
                subtract_dec[b_dec_size-1] += 1;
            }
            //for(int i=0;i<b_dec_size;i++) cout << subtract_dec[i] << ' ';
        }
        // OUTPUT prepare checking...
        int max_int_len, max_dec_len;
        max_int_len = a_int_size >= b_int_size ? a_int_size : b_int_size;
        max_dec_len = a_dec_size >= b_dec_size ? a_dec_size : b_dec_size;
        char check_dec = judgeSizeOfNum(p_dec, q_dec, max_dec_len);
        if(check_dec == 'f'){ // 小数部分在整数借一
            if(subtract_int[max_int_len - 1] != 0){
            subtract_int[max_int_len - 1] -= 1;
            }else{
                int zerocount = 0;
                while(subtract_int[max_int_len-zerocount-1] == 0) zerocount ++;
                subtract_int[max_int_len-zerocount-1] -= 1;
                if(int_compare != 'e') for(int i=max_int_len-zerocount;i<max_int_len;i++) subtract_int[i] = 9;
            }
        }
        //dec_compare = judgeSizeOfNum(p_dec, q_dec, max_dec_len);
        bool ifintzero = true;
        for(int i=0;i<max_int_len;i++) if(subtract_int[i] == 0) continue; else ifintzero = false;
        // OUTPUT >>>
        cout << "Output: ";
        if(a_int_size < b_int_size || int_compare == 'f' || (ifintzero && dec_compare == 'f')) cout << '-';
        if(!ifintzero){
            if(!a_int_null && !b_int_null){
                if(a_int_size < b_int_size) subtract_int[max_int_len - 1] -= 1;
                // for(int i=0;i<max_int_len;i++) cout << subtract_int[i];
                {int i=0;while(subtract_int[i] == 0) i++;
                for(int j=i;j<max_int_len;j++) cout << subtract_int[j];}
                cout << '.';
                for(int i=0;i<max_dec_len;i++) cout << subtract_dec[i];
            }else{
                if(b_int_null && !a_int_null){
                    cout << a_int[a_pre_zeros+a_int_size-1] << '.';
                    for(int i=0;i<max_dec_len;i++) cout << subtract_dec[i];
                }else{
                    cout << b_int[b_pre_zeros+b_int_size-1] << '.';
                    for(int i=0;i<max_dec_len;i++) cout << subtract_dec[i];
                }
            }
        }else{
            cout << 0 << '.';
            for(int i=0;i<max_dec_len;i++) cout << subtract_dec[i];
        }
        cout << endl;
    }
    return 0;
}
// 写到最后，发现有一种更好的实现方法，先实现一个整体大减小（带小数）的函数，然后判断数字大小，交换存入并输出负号