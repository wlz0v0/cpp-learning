#pragma once
#include <string>
#include <iostream>
#define TO_STRING_SSTREAM 1

class MyComplex
{
private:
	double real;
	double imaginary;

public:
	MyComplex();
	MyComplex(double real_, double imaginary_);

	MyComplex operator+(const MyComplex& rhs);
	MyComplex& operator+=(const MyComplex& rhs);
	double& operator[](size_t index);
	MyComplex& operator++();
	MyComplex operator++(int);
	friend std::ostream& operator<<(std::ostream& os, MyComplex& c);

	std::string toString();
};