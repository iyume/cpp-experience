#include <unistd.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ostream;
using std::runtime_error;
using std::string;
using std::stringstream;
namespace fs = std::filesystem;

string getCWD() {
    char abs_path[1024];
    int cnt = readlink("/proc/self/exe", abs_path, 1024);
    if (cnt < 0 || cnt >= 1024) {
        return nullptr;
    }
    // remove exe program and return a directory
    for (int i = cnt; i >= 0; --i) {
        if (abs_path[i] == '/') {
            abs_path[i + 1] = '\0';
            break;
        }
    }
    string path(abs_path);
    return path;
}

template <class TT>
struct Node {
    explicit Node(const TT& data) : data(data) { this->data = data; };
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
        stringstream exc;
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

struct CSVRow {
    explicit CSVRow(istream& s) {
        // 参数 s: 单行数据，示例 `012345,2020440002,DK234,2011-6-5`
        next = nullptr;
        string cell;
        getline(s, cell, ',');
        account = cell;
        getline(s, cell, ',');
        identity = cell;
        getline(s, cell, ',');
        book = cell;
        getline(s, cell, ',');
        date = cell;
    };
    friend ostream& operator<<(ostream& out, const CSVRow& rr) {
        // 重载结构体 CSVRow 的流输出运算符
        out << "account:   " << rr.account << endl;
        out << "identity:  " << rr.identity << endl;
        out << "book:      " << rr.book << endl;
        out << "date:      " << rr.date << endl;
        return out;
    };
    bool operator==(const CSVRow& r) const {
        // 重载 CSVRow 之间的比较运算符
        return (account == r.account && identity == r.identity &&
                book == r.book && date == r.date)
                   ? true
                   : false;
    };

    string account;
    string identity;
    string book;
    string date;
    CSVRow* next;
};

class CSVReader {
  public:
    explicit CSVReader(istream& s);

  private:
    Chain<CSVRow> m_chain;
};

CSVReader::CSVReader(istream& s) {
    string cell;
    while (getline(s, cell, '\n')) {
        stringstream cell_buffer;
        cell_buffer << cell;
        CSVRow row_obj(cell_buffer);
        m_chain.append(row_obj);
    };
};

int main() {
    fs::path cwd = getCWD();
    auto filepath = cwd / "test" / "lend.csv";
    string data;
    ifstream file(filepath);
    cout << "File path: " << filepath << endl;
    CSVReader chain(file);
    file.close();
    return 0;
}
