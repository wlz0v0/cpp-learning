#include <iostream>
#include <fstream>
#include <filesystem>
#include <iomanip>
constexpr double pi = 3.1415926;
std::ostream& output(std::ostream& os, int i)
{
    os << std::setprecision(i)
        << std::setfill('*')
        << std::setw(static_cast<std::streamsize>(i) + 4L)
        << pi << std::endl;
    return os;
}

int main()
{
    namespace fs = std::filesystem;
    fs::path outPath("E:\\out.txt");
    fs::path inPath("E:\\in.txt");
    std::ofstream ofs(outPath);
    for (int i = 1; i <= 5; ++i)
    {
        output(std::cout, i);
        output(ofs, i);
    }
    return 0;
}