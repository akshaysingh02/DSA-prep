//This is stack implementation using linked list which is prefered over the array implementation

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = NULL; // This is for creating and empty stack

void push(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL){
        cout<<"Error: stack is empty"<<endl;
        return;
    }
        
    Node *temp;    
    temp = top;
    top = temp->next;
    delete temp;
}
bool IsEmpty() // This function will inform is stack is empty or not
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node *Top()
{
    Node *temp = new Node;
    temp = top;
    return temp;
}
void print()
{
    Node *temp = new Node;
    temp = top;
    cout<<"Stack is : ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    push(2); print();
    push(3); print();
    push(5); print();
    pop(); print();
    push(6); print();
}