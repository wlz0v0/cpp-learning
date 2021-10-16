#include <iostream>
#include <array>

class Circle
{
private:
    double radius = 1.0;
public:
    Circle() = default;
    Circle(double radius_) : radius(radius_) {}
    double getArea() { return 3.14 * radius * radius; }
};

int main()
{
    std::array<Circle, 10> arr;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        if (i > 4)
            arr[i] = Circle();
        else
            arr[i] = Circle(i + 1);
    }
    for (auto x : arr)
        sum += x.getArea();
    std::cout << sum;
    return 0;
}