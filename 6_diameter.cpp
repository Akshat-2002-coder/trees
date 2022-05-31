//to find the diameter of thr binary tree.
//diametr is the longest path between the two nodes.The path is not necessarely pass through the root node. 
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
int diameter(struct node* temp,int &maxi)
{  if(temp==NULL)
      return 0;
   int lh=diameter(temp->left,maxi);
   int rh=diameter(temp->right,maxi);
   maxi=max(maxi,lh+rh);
   return 1+max(lh,rh);

} 
int main()
{  struct node* root=newnode(10);
   int maxi=0;
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   diameter(root,maxi);
   cout<<"diameter = "<<maxi;
   return 0;
}