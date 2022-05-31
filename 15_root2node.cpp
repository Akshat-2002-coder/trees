// to print the root to node path in a given binary tree.
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
bool root2nodepath(vector<int> &ans,struct node* root,int key){
    if(root==NULL)
        return false;
    ans.push_back(root->data);
    if(root->data==key)
        return true;
    if(root2nodepath(ans,root->left,key) || root2nodepath(ans,root->right,key))
        return true;
    ans.pop_back();
    return false;
}
int main()
{  struct node* root=newnode(10);
   vector<int> ans;
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   root2nodepath(ans,root,50);
   for(auto it:ans)
      cout<<it<<" ";
   return 0;
}