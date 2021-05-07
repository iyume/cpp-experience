#include <iostream>

using std::cout;

class Date;
class Time;
void display(const Date& d1);
void display(const Time& t1);

class Date {
  public:
    Date(int m, int d, int y) : m_month(m), m_day(d), m_year(y){};
    friend void display(const Date& d1);

  private:
    int m_month;
    int m_day;
    int m_year;
};

class Time {
  public:
    Time(int h, int m, int s) : m_hour(h), m_min(m), m_sec(s){};
    friend void display(const Time& t1);

  private:
    int m_hour;
    int m_min;
    int m_sec;
};

void display(const Date& d1) {
    cout << d1.m_month << '/' << d1.m_day << '/' << d1.m_year;
};

void display(const Time& t1) {
    cout << t1.m_hour << ':' << t1.m_min << ':' << t1.m_sec;
};

int main() {
    Time t1(10, 13, 56);
    Date d1(12, 25, 2004);
    display(d1);
    cout << std::endl;
    display(t1);
    return 0;
}
