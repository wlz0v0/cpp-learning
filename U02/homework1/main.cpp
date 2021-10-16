#include <iostream>
#include <string>

int main(void)
{
	int n;
	std::cin >> n;
	try
	{
		if (n > 9 || n < 1)
		{
			throw std::string("nÓ¦µ±ÊôÓÚ1~9£¡");
		}
		for (int i = 1; i <= n; i++)
		{
			std::cout << i;
		}
	}
	catch (std::string errStr)
	{
		std::cerr << errStr << std::endl;
	}
	return 0;
}