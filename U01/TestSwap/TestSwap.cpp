#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a{ 0 }, b{ 1 };
    std::cout << "before: a=" << a << "\tb=" << b << std::endl;
    swap(a, b);
    std::cout << "after:  a=" << a << "\tb=" << b << std::endl;
    return 0;
}