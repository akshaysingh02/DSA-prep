#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head;

void InsertatHead(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    else{
    temp->next = head;
    head = temp;
    temp->next->prev = temp;
    }
}

void Insertattail(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
}

void print(){
    Node* temp = head;
    cout<<"Linked list is : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverseprint(){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"Reverse Linked list is : ";
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;

}


int main(){
    head = NULL;
    InsertatHead(2);
    InsertatHead(4);
    InsertatHead(7);
    Insertattail(9);
    Insertattail(11);
    Insertattail(13);

    print(); 

    reverseprint();
}