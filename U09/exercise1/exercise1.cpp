#include <iostream>
#include <exception>
#include <stdexcept>
#include <limits>
#include <new>

class MyBadAlloc : public std::bad_alloc
{
public:
    MyBadAlloc() = default;
    MyBadAlloc(const std::string& str):
        bad_alloc(),
        info(str)
    {}
    virtual const char* what() const noexcept
    {
        return info.c_str();
    }
private:
    std::string info;
};

void f()
{
    try
    {
        for (int i = 0; i < std::numeric_limits<int>::max(); ++i)
        {
            throw MyBadAlloc("123");
        }
    }
    catch (std::bad_alloc&)
    {
        throw MyBadAlloc();
    }
    throw 42;
}

int main()
{
    try
    {
        throw MyBadAlloc("123");
    }
    catch (const MyBadAlloc& e)
    {
        std::cout << e.what();
    }
    catch (int e)
    {
        std::cout << e;
    }
    return 0;
}