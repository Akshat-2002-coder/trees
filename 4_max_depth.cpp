//to find the maximum depth(height) of a binnary tree.
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