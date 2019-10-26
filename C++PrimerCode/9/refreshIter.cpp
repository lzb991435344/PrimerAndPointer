
#include "Version_test.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

#ifndef LIST_INIT
#include <iterator>
using std::begin; using std::end;
#endif

//打印vector的元素
void printVec(const vector<int> &vi)
{
	// print the vector's elements
	auto iter = vi.begin();
	while (iter != vi.end())
		cout << *iter++ << endl;
}

int main()
{
	// silly loop to remove even-valued elements 
	// and insert a duplicate of odd-valued elements
#ifdef LIST_INIT
	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
#else
	int temp[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vi(begin(temp), end(temp));
#endif
	printVec(vi);

	// we call begin, not cbegin because we're changing vi
	auto iter = vi.begin(); 
	while (iter != vi.end()) {
		//打印偶数
		if (*iter % 2) {    // if the element is odd
			iter = vi.insert(iter, *iter);  // duplicate  it
			iter += 2; // advance past this element and the new one 
		} else  //删除基数
			iter = vi.erase(iter);          // remove even elements
			// don't advance the iterator; 
			// iter denotes the element after the one we erased
	}
	printVec(vi);

	return 0;
}
	
