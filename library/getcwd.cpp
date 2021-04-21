#include <unistd.h>
#include <string>
using std::string;

string getCWD() {
    char abs_path[1024];
    int cnt = readlink("/proc/self/exe", abs_path, 1024);
    if (cnt < 0 || cnt >= 1024) {
        return nullptr;
    }
    // remove exe program and return a directory
    for (int i = cnt; i >= 0; --i) {
        if (abs_path[i] == '/') {
            abs_path[i + 1] = '\0';
            break;
        }
    }
    string path(abs_path);
    return path;
}