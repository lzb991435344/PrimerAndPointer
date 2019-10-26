
#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

int main() 
{
	//字符串的查找
    string name("AnnaBelle");
    auto pos1 = name.find("Anna"); // pos1 == 0
    cout << pos1 ;
    string lowercase("annabelle");
    pos1 = lowercase.find("Anna");   // pos1 == npos
    cout << " " << pos1 << endl;
    return 0;
}
