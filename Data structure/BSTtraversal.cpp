//This is the code for binary tree level order traversal
//And how to print binary tree in the level order manner using queues
#include <iostream>
#include <queue>
using namespace std;

struct bstNode
{
    char data;
    bstNode *left;
    bstNode *right;
};

bstNode *GetNewNode(char data)
{
    bstNode *temp = new bstNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(bstNode *&root, char data)
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

//This function will take pointer to tree as arguement and print 
//the data of the tree in the level order manner
void levelorder(bstNode* r){
    if(r==NULL) return;

    queue<bstNode*> Q;
    Q.push(r);
    while(!Q.empty()){
        bstNode* temp = Q.front();
        cout<<temp->data<<" ";
        if(temp->left!=NULL) Q.push(temp->left);
        if(temp->right!=NULL) Q.push(temp->right);
        Q.pop();
    }
}


int main()
{
    bstNode *root;
    root = NULL;
    insert(root, 'M');
    insert(root, 'B');
    insert(root, 'Q');
    insert(root, 'Z');
    insert(root, 'A');
    insert(root, 'C');

    levelorder(root);
    
}

