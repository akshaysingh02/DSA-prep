//In this question we'll learn how to reverse a string using stack data structures
//Wr're also using stack from standard template library 
//Problem : Reverse a string
#include <iostream>
#include <stack>
using namespace std;

void Reverse(char *C)
{
    int len = strlen(C);
    stack <char> S;
    for(int i = 0; i<len;i++){
        S.push(C[i]);
    }

    for(int i = 0;i<len;i++){
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];
    cout << "Enter a string: ";
    gets(C);
    Reverse(C);

    cout<<"Reversed string is : " << C << endl;
}