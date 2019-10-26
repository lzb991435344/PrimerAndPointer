

#include <iterator>
using std::begin; 
using std::end;

#include <cstddef>
using std::size_t; 

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	int ia[] = {0,1,2,3,4,5,6,7,8,9};

	//指针变量指向字符数组的第一个元素
	int *p = ia; // p points to the first element in ia
	
	//指向ia[1]
	++p;           // p points to ia[1]

	int *e = &ia[10]; // pointer just past the last element in ia
	for (int *b = ia; b != e; ++b)
		cout << *b << " "; // print the elements in ia
	cout << endl;

	const size_t sz = 10;
	int arr[sz];  // array of 10 ints

	//输入数组元素
	for (auto &n : arr) // for each element in arr
		cin >> n;  // read values from the standard input

	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	// pbeg points to the first and 
	// pend points just past the last element in arr
	int *pbeg = begin(arr),  *pend = end(arr);

	// find the first negative element, 
	// stopping if we've seen all the elements
	while (pbeg != pend && *pbeg >= 0)
		++pbeg;
	
	//
	if (pbeg == pend)
		cout << "no negative elements in arr" << endl;
	else
		cout << "first negative number was " << *pbeg << endl;
	return 0;
}

