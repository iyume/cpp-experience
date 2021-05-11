#pragma once

#include <string>

template <class TT>
struct CircularChainNode {
    CircularChainNode() = default;
    explicit CircularChainNode(const TT& data) {
        this->data = data;
        this->next = nullptr;
    };
    CircularChainNode(const TT& data, CircularChainNode<TT>* next) {
        this->data = data;
        this->next = next;
    };

    TT data;
    CircularChainNode<TT>* next;
};

template <class TT>
class CircularChain {
  public:
    CircularChain();
    void checkIndex(int index);
    [[nodiscard]] int length() const { return m_size; };
    int indexOf(const TT& data);       // get the index of data if matched
    TT& get(int index);              // get data by node's index
    TT& getByStudentCode(int code);  // iter table, return matched record one
    TT& getByStudentName(const std::string& name);  // return matched record one
    void append(TT& data);
    void insert(int index, TT& data);
    void erase(int index);
    void display() const;
    CircularChainNode<TT>* head();
    CircularChainNode<TT>* begin();
    CircularChainNode<TT>* end();
    bool empty();

  private:
    CircularChainNode<TT>* m_headNode;
    CircularChainNode<TT>* m_firstNode;
    int m_size;
};
