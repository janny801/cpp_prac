#include <iostream> 
#include <stdio.h>
using namespace std; 
#include <algorithm> //maybe try to do it without this if can tho 
                        //prob will be used for max()/min() function 

struct treenode
{
    int value; 
    treenode* left; 
    treenode* right; 
    
    //constructor to create new nodes 
    treenode(int val) 
    {
        value = val; 
        left = nullptr; 
        right = nullptr; 
    }
    
}; 

int maxdepth(treenode*root)
{
    //base case 
    if(root ==nullptr)
    {
        return 0; 
    }
    
    //recurse left side 
    int leftheight = maxdepth(root-> left); 
    
    
    //recurse right side 
    int rightheight =maxdepth(root-> right); 
    
    return 1+ max(leftheight, rightheight); 
}

int main()
{
    /*
            3
           / \
          9   20
             /  \
            15   7
    */

    // create nodes
    treenode* root = new treenode(3);
    root->left = new treenode(9);
    root->right = new treenode(20);
    root->right->left = new treenode(15);
    root->right->right = new treenode(7);

    // call the maxdepth function (you will write this later)
    int depth = maxdepth(root);

    cout << "Maximum depth of tree: " << depth << endl;

    return 0;
}