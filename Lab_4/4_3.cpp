// Represent polynomial equation using Linked list to perform addition of two polynomials.

#include <iostream>
using namespace std;
int main()
{
    int index, coeff;
    cout << "Enter the 1st polynomial equation's coefficient in decreasing order:";
    do
    {
        cout << "Index : ";
        cin >> index;
        cout << "Coeff of " << index << " :";
        cin >> coeff;
    } while (index != 0);

    return 0;
}