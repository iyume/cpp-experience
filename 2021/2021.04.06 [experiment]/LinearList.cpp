#include <cstdint>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ostringstream;
using std::runtime_error;
using std::string;
using std::to_string;

struct StudentHealthSheet {
    int64_t code{};        // 学生编号，唯一，主键 (uuid)
    string name;           // 学生姓名
    char sex{};            // 学生性别
    bool is_health{};      // 学生是否健康
    int created_time = 0;  // timestamp

    bool operator==(StudentHealthSheet& s) const { return code == s.code; };
    friend ostream& operator<<(ostream& out, const StudentHealthSheet& s) {
        out << "学生编号      " << s.code << endl;
        out << "学生姓名      " << s.name << endl;
        out << "学生性别      " << s.sex << endl;
        out << "学生健康情况   " << (s.is_health ? "健康" : "风险") << endl;
        return out;
    };
};

template <class TT>
struct Node {
    explicit Node(const TT& data) { this->data = data; };
    Node(const TT& data, Node<TT>* next) {
        this->data = data;
        this->next = next;
    };

    TT data;
    Node<TT>* next;
};

template <class TT>
class Chain {
  public:
    Chain();
    void checkIndex(int index);
    int length() { return m_size; };
    int index(TT& data);             // get the index of data if matched
    TT& get(int index);              // get data by node's index
    TT& getByStudentCode(int code);  // iter table, return matched record one
    TT& getByStudentName(const string& name);  // return matched record one
    void append(TT& data);
    void insert(int index, TT& data);
    void erase(int index);
    void display() const;

  private:
    Node<TT>* m_first_node;
    int m_size;
};

template <class TT>
Chain<TT>::Chain() {
    m_first_node = nullptr;
    m_size = 0;
};

template <class TT>
void Chain<TT>::checkIndex(int index) {
    if (index < 0 || index >= m_size) {
        ostringstream exc;
        exc << "*** Error ***" << endl;
        exc << "invalid index: " << index << endl;
        exc << "m_size: " << m_size << endl;
        exc << "*************" << endl;
        throw runtime_error(exc.str());
    };
};

template <class TT>
int Chain<TT>::index(TT& data) {
    Node<TT>* p = m_first_node;
    for (int i = 0; i < m_size; i++) {
        if (p->data == data) {
            return i;
        };
        p = p->next;
    };
    throw runtime_error("no matched index\n");
};

template <class TT>
TT& Chain<TT>::get(int index) {
    checkIndex(index);
    Node<TT>* p = m_first_node;
    for (int i = 0; i < index; i++) {
        p = p->next;
    };
    return p->data;
};

template <class TT>
TT& Chain<TT>::getByStudentCode(int code) {
    Node<TT>* p = m_first_node;
    for (int i = 0; i < m_size; i++) {
        if ((p->data).code == code) {
            return p->data;
        };
        p = p->next;
    };
    throw runtime_error("no matched student code\n");
};

template <class TT>
TT& Chain<TT>::getByStudentName(const string& name) {
    Node<TT>* p = m_first_node;
    for (int i = 0; i < m_size; i++) {
        if ((p->data).name == name) {
            return p->data;
        };
        p = p->next;
    };
    throw runtime_error("no matched student name\n");
};

template <class TT>
void Chain<TT>::append(TT& data) {
    if (m_size == 0) {
        m_first_node = new Node<TT>(data);
    } else {
        auto* p = m_first_node;
        for (int i = 0; i < m_size - 1; i++) {
            p = p->next;
        };
        p->next = new Node<TT>(data);
    };
    m_size++;
};

template <class TT>
void Chain<TT>::insert(int index, TT& data) {
    if (index < 0 || index > m_size) {
        throw runtime_error("invalid index to insert\n");
    }
    if (index == 0) {
        m_first_node = new Node<TT>(data);
    } else {
        auto* p = m_first_node;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        };
        p->next = new Node<TT>(data, p->next);
    };
    m_size++;
};

template <class TT>
void Chain<TT>::erase(int index) {
    checkIndex(index);
    Node<TT>* delete_node = nullptr;
    if (index == 0) {
        delete_node = m_first_node;
        m_first_node = m_first_node->next;
    } else {
        auto* p = m_first_node;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        delete_node = p->next;
        p->next = p->next->next;
    }
    delete delete_node;
    m_size--;
};

template <class TT>
void Chain<TT>::display() const {
    Node<TT>* p = m_first_node;
    for (int i = 0; i < m_size; i++) {
        cout << "**********" << endl;
        cout << "索引  " << i << endl;
        cout << p->data;
        p = p->next;
        if (i == m_size - 1) {
            cout << "**********" << endl;
        }
    }
};

