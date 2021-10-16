#include "MyComplex.h"
#include <stdexcept>
#include <sstream>

MyComplex::MyComplex() :
	real(0.0),
	imaginary(0.0)
{}

MyComplex::MyComplex(double real_, double imaginary_) :
	real(real_),
	imaginary(imaginary_)
{}

MyComplex MyComplex::operator+(const MyComplex& rhs)
{
	double retReal = real + rhs.real;
	double retImaginary = imaginary + rhs.imaginary;
	return MyComplex(retReal, retImaginary);
}

MyComplex& MyComplex::operator+=(const MyComplex& rhs)
{
	*this = *this + rhs;
	return *this;
}

double& MyComplex::operator[](size_t index)
{
	if (index == 0)
		return real;
	else if (index == 1)
		return imaginary;
	else
		throw std::out_of_range("∑√Œ ‘ΩΩÁ");
}

MyComplex& MyComplex::operator++()
{
	++real;
	++imaginary;
	return *this;
}

MyComplex MyComplex::operator++(int)
{
	MyComplex old = *this;
	operator++();
	return old;
}

std::string MyComplex::toString()
{
#if TO_STRING_SSTREAM
	std::stringstream ssm;
	if (imaginary == 0.0)
		ssm << real;
	else if (real == 0.0)
		ssm << imaginary << "i";
	else if (imaginary > 0.0)
		ssm << real << "+" << imaginary << "i";
	else if (imaginary < 0.0)
		ssm << real << imaginary << "i";
	return ssm.str();
#else
	std::string realStr = std::to_string(real);
	std::string imaginaryStr = std::to_string(imaginary);
	if (imaginary == 0.0)
		return realStr;
	else if (real == 0.0)
		return imaginaryStr + "i";
	else if (imaginary > 0.0)
		return realStr + "+" + imaginaryStr + "i";
	else if (imaginary < 0.0)
		return realStr + imaginaryStr + "i";
	return "bug";
#endif
}

std::ostream& operator<<(std::ostream& os, MyComplex& c)
{
	os << c.toString();
	return os;
}
