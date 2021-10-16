#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

int main()
{
    std::array<int, 5> arr;
    srand(static_cast<unsigned int>(time(NULL)));
    for (auto& x : arr)
    {
        x = rand();
    }
    return 0;
}