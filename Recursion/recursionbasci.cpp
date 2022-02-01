//This program shows the use of recursion in calculating the factorila of any number

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
    {
        return n*factorial(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter a to calculate factorial of: ";
    cin >> n;
    int temp = factorial(n);
    cout<<temp;
}