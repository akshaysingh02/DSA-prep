//This program shows how to calculate the fibnacchi series of any number

// #include <iostream>
// using namespace std;

// int fib(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     else
//     {
//         int temp = fib(n - 1) + fib(n - 2);
//         return temp;
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter a to calculate factorial of: ";
//     cin >> n;
//     int temp = fib(n);
//     cout << temp;
// }

//The recursive function for calculating the fibnacci series is having the time complexcity of (a power b), which is  not prefferable.
//Always keep in mind recursion is not always good in terms of space and time complexcity

//so we use the recursion with memoization to reduce space and time comlexcity of the function.
//The logic beind is that we save the value that is once being calculated which save our
//time and space
//This approach is also similar to dynamic programming

#include <iostream>
using namespace std;
int F[51];
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (F[n] != -1)
    {
        return F[n];
    }
    F[n] = fib(n - 1) + fib(n - 2);
    return F[n];
}

int main()
{
    for (int i = 0; i < 51; i++)
    {
        F[i] = -1;
    }


    int n;
    cout << "Enter a to calculate fibnacci of: ";
    cin >> n;
    int temp = fib(n);
    cout << temp;
}
