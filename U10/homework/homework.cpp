#include <iostream> 
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
template<typename T>
class Array
{
public:
    Array(vector<T> v) {
        size_ = v.size();
        data_ = static_cast<T*> (new T[size_]);
        for (int i = 0; i < size_; i++) {
            data_[i] = v[i];
        }
    }
    ~Array() {
        delete[] data_;
    }
    void sort() {
        int i, j;
        T key;
        for (j = 1; j < size_; j++)
        {
            key = data_[j];
            i = j - 1;
            while (i >= 0 && data_[i] > key)
            {
                data_[i + 1] = data_[i--];
            }
            data_[i + 1] = key;
        }
    }
    int seek(T key) {
        for (int i = 0; i < size_; ++i)
        {
            if (key == data_[i])
                return i;
        }
        return -1;
    }
    void display() {
        int i;
        for (i = 0; i < size_; i++) {
            cout << data_[i];
            if (i != size_ - 1)
                cout << " ";  // 输出一个空格
        }
    }
private:
    T* data_;
    size_t size_;
};
int main() {
    vector<int> vi;
    int ti;
    vector<double> vd;
    double td;
    vector<char> vc;
    char tc;

    while (cin.get() != '\n') {
        cin.unget();
        cin >> ti;
        vi.push_back(ti);
    }

    while (cin.get() != '\n') {
        cin.unget();
        cin >> td;
        vd.push_back(td);
    }

    while (cin >> tc) {
        vc.push_back(tc);
    }

    Array<int> ai(vi);
    Array<double> ad(vd);
    Array<char> ac(vc);

    cout << ai.seek(10) << endl;
    cout << ad.seek(10.0) << endl;
    cout << ac.seek('a') << endl;

    ai.sort();
    ad.sort();
    ac.sort();

    ai.display();
    cout << endl;
    ad.display();
    cout << endl;
    ac.display();
    return 0;
}