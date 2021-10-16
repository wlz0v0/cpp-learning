#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;
class MyShape {
protected:
    int R_, G_, B_;
    string colorToString() {
        stringstream ss;
        ss << R_ << " " << G_ << " " << B_;
        return ss.str();
    }
public:
    void setColor(int R, int G, int B) {
        R_ = R; G_ = G, B_ = B;
    }
    int getR() {
        return R_;
    }
    int getG() {
        return G_;
    }
    int getB() {
        return B_;
    }
    virtual void Draw() = 0;
    MyShape() {
        R_ = 255; G_ = 255, B_ = 255;
    }
};
class MyCircle : public MyShape {
private:
    int x_ = 200, y_ = 200, radius_ = 200, minInt = numeric_limits<int>::min();
public:
    MyCircle(int x, int y, int radius) {
        x_ = x;
        y_ = y;
        radius_ = radius;
    }
    MyCircle() = default;
    MyCircle(MyCircle& aCircle) {
        x_ = aCircle.x_;
        y_ = aCircle.y_;
        radius_ = aCircle.radius_;
        R_ = aCircle.getR();
        G_ = aCircle.getG();
        B_ = aCircle.getB();
    }
    void setCenter(int x, int y) {
        x_ = x;
        y_ = y;
    }
    void setRadius(int radius) {
        radius_ = radius;
    }
    void Draw() {
    }
    int& operator[](size_t pos)
    {
        if (pos == 0)
            return x_;
        else if (pos == 1)
            return y_;
        else if (pos == 2)
            return radius_;
        else
            return minInt;
    }
};

int main() {
    int x, y, r = 0;
    cin >> x >> y >> r;
    MyCircle c1(x, y, r);
    MyCircle c2;
    c2[2] = x;
    for (int i = 0; i <= 3; i++) {
        cout << c1[i] << endl;
        cout << c2[i - 1] << endl;
    }
    return 0;
}