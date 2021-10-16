#include <iostream>
#include <map>
#include <utility>
#include <string>

using pis = std::pair<int, std::string>;

int main()
{
    std::map<int, std::string> studentInfo;
    studentInfo.insert(pis(1, "小明"));
    studentInfo.insert(pis(2, "小红"));
    studentInfo.insert(pis(3, "小刚"));
    studentInfo.insert(pis(4, "小丽"));
    studentInfo.insert(pis(5, "小王"));
    std::cout << "请输入学生号" << std::endl;
    int id = 0;
    std::cin >> id;
    auto it = studentInfo.find(id);
    if (it != studentInfo.end())
        std::cout << it->second << std::endl;
    else
        std::cout << "查无此人！" << std::endl;
    return 0;
}