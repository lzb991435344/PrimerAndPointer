

#include <cstddef>
using std::size_t;

#include <deque>
using std::deque;

#include <stack>
using std::stack; 

#include <iostream>
using std::cout; using std::cerr; using std::endl;

bool process(int);

int main()
{
	//栈的使用
	stack<int> intStack;  // empty stack

	// fill up the stack
	for (size_t ix = 0; ix != 10; ++ix)
    	intStack.push(ix);   // intStack holds 0 . . . 9 inclusive

	// while there are still values in intStack
	while (!intStack.empty()) {
		//取栈顶
    	int value = intStack.top();
    	// code that uses value
		cout << value << endl;
    	intStack.pop(); // pop the top element, and repeat
	}

	return 0;
}
