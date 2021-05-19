#include <iostream>
#include <stdexcept>
#include <string>
using std::cout;
using std::runtime_error;
using std::string;

// 括号匹配

template <class TT>
class Stack {
  public:
    explicit Stack(int init_size = 100);
    [[nodiscard]] bool empty() const;
    [[nodiscard]] int size() const;
    TT& top();
    void pop();
    void push(TT data);

  private:
    TT* m_data;
    int m_size;
    int m_max_length;
};

template <class TT>
Stack<TT>::Stack(int init_size) {
    m_data = new TT[init_size];
    m_size = 0;
    m_max_length = init_size;
};

template <class TT>
bool Stack<TT>::empty() const {
    return m_size == 0;
};

template <class TT>
int Stack<TT>::size() const {
    return m_size;
};

template <class TT>
TT& Stack<TT>::top() {
    if (empty()) {
        throw runtime_error("stack is empty");
    };
    return m_data[m_size - 1];
};

template <class TT>
void Stack<TT>::pop() {
    if (empty()) {
        throw runtime_error("empty to pop");
    };
    m_size--;
};

template <class TT>
void Stack<TT>::push(TT data) {
    if (m_size == m_max_length) {
        throw runtime_error("stack is full");
    };
    m_data[m_size] = data;
    m_size++;
};

int main() {
    const string s1 = "{(()[])}[]";  // 正确的匹配字符串
    const string s2 = "{}}";         // 右边不匹配的情况
    const string s3 = "{(})";
    Stack<char> stack;
    for (char c : s3) {
        if (c == '(') {
            stack.push(')');
        } else if (c == '[') {
            stack.push(']');
        } else if (c == '{') {
            stack.push('}');
        } else if (stack.empty() || stack.top() != c) {
            stack.push(c);
            break;  // 栈处于有元素的状态，直接走向失败
        } else {
            stack.pop();
        };
    };
    if (stack.empty()) {
        cout << "匹配成功";
    } else {
        cout << "匹配失败";
    }
    return 0;
}
