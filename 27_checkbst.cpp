//program to check whether the given tree is bst or not.

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
bool check(struct node* temp,int left_limit,int right_limit)
{   if(temp==NULL) return true;
    if(temp->data<=left_limit || temp->data>=right_limit) return false;
    return check(temp->left,left_limit,temp->data) && check(temp->right,temp->data,right_limit);

}
int main()
{  struct node* root=newnode(40);
   root->left=newnode(30);
   root->right=newnode(60);
   root->left->left=newnode(10);
   root->left->right=newnode(20);
   root->right->left=newnode(50);
   root->right->right=newnode(70);
   bool ans=check(root,INT_MIN,INT_MAX);
   cout<<ans;
   return 0;
}