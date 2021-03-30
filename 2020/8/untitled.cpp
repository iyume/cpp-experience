#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1. 【问题描述】
// 从键盘中读入最多不超过50个学生的学生信息（包括空格隔开的姓名、学号、年龄信息，以学号从低到高排序）
// 【输入形式】
// 每次键盘读入最多不超过50个学生的学生信息：
// 第一行为学生人数；
// 后面每一行为空格隔开的学生学号、姓名、年龄，其中学号和年龄都是整数。
// 【输出形式】
// 分别以姓名顺序（从低到高）和年龄顺序（从低到高）将学生信息输出，每行输出一位学生的信息，其中学号占3位，姓名（英文）占6位，年龄占3位，均为右对齐。年龄相同时按姓名从低到高排序。两种顺序的输出结果用一行空行相隔。
// 【输入样例】
// 4
// 1 aaa 22
// 45 bbb 23
// 54 ddd 20
// 110 ccc 19
// 【输出样例】
//      1    aaa     22       
//   45     bbb     23     
// 110     ccc     19
//   54     ddd     20                                      

// 110     ccc     19       
//   54     ddd     20        
//     1     aaa     22       
//   45     bbb     23                           
// 【样例说明】
// 从键盘输入四个学生记录，分别按姓名和年龄排序并输出。
// 二.【问题描述】
// 输入两组正整数，每组整数不超过20个，并且每组整数中不存在重复数据，也不存在是另一个数据整数倍的数据。编写一个程序按下面要求合并两组整数并输出：要求用指针实现。
// 1. 合并时如果一个数据是另一个数据的整数倍，则剔除；若数据相同，则只保留一个；
// 2. 从小到大顺序输出合并后数据。
// 【输入形式】
// 先从控制台输入第一组整数的个数，然后在下一行输入第一组整数，各整数之间以一个空格分隔；然后按照同样的方式输入第二组整数。
// 【输出形式】
// 在标准输出上按从小到大顺序输出合并后的数据，各整数之间以一个空格分隔，最后一个整数后也可以有一个空格。
// 【输入样例】
// 4
// 25 93 61 2
// 6
// 5 22 3 67 13 61
// 【输出样例】
// 2 3 5 13 61 67
// 【样例说明】
// 第一组整数有4个，第二组有6个，其中第一组整数中的25是第二组中的5的倍数，所以丢弃掉不合并。同样第一组中的93和第二组中的22也不合并到最后的数据中。另外第一组的61和第二组的61重复，只保留一个。最后按照从小到大的顺序输出合并后的数据为：2 3 5 13 61 67。

struct Student{
    int id;
    string name;
    int age;
    int name_rank;
    int age_rank;
};

bool compareName(Student a, Student b){ // 名字不会重复所以直接return true
    for(int i=0;i<6;i++){
        if(a.name.at(i) != b.name.at(i)) return a.name.at(i) < b.name.at(i);
    }
    return true;
}

void sortByName(Student a[], int amount){
    sort(a, a + amount, compareName);
    for(int i=0;i<amount;i++){
        a[i].name_rank = i + 1;
    }
}

bool compareAge(Student a, Student b){
    if(a.age != b.age){
        return a.age < b.age;
    }
    return compareName(a, b);
}

void sortByAge(Student a[], int amount){
    sort(a, a + amount, compareAge);
    for(int i=0;i<amount;i++){
        a[i].age_rank = i + 1;
    }
}

void prettyOutput(Student a){
    if(a.id < 100 && a.id >= 10) cout << ' ' << a.id;
    else if(a.id < 10) cout << "  " << a.id;
    else cout << a.id;
    for(int i=0;i<6-a.name.length();i++) cout << ' ';
    cout << a.name;
    if(a.age < 100 && a.age >= 10) cout << ' '<< a.age;
    else if(a.age < 10) cout << "  " << a.age;
    else cout << a.age;
    cout << endl;
}

void bubbleSort(int array[], int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

bool trackSub(int *p, int *target, int position){ // 不是余数则返回true
    for(int i=0;i<position;i++){
        if(*p % *(target + i) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int q;
    cout << "Select the question(1-2): ";
    while(cin >> q){
        if(q != 1 && q != 2) return 0;
        if(q == 1){
            cout << "You choose question one >>>" << endl;
            Student *students;
            int amount;
            cin >> amount;
            students = new Student [amount];
            for(int i=0;i<amount;i++){
                cin >> students[i].id;
                cin >> students[i].name;
                cin >> students[i].age;
            }
            sortByName(students, amount);
            for(int i=0;i<amount;i++) prettyOutput(students[i]);
            cout << endl;
            sortByAge(students, amount);
            for(int i=0;i<amount;i++) prettyOutput(students[i]);
            delete[] students;
        }
        if(q == 2){
            cout << "You choose question two >>>" << endl;
            int *a, *merge, a_len, b_len;
            cin >> a_len;
            a = new int [a_len];
            for(int i=0;i<a_len;i++) cin >> a[i];
            cin >> b_len;
            int mlen = a_len + b_len;
            merge = new int [mlen];
            for(int i=a_len;i<mlen;i++) cin >> merge[i];
            for(int i=0;i<a_len;i++) merge[i] = a[i];
            delete[] a;
            bubbleSort(merge, mlen);
            int *p = &merge[0];
            for(int i=0;i<mlen;i++){
                if(i == 0){
                    cout << merge[0];
                    p ++;
                    continue;
                }
                if(trackSub(p, merge, i)){
                    cout << ' ' << merge[i];
                }
                p ++;
            }
            delete[] merge;
            cout << endl;
        }
        cout << "Select the question(1-2): ";
    }
    return 0;
}