// Linked list from mycodeschool
#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *link;
};
Node *head;

//This inserts the new node at the beginning of the 
void insert(int x){
    Node* temp = new Node;
    temp -> data = x;
    temp -> link = head;  // This line performs when list is empty as well as when list already contains some nodes.
    head = temp;
}
void print(){
    Node* temp = head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

void addAtHead(Node* head, int val){
        Node* temp = new Node;
        temp->link = head;
        head = temp;
    }

int main(){
    head = NULL;   //for empty list

    int n,x;
    cout<<"Enter the number of Nodes you want: ";
    cin>>n;

    for (int i = 0; i<n; i++){
        cout<<"Enter the Value for node: "<<endl;
        cin>>x;
        insert(x);  //This function inserts the value given by user to the front of linked list
        print();  //This function prints the linked list
    }
    

}
