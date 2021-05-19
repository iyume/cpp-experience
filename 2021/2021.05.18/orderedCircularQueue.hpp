template <class TT>
class OrderedCircularQueue {
  public:
    explicit OrderedCircularQueue(int init_size = 100);
    [[nodiscard]] bool empty() const;
    [[nodiscard]] int size() const;
    TT& front();
    TT& back();
    TT pop();  // 删除首元素
    void push(const TT& val);

  private:
    TT* m_array;
    int m_front;
    int m_back;
    int m_size_max;
};
