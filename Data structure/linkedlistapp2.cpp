//This program illustrate how to impliment code to delete a node from nth postion from and linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head; //global

void insert(int data)
{ //To insert the node at the end of the linked list
    Node *temp = new Node;
    Node *temp1 = new Node;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void del(int pos)
{ // To delete the node at the Nth position of the linked list
    Node *temp1 = new Node;
    temp1 = head;
    if (pos == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = new Node;
    temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void print()
{
    Node *temp = head;
    cout << "List is : " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


//This function will insert given node in a sorted manner
void insertSort(int val)
{
    Node *temp = head;
    if(temp->data >= val){
        Node* temp1 = new Node;
        temp1->data = val;
        temp1->next = temp;
        head = temp1;
        return;
    }
      else{
            Node* prev = head;
            Node* curr = head->next;
            
            while(curr!=NULL){
                if(curr->data >= val){
                    Node* temp1 = new Node;
                    temp1->next = curr;
                    temp1->data = val;
                    prev->next = temp1;
                    return;
                }
                prev=prev->next;
                curr = curr->next;
            }

            Node* temp2 = new Node;
            temp2->data = val;
            temp2->next = NULL;
            prev->next = temp2;
        }  
}

int main()
{
    head = NULL;
    insert(1);
    insert(2);
    insert(4);


    // del(2);
    insertSort(1);
    insertSort(3);
    insertSort(4);

    print();
}
