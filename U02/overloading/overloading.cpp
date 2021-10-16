#include <iostream>

int add(int op1, int op2 = 1);
double add(double op1, double op2 = 1.0);

int main()
{

    return 0;
}

int add(int op1, int op2)
{
    return op1 + op2;
}

double add(double op1, double op2)
{
    return op1 + op2;
}