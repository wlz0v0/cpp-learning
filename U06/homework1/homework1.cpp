#include <iostream>
#include <vector>

class Animal
{
public:
    Animal()
    {
        std::cout << "Animal" << std::endl;
    }
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    Dog()
    {
        std::cout << "Dog" << std::endl;
    }
    virtual void speak()
    {
        std::cout << "wang" << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        std::cout << "Cat" << std::endl;
    }
    virtual void speak()
    {
        std::cout << "miao" << std::endl;
    }
};

int main()
{
    int n = 0;
    std::vector<Animal*> v;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        Dog dog;
        Dog* pdog = &dog;
        v.push_back(pdog);
        Cat cat;
        Cat* pcat = &cat;
        v.push_back(pcat);
    }
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->speak();
    }
    return 0;
}