//To do the leval order traversal of a binary tree
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
int widthofbinarytree(struct node* root)
{ if(root==NULL) return 0;
  int ans=0;
  queue<pair<node*,int>> q;
  q.push({root,0});
  while(!q.empty()){
     int size=q.size();
     int mmin=q.front().second;
     int first,last;
     for(int i=0 ; i<size ; i++){
        int cur_id=q.front().second-mmin;
        struct node* temp=q.front().first;
        q.pop();
        if(i==0) first= cur_id;
        if(i==size-1) last=cur_id;
        if(temp->left)  q.push({temp->left , cur_id*2+1});
        if(temp->right)  q.push({temp->right , cur_id*2+2});
     }
     ans=max(ans,last-first+1);
  }
  return ans;
}
int main()
{ vector<vector<int>> ans;
  struct node* root=newnode(10);
  root->left=newnode(20);
  root->right=newnode(30);
  root->left->left=newnode(40);
  root->left->right=newnode(50);
  root->right->left=newnode(60);
  root->right->right=newnode(70);
  cout<<widthofbinarytree(root); 
  return 0;
}