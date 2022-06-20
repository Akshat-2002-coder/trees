// to see the rihgt side view of a binary tree.
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
vector<int> right_view(struct node* root)
{  vector<int> ans;
   if(root==NULL) return ans;
   map<int,int> mp;
   queue<pair<int,node*>> q;
   q.push({0,root});
   while(!q.empty()){
      auto temp=q.front();
      q.pop();
      int level=temp.first;
      struct node* node=temp.second;
      mp[level]=node->data;
      if(node->left) q.push({level+1,node->left});
      if(node->right) q.push({level+1,node->right});
   }
    for(auto it:mp)
        ans.push_back(it.second);
    return ans;
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
   root->left->right->right=newnode(80);
   ans=right_view(root);
  for(auto it:ans)
     cout<<it<<" ";   
   return 0;
}

// void recursion(node* root,int level,vector<int> &ans)
// {  if(root==NULL) return;
//    if(level==ans.size())
//      ans.push_back(root->data);
//    recursion(root->right,level+1,ans);
//    recursion(root->left,level+1,ans);
// }