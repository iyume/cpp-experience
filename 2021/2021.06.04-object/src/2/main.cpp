#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

struct Employee {
    string code;
    string name;
    int age = 0;
    int money = 0;

    Employee() = default;
    explicit Employee(const string& s) {
        // 输入形式：3 hu 8 777
        istringstream sbuf(s);
        sbuf >> code;
        sbuf >> name;
        sbuf >> age;
        sbuf >> money;
    }
    friend ostream& operator<<(ostream& out, const Employee& e) {
        out << e.code << ' ' << e.name << ' ' << e.age << ' ' << e.money
            << endl;
        return out;
    }
    bool static sort(const Employee& e1, const Employee& e2) {
        return e1.code < e2.code;
    }
};

int main() {
    // 1）按职工号由小到大的顺序将 5
    // 个员工的数据（包括号码、姓名、年龄、工资）输出到磁盘文件中保存。
    const char* filename = "./data.txt";
    {
        // read from keyboard and save to employee array
        string linestr;
        const int init_employee_count = 5;
        auto* employees = new Employee[init_employee_count];
        for (int i = 0; i < init_employee_count; i++) {
            getline(cin, linestr);
            employees[i] = Employee(linestr);
        }
        // sort by employee code
        sort(employees, employees + init_employee_count, Employee::sort);
        // save to file
        {
            ofstream fb(filename);
            for (int i = 0; i < init_employee_count; i++) {
                fb << employees[i];
            }
            // brace for auto deconstruct and close filebuf
        }
    }
    // 2）从键盘输入两个员工的数据（职工号大于已有的职工号），增加到文件的末尾。
    {
        ofstream fb(filename, ios::app);
        string linestr;
        getline(cin, linestr);
        fb << Employee(linestr);
        getline(cin, linestr);
        fb << Employee(linestr);
    }
    // 3）输出文件中全部职工的数据。
    {
        ifstream fb(filename);
        ostringstream ss;
        ss << fb.rdbuf();
        cout << "*** all employee ***" << endl;
        cout << ss.str();
        cout << "********************" << endl;
    }
    // 4）从键盘输入一个号码，在文件中查找有无此职工号
    // 如有则显示此职工是第几个职工，以及此职工的全部数据。
    // 如没有，就输出“无此人”。
    // 可以反复多次查询，如果输入查找的职工号为 0，就结束查询。
    {
        string in_code;
        cout << "输入需要查找的员工编号: ";
        while (cin >> in_code) {
            if (in_code == "0") {
                return 0;
            }
            string linestr;
            ifstream fb(filename);
            int num = 0;
            cout << "查找中..." << endl;
            while (++num != 0) {
                getline(fb, linestr);
                if (linestr.empty()) {
                    cout << "员工不存在，输入下一个需要查找的员工编号: ";
                    break;
                }
                Employee employee(linestr);
                if (employee.code == in_code) {
                    cout << "员工编号 " << in_code << " 为第 " << num
                         << " 个员工" << endl;
                    cout << "*** employee info ***" << endl;
                    cout << employee;
                    cout << "*********************" << endl;
                    cout << "输入下一个需要查找的员工编号: ";
                    break;
                }
            }
        }
    }
    return 0;
}
