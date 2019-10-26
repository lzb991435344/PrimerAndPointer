

#ifndef SALESITEM_H
// we're here only if SALESITEM_H has not yet been defined 
#define SALESITEM_H

#include "Version_test.h" 

//类定义和操作符重载


// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_item {
// these declarations are explained section 7.2.1, p. 270 
// and in chapter 14, pages 557, 558, 561
friend std::istream& operator>>(std::istream&, Sales_item&);
friend std::ostream& operator<<(std::ostream&, const Sales_item&);
friend bool operator<(const Sales_item&, const Sales_item&);
friend bool 
operator==(const Sales_item&, const Sales_item&);
public:
    // constructors are explained in section 7.1.4, pages 262 - 265
    // default constructor needed to initialize members of built-in type

#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
//若定义类初始值设置及默认值，则定义默认构造函数,不接受任何实参；
    Sales_item() = default;
#else
	/*若未定义类初始值及默认值，则定义构造函数，函数体空；
   构造函数初始列表为新创建的数据成员units_sold/revenue初始化，对应初始化值为0/0.0；*/
    Sales_item(): units_sold(0), revenue(0.0) { }
#endif
    Sales_item(const std::string &book):
              bookNo(book), units_sold(0), revenue(0.0) { }

	/*一个istream为参数的构造函数,函数体空；
    函数体：从is中读取一条交易信息后存入this对象中；*/
    Sales_item(std::istream &is) { is >> *this; }
public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Sales_item& operator+=(const Sales_item&);
    
    // operations on Sales_item objects
    std::string isbn() const { return bookNo; }//返回一个变量，该变量不可修改
    double avg_price() const;

// private members as before
private:  //隐式初始化
    std::string bookNo;      // implicitly initialized to the empty string

#ifdef IN_CLASS_INITS
    unsigned units_sold = 0; // explicitly initialized 显式初始化
    double revenue = 0.0;
#else
    unsigned units_sold;  
    double revenue;       
#endif
};

// used in chapter 10
inline
bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs) 
{ return lhs.isbn() == rhs.isbn(); }

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool 
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool 
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs) 
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue; 
    return *this;//成员函数都会传入this指针
}

// assumes that both objects refer to the same ISBN
Sales_item 
operator+(const Sales_item& lhs, const Sales_item& rhs) 
{
    Sales_item ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}

std::istream& 
operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else 
        s = Sales_item();  // input failed: reset object to default state
    return in;
}

std::ostream& 
operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold) 
        return revenue/units_sold; 
    else 
        return 0;
}
#endif
