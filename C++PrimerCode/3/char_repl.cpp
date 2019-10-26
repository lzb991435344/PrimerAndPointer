// demo01.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	//直接赋值和拷贝赋值
	string str("some string"), orig = str;
	if (!str.empty())          // make sure there's a character to print
		cout <<1<<" "<< str[0] << endl;// print the first character in str

							   //首字母大写	
	if (!str.empty())       // make sure there's a character in str[0]
							//重新分配一个新值
							// assign a new value to the first character in str
		str[0] = toupper(str[0]);
	cout << 2 << " " << str << endl;

	//重置字符串为初始状态
	str = orig; // restore str to its original value

				// equivalent code using iterators instead of subscripts
	if (str.begin() != str.end()) { // make sure str is not empty
		auto it = str.begin();  // it denotes the first character in str
		*it = toupper(*it);     // make that character uppercase
	}
	cout << 3 << " " << str << endl;

	str = orig; // restore str to its original value

				// four wasy to capitalize first word in str:
				// 1. for loop with subscripts
	for (decltype(str.size()) index = 0;
		index != str.size() && !isspace(str[index]); ++index)
		str[index] = toupper(str[index]); // capitalize the current character
	cout << 4 << " " << str << endl;

	str = orig; // restore str to its original value

				// 2. for loop with iterators instead of subscripts
	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it); // capitalize the current character
	cout << 5 << " " << str << endl;

	str = orig; // restore str to its original value

				// 3. while instead of a for with subscripts
	decltype(str.size()) index = 0; // subscript to look at characters in str
	while (index != str.size() && !isspace(str[index])) {
		str[index] = toupper(str[index]);  // capitalize the current character
		++index;        // advance the index to get the next character
	}
	cout << 6 << " " << str << endl;

	// 4. while loop with iterators
	auto beg = str.begin();
	while (beg != str.end() && !isspace(*beg)) {
		*beg = toupper(*beg);
		++beg;
	}
	cout << 7 << " " << str << endl;

	str = orig; // restore str to its original value

				// range for loop to process every character
				// first a loop to print the characters in str one character to a line
	for (auto c : str)      // for every char in str
		cout << c << endl;  // print the current character followed by a newline

							// next change every character in str
	//使用引用改变字符串的内容
	for (auto &c : str)  // note: c is a reference 
		c = '*';         // assign a new value to the underlying char in str
	cout << 8 << " " << str << endl;

	str = orig;  // restore str to its original value

				 // equivalent code using traditional for loops
				 // first print the characters in str
	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
		cout << str[ix] << endl;  // print current character followd by a newline

								  // next change every character in str
	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
		str[ix] = '*';  // assigns a new value to the character in str
	cout << 9 << " " << str << endl;

	str = orig;  // restore str to its original value

				 // equivalent code using traditional for loops and iterators
				 // first print the characters in str
	for (auto beg = str.begin(); beg != str.end(); ++beg)
		cout << 10 << " " << *beg << endl;  // print current character followd by a newline

							   // next change every character in str
	for (auto beg = str.begin(); beg != str.end(); ++beg)
		*beg = '*';  // assigns a new value to the character in str
	cout << 11 << " " << str << endl;

	getchar();
	system("pause");
	return 0;
}

