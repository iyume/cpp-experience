#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::runtime_error;
using std::string;
using std::stringstream;

template <class TT>
struct Node {
    explicit Node(const TT data, Node<TT>* next = nullptr)
        : data(data), next(next){};

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
            // ::==:: operator overloading required
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
        // checkIndex only validate the index
        // but insert function allow insert to the end of chain
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
            // stay in the front of index, and delete the next
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
        // ::<<:: operator overloading required
        cout << p->data;
        p = p->next;
        if (i == m_size - 1) {
            cout << "**********" << endl;
        }
    }
};

struct CSVRow {
    CSVRow() { next = nullptr; };
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
    friend ofstream& operator<<(ofstream& file, const CSVRow& rr) {
        // 输出到文件流的运算符
        file << rr.account << ',';
        file << rr.identity << ',';
        file << rr.book << ',';
        file << rr.date << endl;
        return file;
    };
    bool operator==(const CSVRow& r) const {
        // 重载 CSVRow 之间的比较运算符
        // 比较依据为 `account`, `identity`, `book`
        return (account == r.account && identity == r.identity &&
                book == r.book)
                   ? true
                   : false;
    };

    string account;
    string identity;
    string book;
    string date;
    CSVRow* next;
};

struct CSVRowCombi {
    CSVRowCombi() = default;
    explicit CSVRowCombi(const CSVRow& row_lend,
                         const CSVRow& row_return = CSVRow()) {
        // 合并两行的数据
        next = nullptr;
        account = row_lend.account;
        identity = row_lend.identity;
        book = row_lend.book;
        lend_date = row_lend.date;
        return_date = row_return.date.empty() ? "尚未归还" : row_return.date;
    };
    friend ostream& operator<<(ostream& out, const CSVRowCombi& rr) {
        // 重载结构体 CSVRow 的流输出运算符
        out << "account:      " << rr.account << endl;
        out << "identity:     " << rr.identity << endl;
        out << "book:         " << rr.book << endl;
        out << "lend_date:    " << rr.lend_date << endl;
        out << "return_date:  " << rr.return_date << endl;
        return out;
    };
    friend ofstream& operator<<(ofstream& file, const CSVRowCombi& rr) {
        // 输出到文件流的运算符
        file << rr.account << ',';
        file << rr.identity << ',';
        file << rr.book << ',';
        file << rr.lend_date << ',';
        file << rr.return_date << endl;
        return file;
    };

    string account;
    string identity;
    string book;
    string lend_date;
    string return_date;
    CSVRowCombi* next{};
};

template <class TT>
class CSVReader {
  public:
    CSVReader() = default;
    explicit CSVReader(istream& s);
    // TT& begin() { return m_chain.get(0); };
    TT& get(int index) { return m_chain.get(index); };
    void append(TT& row) { m_chain.append(row); };
    void display() const { m_chain.display(); };
    int size() { return m_chain.length(); };
    void scanToFile(string& filepath);

  private:
    Chain<TT> m_chain;
};

template <class TT>
CSVReader<TT>::CSVReader(istream& s) {
    string cell;
    while (getline(s, cell, '\n')) {
        stringstream cell_buffer;
        cell_buffer << cell;
        TT row_obj(cell_buffer);
        m_chain.append(row_obj);
    };
};

template <class TT>
void CSVReader<TT>::scanToFile(string& filepath) {
    ofstream file(filepath);
    const int chain_size = size();
    for (int i = 0; i < chain_size; i++) {
        file << this->get(i);
    };
    file.close();
};

CSVReader<CSVRowCombi> csvreaderCombiner(CSVReader<CSVRow>& reader1,
                                         CSVReader<CSVRow>& reader2) {
    // 合并两个 csv
    CSVReader<CSVRowCombi> csvreader_combi;
    for (int i = 0; i < reader1.size(); i++) {
        for (int j = 0; j < reader2.size(); j++) {
            try {
                auto row1 = reader1.get(i);
                auto row2 = reader2.get(j);
                if (row1 == row2) {
                    // 借书的行 == 还书的行，则结合两行数据并追加到链表尾部
                    CSVRowCombi row_combi(row1, row2);
                    csvreader_combi.append(row_combi);
                    break;
                };
                if (j == reader2.size() - 1) {
                    CSVRowCombi row_combi(row1);
                    csvreader_combi.append(row_combi);
                };
            } catch (const runtime_error& exc) {
                cout << exc.what();
            }
        }
    }
    return csvreader_combi;
};

int main() {
    // due to filesystem absolute path required c++17, impl downgrade to string
    string file_lend_path = "./test/lend.csv";
    string file_return_path = "./test/return.csv";
    string out_path = "./out.csv";
    // 将借书表存为 chain_lend
    ifstream filelend(file_lend_path);
    CSVReader<CSVRow> chain_lend(filelend);
    filelend.close();
    // 将还书表存为 chain_return
    ifstream filereturn(file_return_path);
    CSVReader<CSVRow> chain_return(filereturn);
    filereturn.close();
    CSVReader<CSVRowCombi> chain_combi =
        csvreaderCombiner(chain_lend, chain_return);
    chain_combi.scanToFile(out_path);
    return 0;
}
