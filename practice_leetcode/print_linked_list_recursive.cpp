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

void print_recursive(node* temp){
    if(temp == NULL){
        return;
    }

    cout<<temp->data<<" ";
    print_recursive(temp->link);
}

void print_recursive_reverse(node* temp){
    if(temp == NULL) {
        return;
    }

    print_recursive_reverse(temp->link);

    cout<<temp->data<<" ";
}


int main(){
    insert(2);
    insert(34);
    insert(12);
    insert(16);
    insert(45);
    insert(45);
    // cout<<"Linked list printing"<<endl;
    print();

    cout<<"Linked list printing using recursion is : ";
    print_recursive(head);
    
    
    // cout<<"Linked list printing in reverse order using recursion is : ";
    // print_recursive_reverse(head);


    return 0;
}