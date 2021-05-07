#pragma once
#include <iostream>

class Array_max {
  public:
    void setValue();
    void maxValue();
    void showValue() const;

  private:
    int m_array[10];
    int m_max;
};
