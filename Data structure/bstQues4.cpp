//This program will check if a binary tree is binary search tree or not...
//for a binary tree to be a binary search tree, all values in the left
//subtre from the  root should be lesser and that of the value of the
// right subtree should be greater than that of root node, and both left
// and right subtree should be also Binary search tree

//In case, you have duplicates in your tree use root->data >= min && root->data <= max
#include <iostream>
#include <math.h>

//we can't set these to +infinity and - infinity, so we set int_min to minimum limit of 
//int possibe so that it will be smaller than all possible values.
//and same logic goes for the int_max 
// int int_min = std::numeric_limits<int>::lowest();
// int int_max = std::numeric_limits<int>::max();


//If you really need a true "infinite" value, you would have to use a double or a float. Then you can simply do this
//float a = std::numeric_limits<float>::infinity();


//simply use math.h header file and set infinity
double int_min = -INFINITY;
double int_max = INFINITY;


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
//The easy to think logic is to create two functions one will check
// if the tree is lesser and one will tell if the tree is greater
//This is not so effecient,because the time complexcity is O(n^2)
//Which is worst..

//These two function will recieve a pointer to bst and a int vlaue
// to compare if all values are greater or lesser

// bool IsSubTreeLesser(bstNode *r, int val)
// {
//     if (r == NULL)
//         return true;
//     if (r->data <= val 
//     && IsSubTreeLesser(r->left, val) 
//     && IsSubTreeLesser(r->right, val))
//     {
//         return true;
//     }
//     else
//         return false;
// }

// bool IsSubTreeGreater(bstNode *r, int val)
// {
//     if (r == NULL)
//         return true;

//     if (r->data > val 
//     && IsSubTreeGreater(r->left, val) 
//     && IsSubTreeGreater(r->right, val))
//     {
//         return true;
//     }
//     else
//         return false;
// }

//This function will return true if the tree is bst and flase if it's not
// bool isBst(bstNode *r)
// {
//     if (r == NULL)
//         return true;
//     if (IsSubTreeLesser(r->left, r->data) 
//     && IsSubTreeGreater(r->right, r->data) 
//     && isBst(r->left) 
//     && isBst(r->right))
//     {
//         return true;
//     }
//     else
//         return false;
// }

//The simillar logic is to find maximum value in left subtree and find min
//value in right subtree and compare them to data in root if the maximum
// of left subtree is lesser than all other value will be lesser too
//and compare the minimum of the right subtree, because if the minimum
// of right subtree is greater than data in root then all other value
// will be greater too

//--------------*********----------------//

//And the other logic is to set lower and upper bound to node, for example
// The vlaue of the root node can be in between -infinity and +infinity
// and the vaule of the left node should be in between -infinty and root->data
// same logic will go on for every node in the tree
//So now in place of checking IsSubTreeGreater and IsSubTreeLesser we can simply
//check if the data lies between lowerbound and upperbound
//This approach will reduce the time complexcity of the function from O(nˆ2) to O(n)
bool isBstUtil(bstNode *r, double Min_val, double Max_val)
{
    if (r == NULL)
        return true;
    if (r->data > Min_val    // these two will take constant time
        && r->data < Max_val //
        && isBstUtil(r->left, Min_val, r->data) 
        && isBstUtil(r->right, r->data, Max_val))
    {
        return true;
    }
    else
        return false;
}

bool isbst(bstNode* r){
    return isBstUtil(r,int_min, int_max);
}


int main()
{
    bstNode *root;
    root = NULL;
    insert(root, 100);
    insert(root, 75);
    insert(root, 85);
    insert(root, 110);
    insert(root, 107);
    insert(root, 120);
    insert(root, 116);
    insert(root, 55);
    insert(root, 65);

    if(isbst(root)){
        cout<<"It is a binary search tree"<<endl;
    }
    else{
        cout<<"Not a binary search tree"<<endl;
    }
}


/*
Another method is to traverse the tree using Inorder method and store the value in array 
and check if the data in the array is sorted in increasing order or not, if the data is sorted then our tree is binary search tree.
To check if the data is sorted compare newly inserted data in the array with the last one and see if its greater or not
*/