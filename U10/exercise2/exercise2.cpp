#include <iostream>

template<typename T = int>
class Array
{
public:
    Array(T* a, size_t len): a_(a), len_(len)
    {}

    T sum()
    {
        int ret = 0;
        for (int i = 0; i < len_; ++i)
        {
            ret += a_[i];
        }
        return ret;
    }

    T* reverse()
    {
        int i = 0, j = len_ - 1;
        while (i < j)
        {
            T temp = a_[i];
            a_[i] = a_[j];
            a_[j] = temp;
            ++i;
            --j;
        }
        return a_;
    }

    int seek(T key)
    {
        for (int i = 0; i < len_; ++i)
        {
            if (key == a_[i])
            {
                return i;
            }
        }
        return -1;
    }

    void print()
    {
        for (int i = 0; i < len_; ++i)
        {
            std::cout << a_[i] << std::endl;
        }
    }

private:
    T* a_;
    size_t len_;
};

template class Array<int>;

int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Array<int> arr(a, 10);
    std::cout << arr.sum();
    arr.print();
    arr.reverse();
    arr.print();
    return 0;
}