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

void insert_at_n(int data, int n){
    node* temp1 = new node;
    temp1->data = data;
    temp1->link = NULL;

    if(n == 1){
        temp1 ->link = head;
        head = temp1;
        return;
    }

    node* temp2 = head;

    for(int i = 1; i<n-1;i++){
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
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
    insert_at_n(3,5);
    print();
    
    
    return 0;
}