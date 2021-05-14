#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Identity {
  public:
    Identity(int num, string name, char sex, string identity)
        : m_num(num), m_name(name), m_sex(sex), m_identity(identity){};
    Identity(const Identity& idx) {
        m_num = idx.m_num;
        m_name = idx.m_name;
        m_sex = idx.m_sex;
        m_identity = idx.m_identity;
    };
    void changeIdentity(string identity) { m_identity = identity; };
    friend std::ostream& operator<<(std::ostream& out, const Identity& idx) {
        out << "num:" << idx.m_num << ',' << "name:" << idx.m_name << ','
            << "sex:" << idx.m_sex << ',' << "identity:" << idx.m_identity;
        return out;
    };

  private:
    int m_num;
    string m_name;
    char m_sex;
    string m_identity;
};

int main() {
    Identity student(202001, "LiHua", 'm', "student");
    Identity teacher1(202002, "ZhangSan", 'm', "teacher");
    cout << "student:" << endl << student << endl;
    cout << "teacher1:" << endl << teacher1 << endl;
    Identity teacher2(student);
    teacher2.changeIdentity("teacher");
    cout << "teacher2:" << endl << teacher2 << endl;
    return 0;
}
