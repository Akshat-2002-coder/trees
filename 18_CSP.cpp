//childrem sum property of a binary tree.
// each node value is the sum of the value of its right and left node.
//to do the boundary order traverssal in anti clock direction
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
};
struct node* newnode(int key)
{   struct node *temp= new node;
    temp->data=key;
    temp->right=temp->left=NULL;
    return temp;
}
void chaangetree(node *root){
    if(root==NULL) return;
    int child=0;
    if(root->left)
       child+=root->left->data;
    if(root->right)
       child+=root->right->data;
    if(child>=root->data) 
       root->data=child;
    else{
        if(root->left)  root->left->data=root->data;
        else if(root->left)  root->right->data=root->data;
    }
    chaangetree(root->left);
    chaangetree(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
}
int main()
{   struct node* root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);
    root->left->right=newnode(50);
    root->right->left=newnode(60);
    root->right->right=newnode(70);
    
    return 0;
} 