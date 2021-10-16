#include <iostream>

char min(char c1, char c2)
{
    return c1 < c2 ? c1 : c2;
}

char min(char c1, char c2, char c3)
{
    return (c1 < c2) ? (c1 < c3 ? c1 : c3) : (c2 < c3 ? c2 : c3);
}

int min(int i1, int i2)
{
    return i1 < i2 ? i1 : i2;
}

int min(int i1, int i2, int i3)
{
    return (i1 < i2) ? (i1 < i3 ? i1 : i3) : (i2 < i3 ? i2 : i3);
}

int main()
{
    char chres1 = min('[', 'N'), chres2 = min('G', '9', '*');
    int ires1 = min(-42, 0), ires2 = min(42, 0, std::numeric_limits<int>::min());
    std::cout << chres1 << " " << chres2 << " "
        << ires1 << " " << ires2;
    return 0;
}