#include <iostream>
#include <utility>
using namespace std;

namespace personnel_department {
struct Student {
    Student(int id, string name, int age, string addr)
        : id(id), name(std::move(name)), age(age), addr(std::move(addr)) {}
    friend ostream& operator<<(ostream& out, const Student& stu) {
        out << "num:" << stu.id << ' ' << "name:" << stu.name << ' '
            << "age:" << stu.age << ' ' << "address:" << stu.addr;
        return out;
    }

    int id;
    string name;
    int age;
    string addr;
};
}  // namespace personnel_department

namespace education_department {
struct Student {
    Student(string id, string name, char sex, double score)
        : id(std::move(id)), name(std::move(name)), sex(sex), score(score) {}
    friend ostream& operator<<(ostream& out, const Student& stu) {
        out << "num:" << stu.id << ' ' << "name:" << stu.name << ' '
            << "sex:" << stu.sex << ' ' << "score:" << stu.score;
        return out;
    }

    string id;
    string name;
    char sex;
    double score;
};
}  // namespace education_department

int main() {
    personnel_department::Student s1(101, "zhangsan", 23, "changchun");
    personnel_department::Student s2(102, "lisi", 25, "shenyang");
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}