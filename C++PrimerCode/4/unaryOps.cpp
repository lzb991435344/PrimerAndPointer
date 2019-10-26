

#include <iostream>
using std::cout; using std::endl;

//基本类型
int main()
{
	int i = 1024;
	int k = -i; // i is -1024
	
	bool b = true;
	bool b2 = -b; // b2 is true!
	
	cout << b << " " << b2 << " " << endl;
	
	return 0;
}
