#include "./arraymax.hpp"

void Array_max::setValue() {
    for (int i = 1; i < 10; i++) {
        std::cin >> m_array[i];
    }
};

void Array_max::maxValue() {
    m_max = m_array[0];
    for (int i = 1; i < 10; i++) {
        if (m_array[i] > m_max) {
            m_max = m_array[i];
        }
    }
};

void Array_max::showValue() const {
    std::cout << "max=" << m_max;
}
