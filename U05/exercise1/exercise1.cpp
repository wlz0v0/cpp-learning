#include <iostream>
#include "Person.h"

int main()
{
    Person p1;
    Person p2("肖皓月");
    Person p3("yyds仌方瀚辉");
    Person p4(p3);
    std::cout << Person::getCount1() << std::endl;
    std::cout << p3.getCount2() << std::endl;
    return 0;
}