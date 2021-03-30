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
