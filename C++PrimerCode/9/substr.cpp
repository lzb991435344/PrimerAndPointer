
#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <stdexcept>
//范围溢出
using std::out_of_range;

int main()
{
	//字符串截取
	try {
		string s("hello world");
		cout << s.substr(0, 5) << endl;  // prints hello
		cout << s.substr(6) << endl;     // prints world
		cout << s.substr(6, 11) << endl; // prints world
		cout << s.substr(12) << endl;    // throws out_of_range 
	} catch(out_of_range) {cout << "caught out_of_range" << endl; }

	return 0;
}
