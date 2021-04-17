#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::ostringstream;

template <class TT>
struct Node {
    explicit Node(const TT& element) { this->element = element; };
    Node(const TT& element, Node<TT>* next) {
        this->element = element;
        this->next = next;
    };

    TT element;
    Node<TT>* next;
};

template <class TT>
class Chain {
  public:
    Chain();
    void checkIndex(int index);
    int index(TT& element);  // get the index of element if matched
    TT& get(int index);      // get element by node's index
    void insert(int index, TT& element);

  private:
    Node<TT>* m_first_node;
    Node<TT>* m_current_node;
    int m_size;
};

template <class TT>
Chain<TT>::Chain() {
    m_first_node = nullptr;
    m_current_node = nullptr;
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
int Chain<TT>::index(TT& element) {
    Node<TT>* node_traverse = m_first_node;
    for (int i = 0; i < m_size; i++) {
        if (node_traverse->element == element) {
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
    return node_traverse->element;
};

template <class TT>
void Chain<TT>::insert(int index, TT& element) {
    if (index < 0 || index > m_size)
        throw "invalid index to insert";
    if (index == 0) {
        m_first_node = new Node<TT>(element);
    } else {
        auto* p = m_first_node;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        };
        p->next = new Node<TT>(element);
    };
    m_size++;
};

int main() {
    Chain<int> chain = Chain<int>();
    int got_element = 0;
    for (int i = 0; i < 5; i++) {
        int element = i + 2;
        chain.insert(i, element);
        got_element = chain.get(i);
        cout << "element: " << got_element << endl;
        cout << "index: " << chain.index(got_element) << endl;
    }
    return 0;
}
