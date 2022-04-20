#include <iostream>
using namespace std;

struct node{
    int data;
    node* link;
};
node* head;

void insert(int n){
    node* temp = new node;
    temp->data = n;
    temp->link = head;
    head = temp;
}

void reverse(){
    node* temp = head;
    node* left = NULL;
    node* right = NULL;

    while(temp != NULL){
        right = temp->link;
        temp->link = left;
        left = temp;
        temp = right;
    }

    head = left;
}



void print(){
    node* temp = head;

    cout<<"The linked list is : ";
    while(temp != NULL){
        cout<<temp->data<<" ";

        temp = temp->link;
    }
    cout<<endl;
}

int main(){
    head = NULL;
    insert(2);
    insert(34);
    insert(12);
    insert(16);
    insert(45);
    insert(45);
    cout<<"Linked list before reversing"<<endl;
    print();
    
    reverse();
    cout<<"Linked list after reversing"<<endl;
    print();
    
    return 0;
}