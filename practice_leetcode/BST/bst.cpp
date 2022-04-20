#include <iostream>
using namespace std;

class bstNode {
    public:
    int data;
    bstNode* left;
    bstNode* right;
};

bstNode* GetNewNode(int data){
    bstNode* newNode = new bstNode;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(bstNode** root, int data){
    if(*root == NULL){
        *root = GetNewNode(data);
        return;
    }
    else if(data <= (*root)->data){
        insert(&((*root)->left), data);
    }
    else{
        insert(&((*root)->right),data);
    }
}

bool search(bstNode* root, int data){
    if(root == NULL) return false;
    
    else if(data == root->data) return true;
    else if(data<root->data) return search(root->left, data);
    else return search(root->right, data);
}



int main(){
    bstNode* root1 = NULL; //This initialised the empty tree
    insert(&root1, 15);
    insert(&root1, 10);
    insert(&root1, 20);
    insert(&root1, 25);
    insert(&root1, 8);
    insert(&root1, 12);

    int num;
    cout<<"Enter number to be searched: ";
    cin>>num;

    if(search(root1, num)) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;

    return 0;
}