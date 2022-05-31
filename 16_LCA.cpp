// to find the lowest common ancestor in a binary tree.
// one method is to find the node to root path of both nodes and then compare the botn list 
// return the value just before the point where both the array differs. extra space of O(n) is used
// next method is recursive method.
#include<bits/stdc++.h>
using namespace std;
struct node
{  int data;
   node *right, *left;
};
struct node* newnode(int key)
{  struct node* temp= new node;
   temp->data=key;
   temp->right=temp->left=NULL;
   return temp;
}
struct node* lowestcommonancestor (node* root,node* p,node *q){
    if(root==NULL || root==p || root==q)
      return root;
    node* left=lowestcommonancestor(root->left,p,q);
    node* right=lowestcommonancestor(root->right,p,q);

    if(left==NULL)
       return right;
    else if(right==NULL)
       return left;
    else  return root;  //both left and right are not null we have found the result.
}
int main()
{  struct node* root=newnode(10);
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   struct node* temp=lowestcommonancestor(root,root->left->left,root->left->right);
   cout<<temp->data;
   return 0;
}