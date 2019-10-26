
//预处理变量无视作用域规则
#ifndef SALES_DATA_H   //保证唯一性，大写
#define SALES_DATA_H  //将名字定义为预处理变量

#include "Version_test.h"

#include <string>

struct Sales_data {
	std::string bookNo;
//默认初始值	
#ifdef IN_CLASS_INITS  
	unsigned units_sold = 0;
	double revenue = 0.0;
//没有初始值	
#else 	
	unsigned units_sold;  
	double revenue;
#endif
};
#endif
