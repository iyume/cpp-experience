# 1

# 1.1

【问题描述】
在例 12.3 的基础上作以下修改，并作必要的讨论。

(1) 把构造函数修改为带参数的函数，在建立对象时初始化。

(2) 先不将析构函数声明为 virtual，在 main 函数中另设一个指向 Circle 类对象的指针变量，使它指向 p1。运行程序，分析结果。

【输入形式】
输入不做要求，可以根据定义的类型进行任意赋值。
new circle（2,5,7）
【输出形式】
executing Circle destructor
executing Point destructor
【样例输入】
【样例输出】

## 1.2

【问题描述】
在例 12.3 的基础上作以下修改，并作必要的讨论。

(1) 把构造函数修改为带参数的函数，在建立对象时初始化。

(3) 不作第(2)点的修改而将析构函数声明为 virtual，运行程序，分析结果。

【输入形式】
输入不做要求，可以根据定义的类型进行任意赋值。
new circle（2,5,7）
【输出形式】
executing Circle destructor
executing Point destructor
【样例输入】
【样例输出】

# 2

【问题描述】编写一个程序，定义抽象基类 Shape，由他派生出三个派生类：Circle(圆形)、Rectangle（矩形）和 Triangle（三角形），用一个数函数 ShowArea（）分别显示各种图形的面积，3 个图形的数据在定义时给出。
【输入形式】
在定义对象时传入 Circle 的半径 r=2;
rectangle 的长和宽 length=12,width=2;
triangle 的三条边长 a=3,b=4,c=5;（可用海伦公式求/也可当做直角三角形处理）
【输出形式】
分别输出三者的面积

【样例输入】
Circle circle(2);
Rectangle rectangle(12, 2);
Triangle triangle(3, 4, 5);
【样例输出】
12.56
24
6

# 3

【问题描述】编写一个程序,定义抽象基类 Shape，由它派生出５个派生类：Cricle（圆形),Square（正方形)， Rectangle（矩形）， Trapezoid （梯形）,Triangle（三角形）。用虚函数分别计算图形面积，并求所有图形面积的和．要求用基类指针数组，使它的每一个元素指向一个派生类对象。
【输入形式】
在定义对象时传入 Circle 的半径 r=2;
square 的边长 x=5;
rectangle 的长和宽 length=12,width=2;
trapezoid 的上底、下底和高 a=10,b=40,c=5;
triangle 的三条边长 a=3,b=4,c=5;（可用海伦公式求/也可当做直角三角形处理）
【输出形式】
输出面积的和 sum；

【样例输入】
Circle circle(2);
Square square(5);
Rectangle rectangle(12, 2);
Trapezoid trapezoid(10, 40, 5);
Triangle triangle(3, 4, 5);
【样例输出】
sum = 192.56
