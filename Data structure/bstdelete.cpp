//In this program we will delete a node;
/*
There will be total three cases
case-0 -> when its a leaf node(i.e no child)
case-1 -> when its node with single child
case-2 -> when its a node with both the child (toughest)
*/
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

bstNode* findmin(bstNode* r){
    while(r->left!=NULL){
        r = r->left;
    }
    return r;
}

bstNode *Delete(bstNode *r, int data)
{
    if (r == NULL)
        return r;
    else if (data < r->data)
    {
        r->left = Delete(r->left, data);
    }
    else if (data > r->data)
    {
        r->right = Delete(r->right, data);
    }

    else //wohooo gotcha beech youre going to be deleted....
    {
        //case-1...No child
        if (r->left == NULL && r->right == NULL)
        {
            delete r;
            r = NULL;
            return r;
        }

        //Case-2...one single child
        if (r->left == NULL) //this the case if there is no left child
        {
            bstNode *temp = r;
            r = r->right;
            delete temp;
        }

        if (r->right == NULL)
        {
            bstNode *temp = r;
            r = r->left;
            delete temp;
        }

        //Case-3...if two children is present
        else
        {
            bstNode* temp = findmin(r->right);
            r->data = temp->data;
            r->right = Delete(r->right, temp->data);
        }
    }
    return r;
}

//to print the bst
void Inorder(bstNode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	cout<<root->data<<" ";  //Print data
	Inorder(root->right);      // Visit right subtree
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


    root = Delete(root, 65);
    Inorder(root);
}
