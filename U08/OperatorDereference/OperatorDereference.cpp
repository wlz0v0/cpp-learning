#include <iostream>

class A
{
private:
    int a = 1;
    int b = 2;
public:
    int operator*()
    {
        return a;
    }

    A* operator->()
    {
        return this;
    }

    int getB()
    {
        return b;
    }
};

int main()
{
    A a;
    A* pa = &a;
    std::cout << pa->getB() << std::endl;
}