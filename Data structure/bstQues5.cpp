//This the question of the Inorder Successor in a binary search tree
//where we need to find the next node in a way that we are traversing
//inorder manner

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//This fuction will find the node of given data and return prt to node
Node* Find(Node* r, int data){
    if(r==NULL) return r;
    else if(data<=r->data){
        return Find(r->left,data);
    }
    else if(data>r->data){
        return Find(r->right,data);
    }
    else{
        return r;
    }
}

//This function will return the address of Node with minimum value
Node* FindMin(Node* r){
    if(r == NULL){
        return NULL;
    }
    while(r->left!=NULL){
        r= r->left;
    }
    return r;
}

//This is the code to find the succesor or ancestor
Node *GetSuccessor(Node *root, int data)
{
    //first thing we need to do is search the node with data passed
    Node* current = Find(root, data);
    if(current == NULL) return NULL;


    //case-1: Node has the right subtree
    if(current->right != NULL){
        return FindMin(root->right);
    }

    //Case-2: If there is no right subtree
    else{
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor!= current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
            ancestor = ancestor->right;
            }
        }
        return successor;
    }
}