#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* link;
};

node* head; // global variable, that can be accessed anywhere in our code

//insert the node at the beggening of the linked list
void insert(int n){
    node* temp = new node;
    temp->data = n;
    temp->link = head;
    head = temp;
}

//Insert elements in the linked list in the sorted order
void insert_sort(int n){
    node* temp = new node;
    temp->data = n;

    if(head == NULL || head->data >= n){
        temp->link = head;
        head = temp;
    }
    else{
    node* temp2 = head;
    while(temp2->link != NULL && temp2->link->data<n){
        temp2 = temp2->link;
    }
    temp->link = temp2->link;
    temp2->link = temp;
    }

}

void print(){
    node* temp = head;
    cout<<"The linked list is: ";
    while(temp != NULL){

        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}


int main(){
    head = NULL; // empty list

    int n = 5,x;
    cout<<"How many number you want to insert in the linked list ? ";
    // cin>>n;
    cout<<endl;

    for(int i = 1; i<=n;i++){
        cout<<"Enter the value of the node "<<i<<" ";
        cin>>x;
        insert(x);
        print();
    }

    return 0;
}