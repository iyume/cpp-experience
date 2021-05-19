#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::runtime_error;

// 进制转换

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
    Stack<int> stack(1000);
    int input_number = 0;
    int input_base = 0;
    int remainder = 0;
    cout << "输入一位十进制数: ";
    cin >> input_number;
    cout << "输入目标进制 [2-9]: ";
    while (cin >> input_base) {
        if (input_base > 9 || input_base < 2) {
            cout << "进制不允许，请重新输入";
            continue;
        };
        break;
    };
    while (input_number != 0) {
        try {
            stack.push(input_number % input_base);
        } catch (runtime_error& exc) {
            cout << exc.what();
        };
        input_number /= input_base;
    };
    cout << "转换结果: ";
    while (!stack.empty()) {
        cout << stack.top();
        try {
            stack.pop();
        } catch (runtime_error& exc) {
            cout << exc.what();
        }
    };
    return 0;
}
