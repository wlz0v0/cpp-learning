#include "Person.h"
#include <iostream>
#include <cstring>

unsigned int Person::count = 0;

Person::Person() : Person("Ğ¡ÔÂÔÂ")
{}

Person::Person(const std::string& nameStr)
{
	int len = nameStr.size();
	name = new char[len + 1];
	for (int i = 0; i < len; i++)
		name[i] = nameStr[i];
	name[len] = '\0';
	++count;
}

Person::Person(const char* name_)
{
	int len = strlen(name_);
	name = new char[len + 1];
	for (int i = 0; i < len; i++)
		name[i] = name_[i];
	name[len] = '\0';
	++count;
}

Person::Person(const Person& person_)
{
	int len = strlen(person_.name);
	name = new char[len + 1];
	for (int i = 0; i < len; i++)
		name[i] = person_.name[i];
	name[len] = '\0';
	++count;
}

Person::~Person()
{
	delete[] name;
	name = nullptr;
	--count;
}

unsigned int Person::getCount1()
{
	return count;
}

unsigned int Person::getCount2()
{
	return count;
}
