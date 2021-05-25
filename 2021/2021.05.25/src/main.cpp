#include <iostream>
#include <stdexcept>

class StringAbs {
  private:
    char* m_array;
    int m_strlen;

  public:
    explicit StringAbs(const char* s) {
        int cur = 0;
        while (s[cur] != '\0') {
            cur++;
        };
        m_strlen = cur;
        m_array = new char[m_strlen];
        for (int i = 0; i < cur; i++) {
            m_array[i] = s[i];
        }
    };
    [[nodiscard]] int len() const { return m_strlen; };
    [[nodiscard]] char* str() const { return m_array; };
    [[nodiscard]] char* slice(int start, int end) const {
        char* s = new char[end - start];
        for (int i = 0; i < end - start; i++) {
            s[i] = m_array[i + start];
        };
        return s;
    };
    int find(const char* s) const {
        // BMHS base algorithm
        int s_len = 0;
        while (s[s_len] != '\0') {
            s_len++;
        };
        for (int cur = 0; cur < m_strlen; cur++) {
            char* tmp = slice(cur, cur + s_len);
            if (*tmp == *s) {
                return cur;
            };
        };
        throw std::runtime_error("no matched");
    };
    friend std::ostream& operator<<(std::ostream& out, const StringAbs& s) {
        out << s.m_array;
        return out;
    };
};

class StringFlex {
  private:
    char* m_array;
    int m_strlen;

  public:
    explicit StringFlex(const char* s) {
        int cur = 0;
        while (s[cur] != '\0') {
            cur++;
        };
        m_strlen = cur;
        m_array = new char[m_strlen];
        for (int i = 0; i < cur; i++) {
            m_array[i] = s[i];
        };
    };
    [[nodiscard]] int len() const { return m_strlen; };
    [[nodiscard]] char* str() const { return m_array; };
    StringFlex operator+(const StringFlex& s) {
        char* c = nullptr;
        int c_len = m_strlen + s.m_strlen;
        c = new char[c_len];
        for (int i = 0; i < m_strlen; i++) {
            c[i] = m_array[i];
        };
        for (int i = m_strlen; i < c_len; i++) {
            c[i] = s.m_array[i - m_strlen];
        };
        return StringFlex(c);
    };
    StringFlex operator+(const StringAbs& s) {
        char* c = nullptr;
        int c_len = m_strlen + s.len();
        c = new char[c_len];
        for (int i = 0; i < m_strlen; i++) {
            c[i] = m_array[i];
        };
        for (int i = m_strlen; i < c_len; i++) {
            c[i] = s.str()[i - m_strlen];
        };
        return StringFlex(c);
    };
    friend StringFlex operator+(const StringAbs& s1, const StringFlex& s2) {
        char* c = nullptr;
        int c_len = s1.len() + s2.len();
        c = new char[c_len];
        for (int i = 0; i < s1.len(); i++) {
            c[i] = s1.str()[i];
        };
        for (int i = s1.len(); i < c_len; i++) {
            c[i] = s2.str()[i - s1.len()];
        };
        return StringFlex(c);
    };
    friend std::ostream& operator<<(std::ostream& out, const StringFlex& s) {
        out << s.m_array;
        return out;
    };
};

int main() {
    StringAbs s1("string1");
    StringFlex s2("string2");
    StringFlex s3("string3");
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s1+s2: " << s1 + s2 << std::endl;
    std::cout << "s2+s1: " << s2 + s1 << std::endl;
    std::cout << "s2+s3: " << s2 + s3 << std::endl;
    try {
        std::cout << "s1.find(\"ing\"): " << s1.find("ing") << std::endl;
    } catch (std::runtime_error& exc) {
        std::cout << "error: " << exc.what() << std::endl;
    };
    try {
        std::cout << "s1.find(\"ring\"): " << s1.find("ring") << std::endl;
    } catch (std::runtime_error& exc) {
        std::cout << "error: " << exc.what() << std::endl;
    };
    return 0;
}
