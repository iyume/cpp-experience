#include "./orderedCircularQueue.hpp"
#include <stdexcept>
#include <string>

template <class TT>
OrderedCircularQueue<TT>::OrderedCircularQueue(int init_size) {
    m_array = new TT[init_size];
    m_size_max = init_size;
    m_front = 0;
    m_back = 0;
};

template <class TT>
bool OrderedCircularQueue<TT>::empty() const {
    return m_back == m_front;
};

template <class TT>
int OrderedCircularQueue<TT>::size() const {
    return m_back - m_front;
};

template <class TT>
TT& OrderedCircularQueue<TT>::front() {
    if (empty()) {
        throw std::runtime_error("empty queue");
    };
    return m_array[m_front + 1];
};

template <class TT>
TT& OrderedCircularQueue<TT>::back() {
    return m_array[m_back];
};

template <class TT>
TT OrderedCircularQueue<TT>::pop() {
    if (m_back - m_front == 0) {
        throw std::runtime_error("empty queue");
    };
    return m_array[++m_front];
};

template <class TT>
void OrderedCircularQueue<TT>::push(const TT& val) {
    if (m_back == m_size_max) {
        throw std::runtime_error("full queue");
    };
    m_array[++m_back] = val;
};

template class OrderedCircularQueue<int>;
template class OrderedCircularQueue<std::string>;
