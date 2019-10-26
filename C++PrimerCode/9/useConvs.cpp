#include <string>
using std::string;
using std::to_string; using std::stod;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	//字符和整型的转换
	int i = 42;
	// converts the int i to its character representation
	string s = to_string(i);  

	double d = stod(s);   // converts the string s to floating-point
	cout << "i = " << i << " s = " << s << " d is: " << d << endl;

	// convert the first substring in s that starts with a digit,  d = 3.14
	string s2 = "pi = 3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));

	cout << "d = " << d << " s = " << s << " s2 is: " << s2 << endl;

	return 0;
}
