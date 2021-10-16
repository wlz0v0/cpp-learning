#include <iostream>
#include <string>
#include <stdexcept>

class MyComplex
{
public:
	double real;
	double imaginary;
	bool isNegativeZero;

	MyComplex() :
		real(0.0),
		imaginary(0.0),
		isNegativeZero(false)
	{}
	MyComplex(double real_, double imaginary_) :
		real(real_),
		imaginary(imaginary_),
		isNegativeZero(false)
	{}
	MyComplex operator+(const MyComplex& rhs)
	{
		double retReal = real + rhs.real;
		double retImaginary = imaginary + rhs.imaginary;
		return MyComplex(retReal, retImaginary);
	}
	MyComplex operator-(const MyComplex& rhs)
	{
		double retReal = real - rhs.real;
		double retImaginary = imaginary - rhs.imaginary;
		return MyComplex(retReal, retImaginary);
	}
	MyComplex operator*(const MyComplex& rhs)
	{
		double retReal = real * rhs.real - imaginary * rhs.imaginary;
		double retImaginary = imaginary * rhs.real + real * rhs.imaginary;
		return MyComplex(retReal, retImaginary);
	}
	MyComplex operator/(const MyComplex& rhs)
	{
		if (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary == 0)
		{
			throw std::runtime_error("Divisor is 0");
		}
		double retReal = (real * rhs.real + imaginary * rhs.imaginary) /
			(rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
		double retImaginary = (imaginary * rhs.real - real * rhs.imaginary) /
			(rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
		return MyComplex(retReal, retImaginary);
	}
	friend std::istream& operator>>(std::istream& is, MyComplex& c)
	{
		std::string imgStr;
		is >> c.real >> imgStr;
		c.imaginary = std::stod(imgStr);
		if (imgStr == "-0")
			c.isNegativeZero = true;
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, MyComplex& c)
	{
		if (c.isNegativeZero)
			os << "(" << c.real << c.imaginary << "i)";
		else if (c.imaginary >= 0)
			os << "(" << c.real << "+" << c.imaginary << "i)";
		else if (c.imaginary < 0)
			os << "(" << c.real << c.imaginary << "i)";
		return os;
	}
	friend std::ostream& operator<<(std::ostream& os, MyComplex&& c)
	{
		if (c.isNegativeZero)
			os << "(" << c.real << c.imaginary << "i)";
		else if (c.imaginary >= 0)
			os << "(" << c.real << "+" << c.imaginary << "i)";
		else if (c.imaginary < 0)
			os << "(" << c.real << c.imaginary << "i)";
		return os;
	}
};

int main() {
	MyComplex z1, z2;
	std::cin >> z1;
	std::cin >> z2;
	try {
		std::cout << "z1 + z2 = " << z1 + z2 << std::endl;
		std::cout << "z1 - z2 + z1 = " << z1 - z2 + z1 << std::endl;
		std::cout << "z1 * z2 - z1 = " << z1 * z2 - z1 << std::endl;
		if (z2.real != 0 && z2.imaginary != 0)
			std::cout << "z1 / z2 + z1 = ";

		std::cout << z1 / z2 + z1 << std::endl;
		if (z1.real != 0 && z1.imaginary != 0)
			std::cout << "z2 - z1 / z1 = ";  // 本语句不可与下一句放在一起
			// 否则异常时的输出信息依赖于系统库实现
		std::cout << z2 - z1 / z1 << std::endl;
		std::cout << "Finished";
	}
	catch (std::exception& e) {  // catch父类异常类型，也可以捕获子类异常
		std::cout << e.what()
			<< std::endl;  // what()函数将存放在异常对象中的信息取出来
		std::cout << "Unexpected Error";
	}
	return 0;
}