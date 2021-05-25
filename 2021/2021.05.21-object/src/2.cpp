#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Teacher {
  protected:
    string m_name;
    int m_age;
    char m_sex;
    string m_addr;
    string m_tel;
    string m_title;

  public:
    void display() {
        cout << "name: " << m_name << endl;
        cout << "age: " << m_age << endl;
        cout << "sex: " << m_sex << endl;
        cout << "title: " << m_title << endl;
        cout << "addr: " << m_addr << endl;
        cout << "tel: " << m_tel;
    };
};

class Cadre {
  protected:
    string m_name;
    int m_age;
    char m_sex;
    string m_addr;
    string m_tel;
    string m_post;
};

class TeacherCadre : public Teacher, Cadre {
  private:
    int m_wages{};

  public:
    TeacherCadre(string name,
                 int age,
                 char sex,
                 string title,
                 string addr,
                 string tel,
                 string post,
                 int wages) {
        Teacher::m_name = name;
        Teacher::m_age = age;
        Teacher::m_sex = sex;
        Teacher::m_title = title;
        Teacher::m_addr = addr;
        Teacher::m_tel = tel;
        Cadre::m_post = post;
        m_wages = wages;
    };
    void show() {
        Teacher::display();
        cout << endl;
        cout << "post: " << m_post << endl;
        cout << "wages: " << m_wages;
    }
};

int main() {
    TeacherCadre tc("zhang", 55, 'v', "prof.", "Changchun", "(001)0001111",
                    "president", 5000);
    tc.show();
    return 0;
}
