#include <iostream>

int main()
{
    int* ptr = new int(66);
    int* arr = new int[5];
    for (int i = 0; i < 5; i++)
        arr[i] = *ptr;
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;
    delete ptr;
    delete[] arr;

    return 0;
}