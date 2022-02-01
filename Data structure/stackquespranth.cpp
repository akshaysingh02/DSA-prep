//This program will illustrate the problem
//Check for the balanced parantheses
//This is a very famous programming interview question
//In this program we check that for every opening bracket or parantheses there is
//counter part or closing bracket or parantheses, and check if the given expression is balanced or not.

#include <iostream>
#include <stack>
using namespace std;

bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    return false;
}

bool checkForBalancedParantheses(string exp)
{
    stack<char> P;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            P.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (P.empty() || !ArePair(P.top(), exp[i]))  // visulaize ArePair function for understanding.
            {
                return false;
            }
            else
            {
                P.pop();
            }
        }
    }
    return P.empty() ? true : false;
}

int main()
{
    string str;
    cout << "Enter an expression:  "; // input expression from STDIN/Console
    cin >> str;
    if (checkForBalancedParantheses(str))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}
