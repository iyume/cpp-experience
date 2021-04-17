#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::ostringstream;

template <class TT>
struct Node {
    explicit Node(const TT& data) { this->data = data; };
    Node(const TT& data, Node<TT>* next) {
        this->data = data;
        this->next = next;
    };

    TT data;
    Node<TT>* next;
};

template <class TT>
class Chain {
  public:
    Chain();
    void checkIndex(int index);
    int index(TT& data);  // get the index of data if matched
    TT& get(int index);   // get data by node's index
    void append(TT& data);
    void insert(int index, TT& data);

  private:
    Node<TT>* m_first_node;
    int m_size;
};

template <class TT>
Chain<TT>::Chain() {
    m_first_node = nullptr;
    m_size = 0;
};

template <class TT>
void Chain<TT>::checkIndex(int index) {
    if (index < 0 || index >= m_size) {
        ostringstream exc;
        exc << "invalid index: " << index << endl;
        exc << "m_size: " << m_size;
        throw exc;
    }
};

template <class TT>
int Chain<TT>::index(TT& data) {
    Node<TT>* node_traverse = m_first_node;
    for (int i = 0; i < m_size; i++) {
        if (node_traverse->data == data) {
            return i;
        };
        node_traverse = node_traverse->next;
    };
    throw "no index";
};

template <class TT>
TT& Chain<TT>::get(int index) {
    checkIndex(index);
    Node<TT>* node_traverse = m_first_node;
    for (int i = 0; i < index; i++) {
        node_traverse = node_traverse->next;
    };
    return node_traverse->data;
};

template <class TT>
void Chain<TT>::append(TT& data) {
    if (m_size == 0) {
        m_first_node = new Node<TT>(data);
    } else {
        auto* p = m_first_node;
        for (int i = 0; i < m_size - 1; i++) {
            p = p->next;
        };
        p->next = new Node<TT>(data);
    };
    m_size++;
};

template <class TT>
void Chain<TT>::insert(int index, TT& data) {
    if (index < 0 || index > m_size)
        throw "invalid index to insert";
    if (index == 0) {
        m_first_node = new Node<TT>(data);
    } else {
        auto* p = m_first_node;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        };
        p->next = new Node<TT>(data);
    };
    m_size++;
};

int main() {
    Chain<int> chain = Chain<int>();
    int got_data = 0;
    for (int i = 0; i < 5; i++) {
        int data = i + 2;
        chain.append(data);
        got_data = chain.get(i);
        cout << "data: " << got_data << endl;
        cout << "index: " << chain.index(got_data) << endl;
    }
    return 0;
}
