#include <iostream>

class C {
public:
	C() :C(42) {
		std::cout << "C()" << std::endl;
	}

	C(int x) {
		this->x = x;
		std::cout << "C(" << x << ")" << std::endl;
	}

private:
	int x = 0;
};

int main() {
	C c;
	C c1(void);
	C c2(18);
	return 0;
}