int main() {
    Chain<StudentHealthSheet> chain = Chain<StudentHealthSheet>();
    void initChain(Chain<StudentHealthSheet> & chain);
    void showDoc();
    void showCRUDRepeatMsg();
    void fulfillStudent(StudentHealthSheet & student);
    showDoc();

    cout << "[0] 不加入" << endl;
    cout << "[1] 加入" << endl;
    cout << "是否需要加入初始化数据 [0-1]: ";
    {
        int init = 0;
        cin >> init;
        if (init == 1) {
            initChain(chain);
        };
    };
    cout << "当前表长度: " << chain.length() << endl;
    int command = 0;
    showCRUDRepeatMsg();
    while (cin >> command) {
        switch (command) {
            case 1: {  // create
                StudentHealthSheet new_student;
                fulfillStudent(new_student);
                cout << "选择插入位置的索引 ( -1 追加到末尾): ";
                string msg;
                cin >> msg;
                if (msg == "-1") {
                    chain.append(new_student);
                } else {
                    try {
                        chain.insert(std::stoi(msg), new_student);
                    } catch (const runtime_error& exc) {
                        cout << exc.what();
                    };
                };
                break;
            };
            case 2: {  // read
                int read_command = 0;
                cout << "[1] 索引" << endl;
                cout << "[2] 学生编号" << endl;
                cout << "[3] 学生姓名" << endl;
                cout << "[4] 所有" << endl;
                cout << "选择作为读取学生记录的依据 [1-4]: ";
                cin >> read_command;
                switch (read_command) {
                    case 1: {
                        int index = 0;
                        cout << "索引: ";
                        cin >> index;
                        StudentHealthSheet student;
                        try {
                            student = chain.get(index);
                        } catch (const runtime_error& exc) {
                            cout << exc.what();
                            break;
                        };
                        cout << "*** result ***" << endl;
                        cout << student;
                        cout << "**************" << endl;
                        break;
                    };
                    case 2: {
                        int code = 0;
                        cout << "学生编号: ";
                        cin >> code;
                        StudentHealthSheet student;
                        try {
                            student = chain.getByStudentCode(code);
                        } catch (const runtime_error& exc) {
                            cout << exc.what();
                            break;
                        };
                        cout << "*** result ***" << endl;
                        cout << student;
                        cout << "**************" << endl;
                        break;
                    };
                    case 3: {
                        string name;
                        cout << "学生姓名: ";
                        cin >> name;
                        StudentHealthSheet student;
                        try {
                            student = chain.getByStudentName(name);
                        } catch (const runtime_error& exc) {
                            cout << exc.what();
                            break;
                        };
                        cout << "*** result ***" << endl;
                        cout << student;
                        cout << "**************" << endl;
                        break;
                    };
                    case 4: {
                        chain.display();
                        break;
                    };
                    default: {
                        cout << "操作失败" << endl;
                    };
                }
                break;
            };
            case 3: {  // update
                int index = 0;
                cout << "输入待更新的索引: ";
                cin >> index;
                StudentHealthSheet* student = nullptr;
                try {
                    student = &chain.get(index);
                } catch (const runtime_error& exc) {
                    cout << exc.what();
                    break;
                };
                cout << "*** update ***" << endl;
                cout << *student;
                cout << "**************" << endl;
                cout << "输入新名字: ";
                cin >> student->name;
                cout << "输入新性别 [F/M]: ";
                cin >> student->sex;
                cout << "输入新的健康情况 [Y/N]: ";
                string msg;
                cin >> msg;
                if (msg == "Y") {
                    student->is_health = true;
                } else {
                    student->is_health = false;
                };
                break;
            };
            case 4: {  // delete
                int index = 0;
                cout << "输入待删除的索引: ";
                cin >> index;
                try {
                    chain.erase(index);
                } catch (const runtime_error& exc) {
                    cout << exc.what();
                    break;
                };
                break;
            };
            default: {
                cout << "操作失败" << endl;
            };
        };
        cout << "当前表长度: " << chain.length() << endl;
        showCRUDRepeatMsg();
    };
    return 0;
};

void initChain(Chain<StudentHealthSheet>& chain) {
    const char init_sex = 'F';
    const bool init_is_health = true;
    auto* students = new StudentHealthSheet[10];
    for (int i = 0; i < 10; i++) {
        students[i] = {.code = i,
                       .name = "init_name" + to_string(i),
                       .sex = init_sex,
                       .is_health = init_is_health};
        chain.append(students[i]);
    };
};

void showDoc() {
    cout << "Welcome to LinearList with template data!" << endl;
    cout << "Here you can do simple CRUD-like function. Interactively!" << endl;

    cout << "可使用的操作:" << endl;
    cout << "------- Create -------" << endl;
    cout << "交互式，创建学生记录，选择插入位置，默认插入尾部" << endl;
    cout << "------- Read -------" << endl;
    cout << "交互式，读取学生记录" << endl;
    cout << "依据:" << endl;
    cout << "  1.索引" << endl;
    cout << "  2.学生编号" << endl;
    cout << "  3.学生姓名" << endl;
    cout << "  4.所有" << endl;
    cout << "------- Update -------" << endl;
    cout << "交互式，更新学生记录，Read 一条数据并进行修改" << endl;
    cout << "------- Delete -------" << endl;
    cout << "交互式，删除学生记录，依据有索引、学生编号" << endl;
    cout << endl;
};

void showCRUDRepeatMsg() {
    cout << "[1] create  创建" << endl;
    cout << "[2] read    读取" << endl;
    cout << "[3] update  更新" << endl;
    cout << "[4] delete  删除" << endl;
    cout << "输入下一步操作 [1-4]: ";
};

void fulfillStudent(StudentHealthSheet& student) {
    cout << "即将创建新学生记录..." << endl;
    cout << "学生编号: ";
    cin >> student.code;
    cout << "学生姓名: ";
    cin >> student.name;
    cout << "学生性别: (F/M) ";
    cin >> student.sex;
    cout << "学生健康状态: (Y/N) ";
    string msg;
    cin >> msg;
    if (msg == "Y") {
        student.is_health = true;
    } else {
        student.is_health = false;
    }
};
