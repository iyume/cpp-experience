#include <iostream>
#include <ctime>
#include <tuple>
using namespace std;

// 1. 从一个一维数组中，把指定的数据删除。如果删除的元素位于数组第i个位置，则需把从i后的元素全部往前移位。
// 例:假设数组a中的原始元素为 1 2 3 4 5 6 7 8，及a[0]=1 … a[7]=8；如果指定删除元素5，则数组变为 1 2 3 4 6 7 8，及a[0] = 1,…, a[6] = 8。
// 2. 编写一个程序，使用一个二维数组来存储一年中每月的最高和最低温度。程序应该输出该年的平均最高温度、平均最低温度以及该年的最高温度和最低温度。程序必须包含下面的函数：
// A．函数getData（）：该函数将数据读入并存储到二维数组中。
// B．函数averageHigh():该函数计算并返回该年的平均高温。
// C．函数averageLow（）：该函数计算并返回该年的平均低温。
// D．函数indexHighTemp（）：该函数返回数组中最高温度的下标。
// E．函数indexLowTemp（）：该函数返回数组中最低温度的下标。

int *gen_array(){
    // default_random_engine e;
    // uniform_int_distribution<int> u(10, 99);
    static int rand_nums[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        if(i == 0) cout << "---------------" << endl << "Your array: ";
        rand_nums[i] = rand() % 99;
        cout << ' ' << rand_nums[i];
    }
    cout << endl;
    return rand_nums;
}

int **getData(){
    int **arr;
    arr = new int *[2];
    for(int i=0;i<2;i++) arr[i] = new int [12];
    for(int i=0;i<2;i++){
        for(int j=0;j<12;j++){
            cin >> arr[i][j];
        }
    }
    return arr;
}

int averageHigh(int *p){
    int sum = 0;
    for(int i=0;i<12;i++) sum += *(p + i);
    return sum / 12;
}

int averageLow(int *p){
    int sum = 0;
    for(int i=0;i<12;i++) sum += *(p + i);
    return sum / 12;
}

tuple<int, int> indexHighTemp(int **p){
    int max_i = 0, max_j = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<12;j++){
            if(p[i][j] > p[max_i][max_j]){
                max_i = i;
                max_j = j;
            }
        }
    }
    return make_tuple(max_i, max_j);
}

tuple<int, int> indexLowTemp(int **p){
    int low_i = 0, low_j = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<12;j++){
            if(p[i][j] < p[low_i][low_j]){
                low_i = i;
                low_j = j;
            }
        }
    }
    return make_tuple(low_i, low_j);
}

int main(){
    int q;
    cout << "Select the question(1-2): ";
    while(cin >> q){
        if(q == 0) break;
        if(q == 1){
            int *p, k;
            cout << "Here is an array of length 10 which was generated in random from 10 to 99..." << endl << "You should give me an element in the array, and I will pop(kill) it from the array and return the rest number in turn" << endl;
            p = gen_array();
            cout << "And input k: ";
            cin >> k;
            cout << "Survived array:";
            for(int i=0;i<9;i++){
                if(*(p + i) == k) p += 1;
                cout << ' ' << *(p + i);
            }
            cout << endl << "---------------" << endl;
        }
        if(q == 2){
            cout << "getData(): Within two line" << endl;
            int **arr = getData();
            cout << "Executing averageHigh(): " << averageHigh(arr[0]) << endl;
            cout << "Executing averageLow(): " << averageLow(arr[1]) << endl;
            auto index_high = indexHighTemp(arr);
            cout << "Executing indexHighTemp(): " << get<0>(index_high) << ", " << get<1>(index_high) << endl;
            auto index_low = indexLowTemp(arr);
            cout << "Executing indexLowTemp(): " << get<0>(index_low) << ", " << get<1>(index_low) << endl;
        }
        cout << "Select the question(1-2): ";
    }
    return 0;
}