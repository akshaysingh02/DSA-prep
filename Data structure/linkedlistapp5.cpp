//This program will show how to reverse a linked list using recursion

// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* next;
// };
// Node* Insert(Node* p, int data)
// {
//     Node* temp = new Node;
//     temp->data = data;
//     temp->next = NULL;
//     if (p == NULL)
//     {
//         p = temp;
//     }
//     else
//     {
//         Node* temp1 = p;
//         while (temp1->next != NULL)
//         {
//             temp1 = temp1->next;
//         }
//         temp1->next = temp;
//     }
//     return p;
// }

// void print(Node* p)  //this will print any linked list using recursion
// {
//     if (p == NULL)
//     {
//         cout<<"\n";
//         return;
//     }
//     cout << p->data;
//     print(p->next);
// }
// Node* reverse(Node* head){
//  Node *temp1 = new Node;
//     Node *temp2 = new Node;
//     if (head->next == nullptr) {
//         return head;
//     }
//     else {
//         temp1 =reverse(head->next);
//         temp2 =head->next;
//         temp2->next = head;
//         head->next = nullptr;
//     }
//     return temp1;

//     //below commented function is normal explanation
//     // if(p==NULL){
//     //     head = p;
//     //     cout<<endl;
//     // }
//     // reverse(p->next);
//     // Node* q = p->next;
//     // q->next = p;
//     // p->next = NULL;
// }

// int main()
// {
//     Node* head = NULL;
//     head = Insert(head, 2);
//     head = Insert(head, 4);
//     head = Insert(head, 6);
//     head = Insert(head, 8);
//     head = Insert(head, 10);

//     reverse(head);
//     print(head);
// }

// ------------This is the working program from youtube ------------------

// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     Node* next;
// };
// Node* Insert(Node *head,int data) {
//     Node *temp1 = new Node;
//     temp1 -> data = data;
//     temp1 -> next = nullptr;
//     if (head == nullptr) head = temp1;
//     else {
//         Node *temp2= head;
//         while(temp2 -> next != nullptr) {
//             temp2 = temp2->next;
//         }
//         temp2 -> next = temp1;
//     }
//     return head;
// };
// Node *RevRecursion(Node *head) {
//     Node *temp1 = new Node;
//     Node *temp2 = new Node;
//     if (head->next == nullptr) {
//         return head;
//     }
//     else {
//         temp1 =RevRecursion(head->next);
//         temp2 =head->next;
//         temp2->next = head;
//         head->next = nullptr;
//     }
//     return temp1;
// };
// void Print(Node *p) {  // Node *p is a local variable
//     if (p==nullptr) return;  //Exit condition
//     cout << p->data << " ";       // First print the value in the node
//     Print(p->next);              // Recursive call
// };
// int main(){
//     Node *head = nullptr;   // local variable
//     head = Insert(head,2);  // add node at the end of the list
//     head = Insert(head,4);
//     head = Insert(head,6);
//     head = Insert(head,5);// List 2
//     Print(head);
//     cout << endl;
//     head = RevRecursion(head);
//     Print(head);
//     cout << endl;
//     return 0;
// }

//--------This is thrid try to successfully imliment program using head as a global----
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}; // Don't forget to add ending colon like you do everytime
Node *head;

void Insert(int pos, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node *temp1 = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void Rev(Node *p) // This program will reverse the linked list using recursion
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Rev(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void print(Node *p)
{
    if (p == NULL)
    {
        cout << endl;
        return;
    }
    cout << p->data << " ";
    print(p->next);
}

int main()
{
    head = NULL;
    Insert(1, 11);
    Insert(2, 12);
    Insert(3, 13);
    Insert(4, 14);
    Insert(5, 15);
    Insert(6, 16);
    Insert(7, 17);

    cout << "Normal list: ";
    print(head);
    cout << "\n";

    Rev(head); // this will reverse the list using recursion
    cout << "reversed list: ";

    print(head); // this function will print the linked list using recursion
}
