#pragma once
class MyString
{
private:
    size_t len;
    char* string;
public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();
    char* getString();
    size_t getLen();
    void setString(const MyString&);
};