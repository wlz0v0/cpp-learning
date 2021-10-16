#include <iostream>

template<typename T, typename S = int>
auto add(T op1, S op2, int count = 1)
{
    return op1 + op2;
}

template<typename T>
T* reverse(T a[], int length)
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        ++i;
        --j;
    }
    return a;
}

template<typename T>
void print(T* a, int length)
{
    for (int i = 0; i < length - 1; ++i)
        std::cout << a[i] << std::endl;
}

template<typename T>
void foo(T arg) {

}

template void foo<double>(double);

int main()
{
    std::cout << add(1, 2.2) << std::endl;
    return 0;
}
