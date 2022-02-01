// This program shows to reverse a linked list using itrative method

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* head;
Node* reverse(Node* head){ // This reverse function recieves an argument as the head of any linked list and return the pointer to head of the reversed linked list
    Node *prev, *next, *current;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void Insert(int data, int pos){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (pos == 1){
        temp->next = head;
        head = temp;
        return;
    }
    
    Node* temp1 = new Node;
    temp1 = head;
    for(int i = 0;i<pos-2;i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void print(Node* head){ // this will print any given linked list 
    Node* temp;
    temp = head;
        cout<<" linked list is: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


void addAtHead(Node* head, int val){
        Node* temp = new Node;
        temp->next = head;
        head = temp;
    }

int main(){
head = NULL;
Insert(3,1);
Insert(4,2);
Insert(5,3);
Insert(6,4);
Insert(7,5);
Insert(8,6);
// Node* temp;
// temp = reverse(head); // This function will print the reversed linked list
print(head);



}