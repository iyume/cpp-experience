#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class StudentBase {
  protected:
    int m_num;
    string m_name;
    char m_sex;

  public:
    void getValue();
    void display();
};

class Student1 : public StudentBase {
  private:
    int m_age;
    string m_addr;

  public:
    void getValue1() {
        // can be a operator>> istream overloading
        cin >> m_num;
        cin >> m_name;
        cin >> m_sex;
        cin >> m_age;
        cin >> m_addr;
    };
    void display1() {
        cout << "num:" << m_num << endl;
        cout << "name:" << m_name << endl;
        cout << "sex:" << m_sex << endl;
        cout << "age:" << m_age << endl;
        cout << "addr:" << m_addr;
    };
};

class Student2 : protected StudentBase {
  private:
    int m_age;
    string m_addr;

  public:
    void getValue2() {
        cin >> m_num;
        cin >> m_name;
        cin >> m_sex;
        cin >> m_age;
        cin >> m_addr;
    };
    void display2() {
        cout << "num:" << m_num << endl;
        cout << "name:" << m_name << endl;
        cout << "sex:" << m_sex << endl;
        cout << "age:" << m_age << endl;
        cout << "addr:" << m_addr;
    };
};

void test01(Student1& s) {
    s.getValue1();
};

void test02(Student2& s) {
    s.getValue2();
}

int main() {
    Student1 s1;
    Student2 s2;
    test01(s1);
    test02(s2);
    s1.display1();
    cout << endl;
    s2.display2();
    return 0;
}
