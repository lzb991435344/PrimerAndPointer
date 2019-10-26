
#include "Version_test.h"  

#include "Sales_item.h"
#include <iostream>
#include <string>

int main() {

	int v1(1024);    // direct-initialization, functional form
#ifdef LIST_INIT
	int v2{1024};    // direct-initialization, list initializer form
#else
	int v2(1024);    // use parens if list-initialization not yet supported
#endif
	int v3 = 1024;   // copy-initialization
#ifdef LIST_INIT
	int v4 = {1024}; // copy-initialization, list initializer form
#else
    int v4 = 1024;
#endif

	// alternative ways to initialize string from a character string literal
	std::string titleA = "C++ Primer, 5th Ed.";
	std::string titleB("C++ Primer, 5th Ed.");
	std::string all_nines(10, '9');  // all_nines = "9999999999"

	return 0;
}
