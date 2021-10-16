#include <iostream>

namespace NS1
{
	int x = 1;
}

namespace NS2
{
	int x = 2;
}

int main(void)
{
	std::cout << NS1::x << "\n" << NS2::x;
	return 0;
}