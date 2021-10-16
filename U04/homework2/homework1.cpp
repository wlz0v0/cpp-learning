#include <iostream>
#include <string>

class Parse
{
private:
    int first;
    int last;
public:
    Parse(const std::string& str)
    {
        size_t begin = 0, end = str.size() - 1;
        while (str[begin] < '0' || str[begin] >= '9')
            begin++;
        while (str[end] <= '0' || str[end] >= '9')
            end--;
        auto pos = str.find('-');
        first = std::stoi(str.substr(begin, pos - begin));
        last = std::stoi(str.substr(pos + 1, end - pos));
    }

    int getFirst() { return first; }
    int getLast() { return last; }
};

int main()
{
    std::string s{};
    std::cin >> s;  // 用户输入一个范围字符串
    Parse p(s);     // 构造Parse对象p，同时解析字符串 s
    std::cout << p.getFirst() << ' ' << p.getLast(); // 中间是两个单引号括起来的一个空格字符
    return 0;
}