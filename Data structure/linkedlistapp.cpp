// This is working program that shows the implementaion of inserting an node at Nth postion in an linked list

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node *head;

void insert(int data, int pos){ 
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(pos == 1){
        temp->next = head;
        head = temp;
        return;
    }
    Node* temp1 = head;
    for (int i = 0; i < pos-2; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    
}

void print(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    head = NULL; //empty list in beggining
    insert(4,1);
    insert(5,2);
    insert(9,2);
    // insert(6,3);
    // insert(7,4);
    // insert(8,5);


    print(); //This will print the entire linked list

}
