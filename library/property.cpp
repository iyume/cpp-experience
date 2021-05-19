class Foo {
  private:
    template <class TT>
    struct Property {
        TT m_value;
        Property<TT>& operator=(const TT& i) {
            m_value = i;
            return *this;
        }
        explicit operator TT() const { return m_value; }
    };

  public:
    Property<int> alpha;
    Property<float> bravo;
};
