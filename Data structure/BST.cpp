//In a binary search tree
//From the root node, left subtree should is lesser or equal with respect to root value
// and right subtree and its value should be greater than that of root value
//It have the average time complexcity of Big O(log n) is search,insertion and deletion
#include <iostream>
using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};
//Node in the program will be created dynamicaly in the heap section using the new operator in c++ and malloc in c
//To access the binary search tree we need to store the address of the root into Pointer to bstNode


bstNode *GetNewNode(int data) // this fucntion will create and return new node with data passsed
{
    bstNode *temp = new bstNode;
    temp->data = data;
    temp->left = temp->right = NULL; // right and left pointer will be zero
    return temp;
}

void insert(bstNode *&root, int data) // here we are passing the root by reference to directly make changes in the passed pointer to node by reference
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

//This function will return true if the passed data in found in the tree
//and flase if the data passed doesn't exist in the tree
//we've used the recursion in this function too :) recursion == panic (lmao)
bool Search(bstNode *r, int data)
{
    if (r == NULL)
        return false;
    else if (r->data == data)
        return true;
    else if (data <= r->data)
    {
        return Search(r->left, data);
    }
    else
    {
        return Search(r->right, data);
    }
}

int main()
{
    bstNode *root; // To store the address of root node
    root = NULL;   // set tree as empty
    insert(root, 10);
    insert(root, 77);
    insert(root, 69);
    insert(root, 21);
    insert(root, 88);
    insert(root, 99);

    cout << "Enter any number: ";
    int c;
    cin >> c;
    if (Search(root, c))
    {
        cout << c << " Found in the tree" << endl;
    }
    else
    {
        cout << c << " Not Found in the tree" << endl;
    }
}