#include <iostream>
using namespace std;

class arrayList
{
public:
    arrayList(int init_size = 52) {
        arr = new string[init_size];
        size = 0;
    };
    void push(string s) {
        arr[size++] = s;
    }
    void move_back(int range) {
        string* tmp_arr = new string[range];
        for(int i = 0; i < range; i++) {
            tmp_arr[i] = arr[i];
        }
        for(int i = 0; i < 52 - range; i++) {
            arr[i] = arr[i + range];
        }
        for(int i = 0; i < range; i++) {
            arr[i + 52 - range] = tmp_arr[i];
        }
    }
    string at(int index) {
        return arr[index - 1];
    }
private:
    string* arr;
    int size;
};

int main() {
    arrayList list;
    for(int i = 0; i < 52; i++) {
        string tmp;
        cin >> tmp;
        list.push(tmp);
    }
    int T;
    cin >> T;
    int n, y;
    for(int i = 0; i < T; i++) {
        cin >> n >> y;
        int xi;
        for(int i = 0; i < n; i++) {
            cin >> xi;
            list.move_back(xi);
        }
        cout << list.at(y);
        if (i != T - 1) {
            cout << endl;
        }
    }
    return 0;
}
