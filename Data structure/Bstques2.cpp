//In this program we'll calculate the height of BST (or we can say the maximum depth)
//Height of a root is also defined as the Number of the edges in the longest path from root to a leaf node
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

int findheight(bstNode* r){
    if(r == NULL){
        return -1;
    }
    return max(findheight(r->left),findheight(r->right))+1;
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

    cout<<"Height of the tree is: "<<findheight(root)<<endl;
}