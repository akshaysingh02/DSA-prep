//In this program we will calculate exponential power using recursion ex- claculating x^2
// using the recursion

#include <iostream>
using namespace std;

int pow(int x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    int temp = pow(x,n/2);
    
    if (n % 2 == 0) return temp*temp;
    
    else return x*temp*temp;
}

int main()
{
    int n, x;
    int q = pow(5, 2);
    cout << q<<endl;
}