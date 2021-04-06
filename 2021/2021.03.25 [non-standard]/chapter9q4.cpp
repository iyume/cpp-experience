// 建立一个对象数组，内放5个学生的数据（学号、成绩），用指针指向数组首元素，输出第1,3,5个学生的数据。

// 【输入形式】
// 【输出形式】
// 【样例输入】

// Student(101,75.5),Student(102,85.5),Student(103,95.5),Student(104,100.0),Student(105,96.5)

// 【样例输出】

// 101 75.5

// 103 95.5

// 105 96.5

// 【样例说明】
// 【评分标准】

#include <iostream>
using namespace std;

class Student
{
public:
    Student(int num, double score) : num(num), score(score){};
    void display()
    {
        cout << num << ' ' << score << endl;
    };

private:
    int num;
    double score;
};

int main()
{
    Student *ptr = new Student[5]{Student(101, 75.5), Student(102, 85.5), Student(103, 95.5), Student(104, 100.0), Student(105, 96.5)};
    for (int i = 0; i < 5; i += 2)
    {
        ptr[i].display();
    };
    delete[] ptr;
}
