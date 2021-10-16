#include <iostream>
#include "MyComplex.h"

int main()
{
	MyComplex c1(0, 0);
	MyComplex c2(1.1, 1.1);
	MyComplex c3(2.2, 2.2);
	std::cout << c1[2] << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c3 << std::endl;
	
	return 0;
}