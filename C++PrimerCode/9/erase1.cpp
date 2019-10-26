#include <algorithm>
using std::find; 

#include <string>
using std::string; 

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	list<string> slist;
	string s;
	while (cin >> s)
		slist.push_back(s);  // read the contents into slist

	/* we'll explain find in chapter 10
	 * find looks in the sequence denoted by its first two
	 * iterator arguments for the value of its third argument
	 * returns an iterator to the first element with that value
	 * if that element exists in the input sequence
	 * otherwise returns the end iterator
	*/
	auto iter = find(slist.begin(), slist.end(), "Quasimodo");
	if (iter != slist.end())
	     slist.erase(iter);
	
	auto orig = slist; // keep a copy before we destroy the contents
	slist.clear();     // delete all the elements within the container
	cout << "after clear, size is: " << slist.size() << endl;
	
	slist = orig; // restore the data
	slist.erase(slist.begin(), slist.end()); // equivalent
	cout << "after erase begin to end, size is: " << slist.size() << endl;
	
	slist = orig; // restore the data
	auto elem1 = slist.begin(), elem2 = slist.end();
	// delete the range of elements between two iterators
	// returns an iterator to the element just after the last removed element
	elem1 = slist.erase(elem1, elem2); // after the call elem1 == elem2
	cout << "after erase elem1 to elem2 size is: " << slist.size() << endl;
	
	if (elem1 != elem2)
		cout << "somethings wrong" << endl;
	else
		cout << "okay, they're equal " << endl;
	
}
