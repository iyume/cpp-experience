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
