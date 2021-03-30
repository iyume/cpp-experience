#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;

struct Form
{
    string name;
    int age;
    char sex;
    string birth_date;
};

template <class T>
void copy_backward_(T *arr_begin, T *arr_end, T *arr2_end)
{
    while (arr_begin != arr_end)
        *(--arr2_end) = *(--arr_end);
};

template <class T>
void copy_frontward_(T *arr_begin, T *arr_end, T *arr2_begin)
{
    while (arr_begin != arr_end)
        *(++arr2_begin) = *(++arr_begin);
};

template <class T>
void changeArrayLength(T *&oldArray, int oldLength, int newLength)
{
    // auto increment
    if (newLength < 0)
        throw "new length of array must more than 0";
    T *newArray = new T[newLength];
    int limit = (newLength < oldLength) ? newLength : oldLength; // the amount of element to be copied
    for (int i = 0; i < limit; i++)
    {
        // copy
        newArray[i] = oldArray[i];
    };
    delete[] oldArray;
    oldArray = newArray;
};

template <class T>
class OrderList
{
public:
    OrderList(int init_len = 10);
    ~OrderList() { delete[] ptr; };
    void checkIndexExist(int index);
    void insert(int index, const T &element);
    void erase(int index);
    void output();

private:
    T *ptr;          // pointer to array
    int arrayLength; // storage of array, flexible
    int listSize;    // current list size, default to 0
};

template <class T>
OrderList<T>::OrderList(int init_len)
{
    if (init_len < 0)
        throw "init length of array must more than 0";
    ptr = new T[init_len];
    arrayLength = init_len;
    listSize = 0;
};

template <class T>
void OrderList<T>::checkIndexExist(int index)
{
    // check index if valid, else throw error
    if (index < 0 || index > listSize)
    {
        ostringstream s;
        s << "index = " << index << "size = " << listSize;
        throw s;
    };
};

template <class T>
void OrderList<T>::insert(int index, const T &element)
{
    checkIndexExist(index);
    if (listSize == arrayLength)
    {
        changeArrayLength(ptr, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    };
    if (index != listSize)
    {
        // move elements from index backward
        copy_backward_(ptr + index, ptr + listSize, ptr + listSize + 1);
    }
    ptr[index] = element;
    listSize++;
};

template <class T>
void OrderList<T>::erase(int index)
{
    checkIndexExist(index);
    // erase while copy frontward
    copy_frontward_(ptr + index, ptr + listSize, ptr + index - 1);
    ptr[--listSize].~T();
};

template <class T>
void OrderList<T>::output()
{
    for (int i = 0; i < listSize; i++)
    {
        cout << "position: " << i << "  " << endl;
        cout << "  name: " << ptr[i].name << endl;
        cout << "  age: " << ptr[i].age << endl;
        cout << "  sex: " << ptr[i].sex << endl;
        cout << "  birth_date: " << ptr[i].birth_date << endl;
    }
};

int main()
{
    Form *defaultForm = new Form[3];
    string *name_list = new string[3]{"Amy", "Mike", "Jinale"};
    int *age_list = new int[3]{13, 12, 11};
    char *sex_list = new char[3]{'F', 'M', 'M'};
    string *birth_date_list = new string[3]{"2000-03-12", "2001-03-01", "2000-06-21"};
    OrderList linearList = OrderList<Form>();
    for (int i = 0; i < 3; i++)
    {
        defaultForm[i].name = name_list[i];
        defaultForm[i].age = age_list[i];
        defaultForm[i].sex = sex_list[i];
        defaultForm[i].birth_date = birth_date_list[i];
    };
    for (int i = 0; i < 3; i++)
    {
        linearList.insert(i, defaultForm[i]);
    };
    Form test1 = {.name = "test_insert_to_2", .age = 0, .sex = 'T', .birth_date = "2020-03-30"};
    linearList.insert(2, test1);
    Form test2 = {.name = "test_index_4", .age = 0, .sex = 'T', .birth_date = "2020-03-30"};
    linearList.insert(4, test2);
    Form test3 = {.name = "test_index_5", .age = 0, .sex = 'T', .birth_date = "2020-03-30"};
    linearList.insert(5, test3);
    linearList.erase(4); // test: delete index of 4, and test_index_5 will in the position 4
    linearList.output();
    return 0;
}
