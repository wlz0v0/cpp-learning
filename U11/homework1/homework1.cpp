#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    int temp;
    while (cin.get() != '\n') {
        cin.unget();
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;
    return 0;
}