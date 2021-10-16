#include <iostream>
#include "MyString.h"

int main()
{
    MyString s2("Hello, world!");

    std::cout << s2.getString() << std::endl;
    return 0;
}