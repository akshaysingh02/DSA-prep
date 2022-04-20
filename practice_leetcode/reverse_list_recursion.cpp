#include <iostream>
using namespace std;

struct node {
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

void print(){
    node* temp = head;

    cout<<"The linked list is : ";
    while(temp != NULL){
        cout<<temp->data<<" ";

        temp = temp->link;
    }
    cout<<endl;
}

void reverse_recursion(node* temp){

    if(temp->link == NULL){
        head = temp;
        return;
    }

    reverse_recursion(temp->link);
    node* temp2 = temp->link;
    temp2->link = temp;
    temp->link = NULL;
}


int main(){
    insert(2);
    insert(34);
    insert(12);
    insert(16);
    insert(45);
    insert(45);

    print();

    cout<<"After reversing using recursion"<<" ";
    reverse_recursion(head);
    print();


    return 0;
}