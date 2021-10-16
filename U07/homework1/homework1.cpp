#include <iostream>
#include <fstream>
#include <filesystem>

int main()
{
    std::filesystem::path op("out.txt");
    std::filesystem::path ip("in.txt");
    std::ofstream ofs(op);
    std::ifstream ifs;
    ifs.open(ip);
    if (std::filesystem::exists(ip))
        std::cout << "in.txt exists";
    else
        std::cout << "in.txt does not exist";
    ofs.close();
    ifs.close();
    return 0;
}