#include <iostream>

void swap(int a[], int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int b = 6;
    std::cout << "before swap, a[0] = " << arr[0]
        << ", b = " << b << std::endl;
    swap(arr, &b);
    std::cout << "after swap, a[0] = " << arr[0]
        << ", b = " << b << std::endl;
    return 0;
}