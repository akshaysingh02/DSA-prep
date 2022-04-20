//In this program there is a linked list used using a header function and we're using that for the functionality of
// creating a linked list and adding the element in that list in a sorted order and also searchin the element of the linked list

#include "hash_linked_list.h"

int hash_function(int key){
    return key%10;
}

void insert(node *hash_table[], int key){

    int index = hash_function(key);
    insert_sort(&hash_table[index],key);

}



int main(){
    // node* head = NULL; // empty list

    // int n,x;
    // cout<<"How many number you want to insert in the linked list ? ";
    // cin>>n;
    // cout<<endl;
    // for(int i = 1; i<=n;i++){
    //     cout<<"Enter the value for the new node: ";
    //     cin>>x;
    //     // insert_sort(head,x);
    //     insert_sort(&head,x);
    //     print(head);
    // }
    
    // insert_sort(&head, 10);
    // insert_sort(&head,-12);
    // insert_sort(&head, 234);
    // insert_sort(&head, 12);
    // insert_sort(&head, 32);
    // insert_sort(&head, 0);
    // print(head);


    //This is declaration of hash table which is array of pointer which will hold the value of different head nodes
    node* HT[10];
    for(int i =0; i<10;i++){
        HT[i] = NULL;
    }

    insert(HT,12);
    insert(HT,22);
    insert(HT,42);
    
    node* temp = search(HT[hash_function(42)],42);
    cout<<temp->data<<endl;


    return 0;
}