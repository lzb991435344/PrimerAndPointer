#include "Version_test.h"

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::normal_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <cstddef>
using std::size_t;

#include <algorithm>
using std::max_element; 

#include <numeric>
using std::accumulate;

#ifdef LROUND    // Version_test.h defines lround if LROUND is not defined
#include <cmath>
using std::lround;
#endif


/**
 //lround example 
#include <stdio.h>      //printf 
#include <math.h>       // lround 

int main ()
{
  printf ( "lround (2.3) = %ld\n", lround(2.3) );
  printf ( "lround (3.8) = %ld\n", lround(3.8) );
  printf ( "lround (-2.3) = %ld\n", lround(-2.3) );
  printf ( "lround (-3.8) = %ld\n", lround(-3.8) );
  return 0;
}

result:
lround (2.3) = 2
lround (3.8) = 4
lround (-2.3) = -2
lround (-3.8) = -4
*/
int main()
{
	vector<int> vals(32);     // preallocate so each element is 0 
	//无符号整数通用源
	default_random_engine e;  // generates numbers
	uniform_int_distribution<unsigned> u(0,31); // inclusive range 
	for (size_t i = 0; i != 100; ++i)
		++vals[u(e)];         // count how often each number appears
	/**
	1.在头文件 #include <algorithm> 中，返回的是迭代器，所以输出值的话要在前面加 *
    2. 第三个参数cmp可写可不写， max_element() 和 min_element() 默认是从小到大排列，
    然后 max_element() 输出最后一个值， min_element() 输出第一个值。
	*/
	int m = *max_element(vals.begin(), vals.end());
	for (int i = m; i != 0; --i) {
		for (size_t j = 0; j != vals.size(); ++j)
			if (vals[j] > i-1) cout << "* ";
			else               cout << "  ";
		cout << endl;
	}

	vector<int> vals2(32);     // preallocate so each element 0 value
	default_random_engine e2;  // restart the sequence

	normal_distribution<> n(15,5); // mean 15, standard deviation 5
	for (size_t i = 0; i != 100; ++i) {
		size_t v = lround(n(e));
		if (v < vals.size())
			++vals[v];         // count how often each number appears
		else
			cout << "discarding: " << v << " ";
	}
	cout << endl;
    /**
     int sum = accumulate(vec.begin() , vec.end() , 42);
     accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值。
     accumulate函数将它的一个内部变量设置为指定的初始值，然后在此初值上累加输入范围内
     所有元素的值。
    */
	cout << std::accumulate(vals.begin(), vals.end(), 0) << endl;
	m = *max_element(vals.begin(), vals.end());
	for (int i = m; i != 0; --i) {
		for (size_t j = 0; j != vals.size(); ++j)
			if (vals[j] > i - 1) cout << "* ";
			else               cout << "  ";
		cout << endl;
	}

	return 0;
}
