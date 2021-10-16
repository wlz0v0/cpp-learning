#include <iostream>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>

void print(std::deque<int>& de)
{
	for (auto it = de.begin(); it != de.end(); ++it)
	{
		std::cout << *it << " ";
	}
    std::cout << std::endl;
    
}

void print(std::vector<int>& v)
{
    for (auto x : v)
    {
        std::cout << x << " ";

    }
    std::cout << std::endl;
}

int main()
{
    std::deque<int> de;
    for (int i = 9; i >= 0; --i)
    {
        if (i % 2 != 0)
            de.push_front(i);
        else
            de.push_back(i);
    }
    /*print(de);*/
    std::set<int> s;
    for (auto x : de)
    {
        s.insert(x);
    }
    for (int i = 0; i < 20; ++i)
    {
        if (i % 2 == 1)
            s.insert(i);
    }
    /*std::cout << s.size() << std::endl;
    for (auto x : s)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;*/
    std::vector<int> v1;
    for (auto x : s)
    {
        v1.push_back(x);
    }
    std::vector<int> v2 = v1;
    std::reverse(v2.begin(), v2.end());
    v2.push_back(5);
    v1.pop_back();
    print(v1);
    print(v2);
    std::cout << (v1 == v2) << std::endl;
   
    return 0;
}
