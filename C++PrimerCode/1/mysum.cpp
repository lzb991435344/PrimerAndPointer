
#include <iostream> 

int main() 
{
	int sum = 0, value = 0;

	// read until end-of-file, calculating a running total of all values read
	//输入值，直到到达结束输入，计算总和
	while (std::cin >> value) 
		sum += value; // equivalent to sum = sum + value

	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
