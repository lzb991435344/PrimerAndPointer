// demo01.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <cstring>
#include <cstddef>
using std::size_t;
//string 基本接口的使用
int main() {
		string s1 = "A string example";
		string s2 = "A different string";

		if (s1 < s2)  // false: s2 is less than s1 ,s1 > s2
			cout << s1 << endl;
		else
			cout << s2 << endl;

		//常量符数组
		const char ca1[] = "A string example";
		const char ca2[] = "A different string";

		if (strcmp(ca1, ca2) < 0) // same effect as string comparison s1 < s2
			cout << ca1 << endl;
		else
			cout << ca2 << endl;

		const char *cp1 = ca1, *cp2 = ca2;
		cout << strcmp(cp1, cp2) << endl; // output is positive
		cout << strcmp(cp2, cp1) << endl; // output is negative
		cout << strcmp(cp1, cp1) << endl; // output is zero

										  //16
		cout << strlen(cp1) << endl; // prints 16; strlen ignores the null

		const unsigned sz = 16 + 18 + 2;
		char largeStr[sz];      // will hold the result
		cout << strlen(largeStr) << endl;
		cout << sizeof(largeStr) << endl;
								// disastrous if we miscalculated the size of largeStr
		strcpy_s(largeStr, ca1);  // copies ca1 into largeStr
		strcat_s(largeStr, " ");  // adds a space at the end of largeStr
		strcat_s(largeStr, ca2);  // concatenates ca2 onto largeStr
								// prints A string example A different string
		cout << largeStr << endl;
		cout << strlen(largeStr) << endl;
		cout << sizeof(largeStr) << endl;

		strncpy_s(largeStr, ca1, sz); // size to copy includes the null
		if (strlen(ca1) > sz)
			largeStr[sz - 1] = '\0';
		cout << strlen(largeStr) << endl;
		cout << sizeof(largeStr) << endl;
		strncat_s(largeStr, " ", 2);  // pedantic, but a good habit
		strncat_s(largeStr, ca2, sz - strlen(largeStr));
		cout << largeStr << endl;

		// initialize large_string as a concatenation of s1, a space, and s2
		string large_string = s1 + " " + s2;
		cout << large_string << endl;
	getchar();
	system("pause");
	return 0;
}

