#include "MyString.h"
#include <cstring>

MyString::MyString() : len(0), string(nullptr) {}

MyString::MyString(const char* string_)
{
    if (string_ == nullptr)
        len = 1;
    else
        len = strlen(string_);
    string = new char[len + 1];
    if (string_ != nullptr)
        for (size_t i = 0; i < len; i++)
            string[i] = string_[i];
    string[len] = '\0';
}

MyString::MyString(const MyString& string_) : len(string_.len)
{
    string = new char[len + 1];
    for (size_t i = 0; i < len; i++)
        string[i] = string_.string[i];
    string[len] = '\0';
}

MyString::~MyString()
{
    delete[] string;
    string = nullptr;
}

char* MyString::getString()
{
    return string;
}

size_t MyString::getLen()
{
    return len;
}

void MyString::setString(const MyString& string_)
{
    *this = (string_);
}
