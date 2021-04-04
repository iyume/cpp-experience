// 【问题描述】
// 建立一个对象数组,内放5个学生的数据(学号、成绩),设立一个函数max,用 指向对象的指针作函数参数，在max函数中找出5个学生中成绩最高者，输出此学号及成绩。

// 【输入形式】
// 【输出形式】
// 【样例输入】

// Student(101,78.5),Student(102,85.5),Student(103,98.5),   Student(104,99.5),Student(105,95.5) 

// 【样例输出】

// 104 99.5

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
    int get_num() const
    {
        return num;
    };
    float get_score() const
    {
        return score;
    };

private:
    int num;
    double score;
};

Student max(const Student *p, const int len)
{
    // return max index
    Student _max = p[0];
    for (int i = 0; i < len; i++)
    {
        if (p[i].get_score() > _max.get_score())
        {
            _max = p[i];
        };
    };
    return _max;
};

int main()
{
    const Student *ptr = new Student[5]{Student(101, 78.5), Student(102, 85.5), Student(103, 98.5), Student(104, 99.5), Student(105, 95.5)};
    Student student_max = max(ptr, 5);
    student_max.display();
    delete[] ptr;
}
