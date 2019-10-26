

#include <string> 
using std::string; using std::getline;

#include <iostream> 
using std::cin; using std::cout; using std::endl;

int main() 
{
	string line;

	// read input a line at a time until end-of-file
	//一行一行读取字符串，直到文件尾
	while (getline(cin, line))
		cout << line << endl;

	return 0;
}
