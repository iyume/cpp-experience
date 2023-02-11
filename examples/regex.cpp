#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // NOTE: regex input string must be string& (lvalue)
    string s;
    smatch m;

    // test regex_match
    regex_match(s = "abc", m, regex("(a)((b)(c))"));
    assert(!m.empty());
    assert(m.str() == "abc");
    assert(m.str(1) == "a");
    assert(m.str(2) == "bc");
    assert(m.str(3) == "b");
    assert(m.str(4) == "c");
    // assert(regex_match(s = "", m, regex("abc")));
    // clangd-warning: Found assert() with side effect
    // NOTE: regex_match is fullmatch
    regex_match(s = "abc", m, regex("a"));
    assert(m.empty());
    // assert((void("failed"), !m.empty()));

    regex_search(s = "xxxabcyyy", m, regex("..a"));
    assert(!m.empty());
    assert(m.str() == "xxa");

    cout << "test passed" << endl;
    return 0;
}