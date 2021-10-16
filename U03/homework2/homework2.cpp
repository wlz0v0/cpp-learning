#include <iostream>

int swap(int& a, int& b, int& c)
{
    int temp = b;
    b = a;
    a = c;
    c = temp;
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main()
{
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    int res = swap(a, b, c);
    std::cout << res << " " << a << " " << b << " " << c;
    return 0;
}