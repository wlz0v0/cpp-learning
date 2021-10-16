#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using ios = std::ios;

class Person
{
public:
    double height;
    double weight;
    Person() = default;
    Person(double height_, double weight_):
        height(height_), 
        weight(weight_)
    {}
};

int main()
{
    //写
    std::fstream fs("inout.dat", ios::binary | ios::out);
    int x = 66;
    double y = 6.6;
    int a[3] = { 0, 1, 2 };
    Person p(1.8, 65.5);
    fs.write(reinterpret_cast<char*>(&x), sizeof(x));
    fs.write(reinterpret_cast<char*>(&y), sizeof(y));
    fs.write(reinterpret_cast<char*>(a), sizeof(a));
    fs.write(reinterpret_cast<char*>(&p), sizeof(p));
    fs.close();

    //读
    fs.open("inout.dat", ios::binary | ios::in);
    int iTemp = 0;
    double dTemp = 0.0;
    int aTemp[3] = { -1, -1, -1 };
    Person pTemp;
    if(fs.read(reinterpret_cast<char*>(&iTemp), sizeof(iTemp)))
        std::cout << iTemp << std::endl;
    if(fs.read(reinterpret_cast<char*>(&dTemp), sizeof(dTemp)))
        std::cout << dTemp << std::endl;
    if (fs.read(reinterpret_cast<char*>(aTemp), sizeof(aTemp)))
        for (int i = 0; i < 3; ++i)
            std::cout << aTemp[i] << std::endl;
    if (fs.read(reinterpret_cast<char*>(&pTemp), sizeof(pTemp)))
        std::cout << pTemp.height << " " << pTemp.weight << std::endl;
    fs.close();

    return 0;
}