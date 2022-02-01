//This program shows how to traverse a Binary search tree in a pre-order 
//manner, and printing the element of the tree in pre-order manner

#include <iostream>
using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *GetNewNode(int data)
{
    bstNode *temp = new bstNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(bstNode *&root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return;
    }
    else if (data <= root->data)
    {
        insert(root->left, data);
    }
    else
    {
        insert(root->right, data);
    }
}

void preorder(bstNode* r){
    if(r==NULL) return;

    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(bstNode* r){
    if(r==NULL) return;

    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(bstNode* r){
    if(r==NULL) return;

    preorder(r->left);
    preorder(r->right);
    cout<<r->data<<" ";
}

int main()
{
    bstNode *root;
    root = NULL;
    insert(root, 100);
    insert(root, 75);
    insert(root, 77);
    insert(root, 65);
    insert(root, 88);
    insert(root, 20);
    insert(root, 55);
    insert(root, 24);
    insert(root, 83);

    preorder(root);
}