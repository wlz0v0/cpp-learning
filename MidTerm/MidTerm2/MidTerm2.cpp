#include <iostream>
#include <ctime>

class Fruit
{
public:
    virtual ~Fruit() = default;

    void goToGrocery()
    {
        // do something
    }

    virtual void buyFruit()
    {
        // do something
    }
};

class Apple : public Fruit
{
public:
    virtual void buyFruit()
    {
        // do something
    }
};

int main()
{
    Apple apple;
    Fruit* pFruit = &apple;
    clock_t start = 0, end = 0;
    size_t loopCount = 50000000; // 循环次数
    double resultOfNonVirtual = 0.0, resultOfVirtual = 0.0;

    start = clock();
    for (int i = 0; i < loopCount; ++i)
        pFruit->goToGrocery();
    end = clock();
    resultOfNonVirtual = (static_cast<double>(end) - static_cast<double>(start))
        / CLOCKS_PER_SEC; // 换算结果，CLOCKS_PER_SEC是一秒的时钟数

    start = clock();
    for (int i = 0; i < loopCount; ++i)
        pFruit->buyFruit();
    end = clock();
    resultOfVirtual = (static_cast<double>(end) - static_cast<double>(start))
        / CLOCKS_PER_SEC; // 换算结果，CLOCKS_PER_SEC是一秒的时钟数
    std::cout << resultOfNonVirtual << std::endl;
    std::cout << resultOfVirtual << std::endl;
    return 0;
}