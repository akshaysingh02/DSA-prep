//This program is based upon finding the minimum and maximum value in the Binary search tree using iterative and recursive approach


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

//This is the program to find the minimum value inside the binary search tree
int findmin(bstNode *r)
{
    if (r == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    // while (r->left != NULL)
    // {
    //     r = r->left;     This approach is iterative 
    // }
    // return r->data;


//This the code for the recursive approach
    else if(r->left == NULL){
        return r->data;
    }
    return findmin(r->left);

}

//This is the program to find the maximum value inside the binary search tree
int findmax(bstNode* r){
    if(r == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }

    else if(r->right==NULL){
        return r->data;
    }
    return findmax(r->right);
}


int main()
{
    bstNode *root;
    root = NULL;
    insert(root, 10);
    insert(root, 77);
    insert(root, 69);
    insert(root, 21);
    insert(root, 88);
    insert(root, 99);

    int min = findmin(root);
    cout << min <<" Is the minimum value in the Tree"<< endl;

    int max = findmax(root);
    cout << max <<" Is the maximum value in the Tree"<< endl;
}