// to find whether the given tree is symmetric or not
#include<bits/stdc++.h>
using namespace std;
struct node
{  int data;
   node *left,*right;
};
struct node* newnode(int val)
{  struct node *temp=new node;
   temp->data=val;
   temp->left=NULL;
   temp->right=NULL;
   return temp;
}
bool issymmetric(struct node* left,struct node* right)
{  if(left==NULL || right==NULL) left==right;
   if(left->data != right->data) return false;
   return issymmetric(left->left,right->right) && issymmetric(left->right,right->left);
}
int main()
{ vector<int>ans;
  struct node* root=newnode(10);
  root->left=newnode(20);
  root->right=newnode(30);
  root->left->left=newnode(40);
  root->left->right=newnode(50);
  root->right->left=newnode(60);
  root->right->right=newnode(70);
  cout<<issymmetric(root->left,root->right);
  return 0;
}