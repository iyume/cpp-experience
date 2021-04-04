// 【问题描述】

// 商店销售某一商品,商店每天公布统一的折扣（discount）.同时允许销售人员在销售时灵活掌握售价（price）,在此基础上,对于一次购10以上的客户,还可以享受9.8折优惠.现已知当天3名销售人员的销售情况为：
// 销售员号（num） 销售件数（quantity）单价（price）
// 101                               5                          22.5
// 102                              12                         25.56
// 103                              100                      21.5
// 编写程序,计算出当日此商品的总销售款sum,以及每件商品的平均售价.要求用静态数据成员和静态成员函数.

// 【输入形式】

// Product(101,5,22.5),Product(102,12,25.56),Product(103,100,21.5)

// 【输出形式】

// 【样例输入】
// 【样例输出】
// 【样例说明】
// 【评分标准】

#include <iostream>
using namespace std;

class Product
{
public:
    Product(const int num, const int quantity, const double price) : num(num), quantity(quantity), price(price)
    {
        sold_sum += quantity;
        if (quantity > 10)
        {
            sold_volumn += quantity * price * discount * 0.98;
        }
        else
        {
            sold_volumn += quantity * price * discount;
        };
    };
    static int get_sold_sum()
    {
        return sold_sum;
    };
    static double get_sold_volumn()
    {
        return sold_volumn;
    };
    static double get_sold_price_avg()
    {
        return sold_volumn / sold_sum;
    };

private:
    int num;
    int quantity;
    double price;
    static int sold_sum;
    static double sold_volumn;
    const static double discount;
};
int Product::sold_sum = 0;
double Product::sold_volumn = 0;
const double Product::discount = 0.95;

int main()
{
    Product *ptr = new Product[3]{Product(101, 5, 22.5), Product(102, 12, 25.56), Product(103, 100, 21.5)};
    cout << Product::get_sold_volumn() << endl;
    cout << Product::get_sold_price_avg() << endl;
    delete[] ptr;
}
