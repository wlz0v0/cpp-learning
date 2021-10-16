#include <iostream>
#include <regex>
#include <string>

class Parse
{
private:
    int first;
    int last;
public:
    Parse(const std::string& str)
    {
        std::regex p("\\D*(\\d+)-(\\d+)\\D*");
        std::smatch res;
        std::regex_match(str, res, p);
        first = std::stoi(res[1]);
        last = std::stoi(res[2]);
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
//垃圾oj regex过不了