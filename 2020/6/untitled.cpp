#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 一【问题描述】
// 输入若干个字符串(每个字符串的长度不超过30个字符，字符串总数不超过30)，和一个英文字符ch。 要求： - 删除每个字符串中的字符ch(区分大小写)，得到新的字符串 - 将新的字符串按照字典逆序排序后输出
// 【输入形式】
//     第一行输入英文字符ch
//     每一行输入一个字符串
//     最后一行单独输入特殊字符@做为结束标志
// 【输出形式】
//     删除ch的新字符串按字典逆序输出
//     每行输出一个字符串
// 【样例输入】
// e
// shangejiao
// fudean
// teongji
// shangcai
// @
// 【样例输出】
// tongji
// shangjiao
// shangcai
// fudan

// 二. 给定两个整型数组，本题要求找出不是两者共有的元素。
// 输入格式:
// 输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。
// 输出格式:
// 在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。
// 输入样例:
// 10 3 -5 2 8 0 3 5 -15 9 100
// 11 6 4 8 2 6 -5 9 0 100 8 1
// 输出样例:
// 3 5 -15 6 4 1

// int *indexReversedStringArray(string *p, int iters){
//     int *arr;
//     arr = new int[iters];
//     for(int i=0;i<iters;i++){
//     }
//     return 0;
// }

int main(){
    int q;
    cout << "Select the question(1-2): ";
    while(cin >> q){
        cin.ignore();
        if(q == 0) break;
        if(q == 1){
            char ch, son;
            int count = 0;
            string str_list[30];
            string str;
            ch = cin.get();
            cin.ignore();
            if(ch > 96 && ch < 123) ch -= 32;
            while((son = cin.get()) != '@'){
                if(son == ch or son == ch + 32) continue;
                if(son == '\n'){
                    str_list[count] = str;
                    str = "";
                    count += 1;
                    continue;
                }
                str += son;
            }
            // int *index_arr = indexReversedStringArray(str_list, count);
            sort(str_list, str_list + count); // include <algorithm>
            for(int i=count-1;i>=0;i--) cout << str_list[i] << endl;
        }
        if(q == 2){
            int *arr1, *arr2, n1, n2;
            cin >> n1;
            arr1 = new int [n1];
            for(int i=0;i<n1;i++) cin >> arr1[i];
            cin >> n2;
            arr2 = new int [n2];
            for(int i=0;i<n2;i++) cin >> arr2[i];
            int check = 0;
            vector<int> single_nums;
            for(int i=0;i<n1;i++){
                for(int j=0;j<n2;j++){
                    if(arr1[i] == arr2[j]) check += 1;
                    if(j == n2 -1 && check == 0) single_nums.push_back(arr1[i]);
                }
                check = 0;
            }
            check = 0;
            for(int j=0;j<n2;j++){
                for(int i=0;i<n1;i++){
                    if(arr1[i] == arr2[j]) check += 1;
                    if(i == n1 -1 && check == 0) single_nums.push_back(arr2[j]);
                }
                check = 0;
            }
            // int *p = &single_nums[0], result[20];
            // single_nums.erase(unique(single_nums.begin(), single_nums.end()), single_nums.end()); // should sort first
            // auto end = single_nums.end();
            // for(auto t=single_nums.begin();t!=end;++t){
            //     end = remove(t + 1, end, *t);
            // }
            // single_nums.erase(end, single_nums.end());
            // for(int i=0;i<single_nums.size();i++){
            //     if(i == 0){
            //         cout << single_nums[i];
            //         continue;
            //     }
            //     cout << ' ' << single_nums[i];
            // }
            int count = 1, single_array[40];
            single_array[0] = single_nums[0];
            for(int i=0;i<single_nums.size();i++){
                for(int j=0;j<count;j++){
                    if(single_nums[i] == single_array[j]){
                        break;
                    }else if(j == count - 1){
                        single_array[count] = single_nums[i];
                        count += 1;
                    }
                }
            }
            for(int i=0;i<count;i++){
                if(i == 0){
                    cout << single_array[i];
                    continue;
                }
                cout << ' ' << single_array[i];
            }
            cout << endl;
        }
        cout << "Select the question(1-2): "; // iterator the process
    }
    return 0;
}