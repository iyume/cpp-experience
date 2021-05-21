# 1

【问题描述】定义 Student 基类，包含公有成员函数 get_value()和 display(),以及保护成员变量 num,name,sex，其中 get_value()输入成员变量的值，display()显示；

定义 Student 的派生类 Student1 和 Student2，

派生类 Student1 包含公有成员函数 get_value_1()和 display_1(),以及私有成员变量 age 和 addr，以公共继承的方式继承 Student；

派生类 Student2 包含公有成员函数 get_value_2()和 display_2(),以及私有成员变量 age 和 addr，以保护继承的方式继承 Student；

分别在 test01()函数和 test02()函数中实现这两种继承方式。

在程序运行时需输入 num,name,sex,age 和 addr 的值，程序应输出 5 个以上值。

【输入形式】

    test01做以下输入：

    1 zhangsan m 23 changchun

    test01做以下输入：

    2 lisi f 22 liaoning

【输出形式】

    test01输出：

    num:1

    name:zhangsan

    sex:m

    age:23

    addr:changchun

    test02输出：

    num:2

    name:lisi

    sex:f

    age:22

    addr:shenyang

【样例输入】

    1 zhangsan m 23 changchun

    2 lisi f 22 liaoning

【样例输出】

    num:1

    name:zhangsan

    sex:m

    age:23

    addr:changchun



    num:2

    name:lisi

    sex:f

    age:22

    addr:shenyang

# 2

> shit problem

分别声明 Teacher（教师）类和 Cadre（干部类），采用多重继承方式由这两个类派生出新类 Teacher_Cader（教师兼干部）类。要求：

（1）在两个基类中都包含姓名、年龄、性别、地址、电话等数据成员。

（2）在 Teacher 类中还包含数据成员 title（职称），在 Cadre 类中还包含数据成员 post（职务）。在 Teacher_Cadre 类中还包含数据成员 wages（工资）。

（3）对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同的名字，在引用这些数据成员时，指定作用域。

（4）在类体中声明成员函数，在类外定义成员函数。

（5）在派生类 Teacher_Cadre 的成员函数 show 中调用 Teacher 类中的 display 函数，输出姓名、年龄、性别、职称、地址、电话，然后再用 cout 语句输出职务与工资。
【输入形式】

    Teacher_Cadre te_ca("zhang", 55, 'nv', "prof.", "president", "Changchun", "(001)0001111", 5000);

【输出形式】

    name:zhang

    age：55

    sex：v

    title：prof.

    addr：Changchun

    tel：(001)0001111

    post：president

    wages：5000
