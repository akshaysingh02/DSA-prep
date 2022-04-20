#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* link;
};

// void insert( node** head,int n){
//     node* temp = new node;
//     temp->data = n;
//     temp->link = *head;
//     *head = temp;
// }
void print(node* head){
    cout<<"The linked list is: ";
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->link;
    }
    cout<<endl;
}

//insert element in the linked list in the sorted order
void insert_sort(node **head,int n){
    node* temp = new node;
    temp->data = n;

    if(*head == NULL || (*head)->data >= n){
        temp->link = *head;
        *head = temp;
    }
    else{
    node* temp2 = *head;
    while(temp2->link != NULL && temp2->link->data<n){
        temp2 = temp2->link;
    }
    temp->link = temp2->link;
    temp2->link = temp;
    }
}

//This is the function for the searching the node in the linked list
node* search(node* head, int x){
    while(head!=NULL){
        if(head->data == x){
            return head;
        }
        else{
            head = head->link;
        }
    }
    return NULL;
}


// int main(){
    // head = NULL; // empty list

    // int n,x;
    // cout<<"How many number you want to insert in the linked list ? ";
    // cin>>n;
    // cout<<endl;

    // for(int i = 1; i<=n;i++){
    //     cout<<"Enter the value of the node "<<i<<" ";
    //     cin>>x;
    //     insert(x);
    //     print();
    // }

    // return 0;
// }