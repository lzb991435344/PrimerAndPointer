

#include "Version_test.h"

#include <algorithm>
using std::find; 

#include <string>
using std::string; 

#include <list>
using std::list;

#include <forward_list>
using std::forward_list;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::endl;

#ifndef LIST_INIT
#include <iterator>
using std::begin; using std::end;
#endif 

int main() 
{
	// lst has ten elements 0 ... 9 in value
#ifdef LIST_INIT
	list<int> lst = {0,1,2,3,4,5,6,7,8,9};
#else
	int lstarr[] = {0,1,2,3,4,5,6,7,8,9};
	list<int> lst(begin(lstarr), end(lstarr));
#endif

	// print the initial values in lst
	cout << "initial list: ";
	for (auto it : lst)
		cout << it << " ";
	cout << endl;

	// erase the odd elements in lst
	auto it = lst.begin(); 
	while (it != lst.end())
		if (*it % 2)             // if the element is odd
			it = lst.erase(it);  // erase this element
		else
			++it;

	// print the current contents of lst
	cout << "after erasing odd elements from lst: ";
	for (auto it : lst)
		cout << it << " ";
	cout << endl;
	
	
	
	// repeat the same actions but on a forward_list
#ifdef LIST_INIT
	forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
#else
	// lstarr was defined for the initialization of lst above
	forward_list<int> flst(begin(lstarr), end(lstarr));
#endif

	// print the initial values in flst
	cout << "initial list: ";
	for (auto it : flst)
		cout << it << " ";
	cout << endl;

	// erase the odd elements in flst
	auto prev = flst.before_begin(); // element "off the start" of flst
	auto curr = flst.begin();     // denotes the first element in flst
	while (curr != flst.end()) {  // while there are still elements 
		if (*curr % 2)                     // if the element is odd
	    	curr = flst.erase_after(prev); // erase it and move curr 
		else {
			prev = curr; // move the iterators to denote the next
			++curr;      // element and one before the next element
		}
	}

	// print the current contents of lst
	cout << "after erasing elements from flst: ";
	for (auto it : flst)
		cout << it << " ";
	cout << endl;

	return 0;
}
