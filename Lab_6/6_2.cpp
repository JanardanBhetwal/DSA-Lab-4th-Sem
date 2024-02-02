// Fibonacci number using tail recursion

#include <iostream>
using namespace std;

int Fibonacci(int n, int first = 0, int second = 1)
{
    if (n == 0)
    {
        return first;
    }
    else
    {
        return Fibonacci(n - 1, second, first + second);
    }
}

int main()
{
    for (int i = 1; i < 9; i++)
    {
        cout << Fibonacci(i) << " ";
    }
    return 0;
}