#include "linkedCircularList.hpp"
#include <iostream>
#include <stdexcept>
#include "pch.hpp"

template <class TT>
CircularChain<TT>::CircularChain() {
    m_firstNode = nullptr;
    m_headNode = new CircularChainNode<TT>();
    m_headNode->next = m_headNode;
    m_size = 0;
};

template <class TT>
void CircularChain<TT>::checkIndex(int index) {
    if (index < 0 || index >= m_size) {
        std::stringstream exc;
        exc << "*** Error ***" << std::endl;
        exc << "invalid index: " << index << std::endl;
        exc << "m_size: " << m_size << std::endl;
        exc << "*************" << std::endl;
        throw std::runtime_error(exc.str());
    };
};

template <class TT>
int CircularChain<TT>::indexOf(const TT& data) {
    auto* p = m_firstNode;
    for (int i = 0; i < m_size; i++) {
        if (p->data == data) {
            return i;
        };
        p = p->next;
    };
    throw std::runtime_error("indexOf runtime_error");
};

template <class TT>
TT& CircularChain<TT>::get(int index) {
    checkIndex(index);
    CircularChainNode<TT>* p = m_firstNode;
    for (int i = 0; i < index; i++) {
        p = p->next;
    };
    return p->data;
};

template <class TT>
void CircularChain<TT>::append(TT& data) {
    if (m_size == 0) {
        m_firstNode = new CircularChainNode<TT>(data, m_firstNode);
        m_headNode->next = m_firstNode;
    } else {
        auto* p = m_firstNode;
        for (int i = 0; i < m_size - 1; i++) {
            p = p->next;
        };
        p->next = new CircularChainNode<TT>(data, m_firstNode);
    };
    m_size++;
};

template <class TT>
void CircularChain<TT>::insert(int index, TT& data) {
    if (index < 0 || index >= m_size || m_size == 0) {
        throw std::runtime_error("invalid index to insert\n");
    };
    auto* p = m_firstNode;
    for (int i = 0; i < index; i++) {
        p = p->next;
    };
    p->next = new CircularChainNode<TT>(data, p->next);
    m_size++;
};

template <class TT>
void CircularChain<TT>::erase(int index) {
    checkIndex(index);
    CircularChainNode<TT>* delete_node = nullptr;
    if (index == 0) {
        delete_node = m_firstNode;
        m_firstNode = m_firstNode->next;
        // 由于尾结点指向 firstNode，所以需要重新指定
        auto* p = m_firstNode;
        for (int i = 0; i < m_size - 2; i++) {
            p = p->next;
        };
        p->next = m_firstNode;
    } else {
        auto* p = m_firstNode;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        };
        auto* delete_node = p->next;
        p->next = p->next->next;
    }
    delete delete_node;
    m_size--;
};

template <class TT>
void CircularChain<TT>::display() const {
    auto* p = m_firstNode;
    for (int i = 0; i <= m_size; i++) {
        std::cout << "**********" << std::endl;
        std::cout << "索引  " << i << std::endl;
        std::cout << p->data;
        p = p->next;
        if (i == m_size - 1) {
            std::cout << "**********" << std::endl;
        }
    }
};

template <class TT>
CircularChainNode<TT>* CircularChain<TT>::head() {
    return m_headNode;
};

template <class TT>
CircularChainNode<TT>* CircularChain<TT>::begin() {
    return m_firstNode;
};

template <class TT>
CircularChainNode<TT>* CircularChain<TT>::end() {
    auto* p = m_firstNode;
    for (int i = 0; i < m_size - 1; i++) {
        p = p->next;
    };
    return p;
};

template <class TT>
bool CircularChain<TT>::empty() {
    return m_size == 0;
};

template class CircularChain<int>;
