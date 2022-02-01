//This program will show how to reverse print a linked list using the recursion
//And also normally print an linked list using recursion

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* Insert(Node* p, int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (p == NULL)
    {
        p = temp;
    }
    else
    {
        Node* temp1 = p;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return p;
}

void rev_print(Node* p)  //this will reverse print any linked list using recursion
{ 
    if (p == NULL)
    {
        cout<<"\n";
        return;
    }
    rev_print(p->next);
    cout << p->data << " ";
    
}

void print(Node* p)  //this will print any linked list using recursion
{ 
    if (p == NULL)
    {
        cout<<"\n";
        return;
    }
    cout << p->data;
    print(p->next);
}

int main()
{
    Node* head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    head = Insert(head, 10);

    rev_print(head);
}
