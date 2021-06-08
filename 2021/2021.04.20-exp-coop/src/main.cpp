#include "./csvreader.hpp"
#include "./pch.hpp"

struct CSVRow {
    CSVRow() { next = nullptr; };
    explicit CSVRow(istream& s);
    friend ostream& operator<<(ostream& out, const CSVRow& rr);
    // 重载结构体 CSVRow 的流输出运算符
    friend ofstream& operator<<(ofstream& file, const CSVRow& rr);
    // 输出到文件流的运算符
    bool operator==(const CSVRow& r) const;
    // 重载 CSVRow 之间的比较运算符
    // 比较依据为 `account`, `identity`, `book`

    string account;
    string identity;
    string book;
    string date;
    CSVRow* next;
};

struct CSVRowCombi {
    CSVRowCombi() = default;
    explicit CSVRowCombi(istream& /*s*/) { next = nullptr; };
    explicit CSVRowCombi(const CSVRow& row_lend,
                         const CSVRow& row_return = CSVRow());
    friend ostream& operator<<(ostream& out, const CSVRowCombi& rr);
    // 重载结构体 CSVRow 的流输出运算符
    friend ofstream& operator<<(ofstream& file, const CSVRowCombi& rr);
    // 输出到文件流的运算符
    bool operator==(const CSVRowCombi& r) const;
    // 重载 CSVRow 之间的比较运算符
    // 比较依据为 `account`, `identity`, `book`

    string account;
    string identity;
    string book;
    string lend_date;
    string return_date;
    CSVRowCombi* next{};
};

CSVRow::CSVRow(istream& s) {
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

bool CSVRow::operator==(const CSVRow& r) const {
    return (account == r.account && identity == r.identity && book == r.book)
               ? true
               : false;
};

ostream& operator<<(ostream& out, const CSVRow& rr) {
    out << "account:   " << rr.account << endl;
    out << "identity:  " << rr.identity << endl;
    out << "book:      " << rr.book << endl;
    out << "date:      " << rr.date << endl;
    return out;
};

ofstream& operator<<(ofstream& file, const CSVRow& rr) {
    file << rr.account << ',';
    file << rr.identity << ',';
    file << rr.book << ',';
    file << rr.date << endl;
    return file;
};

CSVRowCombi::CSVRowCombi(const CSVRow& row_lend, const CSVRow& row_return) {
    // 合并两行的数据
    next = nullptr;
    account = row_lend.account;
    identity = row_lend.identity;
    book = row_lend.book;
    lend_date = row_lend.date;
    return_date = row_return.date.empty() ? "尚未归还" : row_return.date;
};

ostream& operator<<(ostream& out, const CSVRowCombi& rr) {
    out << "account:      " << rr.account << endl;
    out << "identity:     " << rr.identity << endl;
    out << "book:         " << rr.book << endl;
    out << "lend_date:    " << rr.lend_date << endl;
    out << "return_date:  " << rr.return_date << endl;
    return out;
}

ofstream& operator<<(ofstream& file, const CSVRowCombi& rr) {
    file << rr.account << ',';
    file << rr.identity << ',';
    file << rr.book << ',';
    file << rr.lend_date << ',';
    file << rr.return_date << endl;
    return file;
};

bool CSVRowCombi::operator==(const CSVRowCombi& r) const {
    return (account == r.account && identity == r.identity && book == r.book)
               ? true
               : false;
};

CSVReader<CSVRowCombi> csvreaderCombiner(CSVReader<CSVRow>& reader1,
                                         CSVReader<CSVRow>& reader2) {
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
                    // 如果借书的行没有在还书记录找到，则设为`尚未归还`
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
    string file_lend_path = "../test/lend.csv";
    string file_return_path = "../test/return.csv";
    string out_path = "./out.csv";
    // 将借书表存为 chain_lend
    ifstream filelend(file_lend_path);
    CSVReader<CSVRow> chain_lend(filelend);
    filelend.close();
    // 将还书表存为 chain_return
    ifstream filereturn(file_return_path);
    CSVReader<CSVRow> chain_return(filereturn);
    filereturn.close();
    auto chain_combi = csvreaderCombiner(chain_lend, chain_return);
    chain_combi.scanToFile(out_path);
    return 0;
}
