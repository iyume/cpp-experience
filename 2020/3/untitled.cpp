#include <iostream>
using namespace std;

int first(void){
    char c;
    getchar();
    while((c = getchar()) != EOF){
        if(c >= 97 && c <= 122){
            c -= 32;
            cout << c << endl;
        }else if(c >= 65 && c <= 90){
            c += 32;
            cout << c << endl;
        }else if(c >= 48 && c <= 57){
            cout << c << endl;
        }else if(c == 32){
            cout << "space" << endl;
        }else{
            cout << "other" << endl;
        }
        getchar();
    }
    return 0;
}

int second(void){
    int num, count;
    char *char_list;
    cout << "Please input the length of number: ";
    while(cin >> num){
        char_list = new char[num];
        cout << "Please input the number: ";
        for(int i=0;i<num;i++){
            cin >> char_list[i];
        }
        for(int i=0;i<(num-1)/2;i++){
            for(int j=num-1;j>(num-1)/2;j--){
                if(char_list[i] == char_list[j]){
                    count += 1;
                }
            }
        }
        if((num - 1) / 2 == count){
            cout << char_list << " is a number of replies." << endl;
        }else{
            cout << char_list << " is not a number of replies." << endl;
        }
        cout << "Please input the length of number: ";
    }
    return 0;
}

int main(){
    int num;
    cout << "Please select the type of your input: " << endl << "1. input a char" << endl << "2. judge the number of replies" << endl;
    cin >> num;
    if(num == 1) first();
    if(num == 2) second();
    return 0;
}