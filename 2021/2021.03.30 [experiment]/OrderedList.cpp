#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <library/exceptions.h>
using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

struct Form {
  string name;
  int age{};
  char sex{};
  string birth_date;
};

template <class TT>
void copyBackward(TT *arr_begin, TT *arr_end, TT *arr2_end) {
  while (arr_begin != arr_end) {
    *(--arr2_end) = *(--arr_end);
  }
};

template <class TT>
void copyFrontward(TT *arr_begin, TT *arr_end, TT *arr2_begin) {
  while (arr_begin != arr_end) {
    *(++arr2_begin) = *(++arr_begin);
  }
};

template <class TT>
void changeArrayLength(TT *&old_array, int old_length, int new_length) {
  // auto increment
  if (new_length < 0)
    throw "new length of array must more than 0";
  TT *new_array = new TT[new_length];
  int limit = (new_length < old_length)
                  ? new_length
                  : old_length; // the amount of element to be copied
  for (int i = 0; i < limit; i++) {
    // copy
    new_array[i] = old_array[i];
  };
  delete[] old_array;
  old_array = new_array;
};

template <class TT> class OrderList {
public:
  explicit OrderList(int init_len = kMInitLen);
  OrderList(const OrderList &o1) {
    for (int i = 0; i < m_listSize; i++) {
      *(m_ptr + i) = *(o1.m_ptr + i);
      m_arrayLength = o1.m_arrayLength;
      m_listSize = o1.m_listSize;
    }
  };
  ~OrderList() { delete[] m_ptr; };
  OrderList &operator=(const OrderList &ol1) {
    if (&ol1 != this) {
      // aviod self assign
      delete[] m_ptr;
      m_ptr = ol1.m_ptr;
      m_arrayLength = ol1.m_arrayLength;
      m_listSize = ol1.m_listSize;
    };
    return *this;
  };
  void checkIndexExist(int index);
  void insert(int index, const TT &element);
  void erase(int index);
  void output();

private:
  const static int kMInitLen = 10;
  TT *m_ptr;         // pointer to array
  int m_arrayLength; // storage of array, flexible
  int m_listSize;    // current list size, default to 0
};

template <class TT> OrderList<TT>::OrderList(int init_len) {
  if (init_len < 0)
    throw "init length of array must more than 0";
  m_ptr = new TT[init_len];
  m_arrayLength = init_len;
  m_listSize = 0;
};

template <class TT> void OrderList<TT>::checkIndexExist(int index) {
  // check index if valid, else throw error
  if (index < 0 || index > m_listSize) {
    ostringstream s;
    s << "index = " << index << "size = " << m_listSize;
    throw s;
  };
};

template <class TT> void OrderList<TT>::insert(int index, const TT &element) {
  checkIndexExist(index);
  if (m_listSize == m_arrayLength) {
    changeArrayLength(m_ptr, m_arrayLength, 2 * m_arrayLength);
    m_arrayLength *= 2;
  };
  if (index != m_listSize) {
    // move elements from index backward
    copyBackward(m_ptr + index, m_ptr + m_listSize, m_ptr + m_listSize + 1);
  }
  m_ptr[index] = element;
  m_listSize++;
};

template <class TT> void OrderList<TT>::erase(int index) {
  checkIndexExist(index);
  // erase while copy frontward
  copyFrontward(m_ptr + index, m_ptr + m_listSize, m_ptr + index - 1);
  m_ptr[--m_listSize].~TT();
};

template <class TT> void OrderList<TT>::output() {
  for (int i = 0; i < m_listSize; i++) {
    cout << "position: " << i << "  " << endl;
    cout << "  name: " << m_ptr[i].name << endl;
    cout << "  age: " << m_ptr[i].age << endl;
    cout << "  sex: " << m_ptr[i].sex << endl;
    cout << "  birth_date: " << m_ptr[i].birth_date << endl;
  }
};

int main() {
  Form *default_form = new Form[3];
  auto *name_list = new string[3]{"Amy", "Mike", "Jinale"};
  int *age_list = new int[3]{13, 12, 11};
  char *sex_list = new char[3]{'F', 'M', 'M'};
  auto *birth_date_list =
      new string[3]{"2000-03-12", "2001-03-01", "2000-06-21"};
  OrderList<Form> linear_list = OrderList<Form>();
  for (int i = 0; i < 3; i++) {
    default_form[i].name = name_list[i];
    default_form[i].age = age_list[i];
    default_form[i].sex = sex_list[i];
    default_form[i].birth_date = birth_date_list[i];
  };
  for (int i = 0; i < 3; i++) {
    linear_list.insert(i, default_form[i]);
  };
  Form test1 = {.name = "test_insert_to_2",
                .age = 0,
                .sex = 'T',
                .birth_date = "2020-03-30"};
  linear_list.insert(2, test1);
  Form test2 = {
      .name = "test_index_4", .age = 0, .sex = 'T', .birth_date = "2020-03-30"};
  linear_list.insert(4, test2);
  Form test3 = {
      .name = "test_index_5", .age = 0, .sex = 'T', .birth_date = "2020-03-30"};
  linear_list.insert(5, test3);
  linear_list.erase(
      4); // test: delete index of 4, and test_index_5 will in the position 4
  linear_list.output();
  return 0;
}
