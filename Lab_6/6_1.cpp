// Factorial for given number using tail recursion

#include <iostream>
using namespace std;

int fact(int n, int factorial = 1)
{
    if (n == 0)
    {
        return factorial;
    }
    else
    {
        return fact(n - 1, n * factorial);
    }
}

int main()
{
    cout << "Factorial of 7 is " << fact(7);
    return 0;
}