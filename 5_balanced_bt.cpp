//to check whetaher the given binary tree is balanced binary tree or not. O(n) solution
// we will return the height iof the tree if the tree is balanced binary tree else -1.
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
int max_depth(struct node* temp)
{  if(temp==NULL)
      return 0;
   int lh=max_depth(temp->left);
   int rh=max_depth(temp->right);
   if(lh==-1||rh==-1) return -1;
   if(abs(lh-rh)>1)return -1;
   return 1+max(lh,rh);

} 
int main()
{  struct node* root=newnode(10);
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   cout<<"maximum depth = "<<max_depth(root);
   return 0;
}