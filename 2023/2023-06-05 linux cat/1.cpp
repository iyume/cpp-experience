#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, char** argv) {
    string content;
    if (sizeof(argv) != 1U) {
        ifstream file(argv[1]);
        getline(file, content);
        cout << content;
    } else {
        cout << "Usage: cat FILE";
    }
    return 0;
}