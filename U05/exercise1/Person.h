#pragma once
#include <string>
class Person
{
private:
    static unsigned int count;
    char* name;

public:
    Person();
    Person(const std::string& name_);
    Person(const char* name_);
    Person(const Person& person_);
    ~Person();
    static unsigned int getCount1();
    unsigned int getCount2();
};