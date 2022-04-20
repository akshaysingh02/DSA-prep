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

void delete_at_nth(int n){
    node* temp = head;
    if(n==1){
        head = temp->link;
        delete temp;
        return;
    }

    for(int i =1; i<n-1;i++){
        temp = temp->link;
    }
    node* not_needed = temp->link;
    temp->link  = temp->link->link;
    delete not_needed;
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
    // delete_at_nth(1);
    delete_at_nth(1);
    delete_at_nth(2);
    print();


    
    
    return 0;
}