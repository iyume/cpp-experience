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
