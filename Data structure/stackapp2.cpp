//Problem : Reverse a linked list using stack!!!!

#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void Reverse(){
    if(head==NULL) 
        return;
    stack<Node*> S;
    Node* temp = head;
    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }
    
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp= temp->next;
    }
    temp->next = NULL;
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

int main(){
head = NULL;
Insert(3,1);
Insert(4,2);
Insert(5,3);
Insert(6,4);
Insert(7,5);
Insert(8,6);
Node* temp;
// temp = reverse(head); // This function will print the reversed linked list
print(head);

Reverse();

print(head);
 

}