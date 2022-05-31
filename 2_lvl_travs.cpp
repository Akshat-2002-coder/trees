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
void level(vector<vector<int>> &ans,struct node *root)
{  queue<node*> q;
   q.push(root);
   while(q.empty()==0)
   {  int size=q.size();
      vector<int> vt;
      for(int i=0 ; i<size ; i++)
      {  struct node *temp=q.front();
         q.pop();
         if(temp->left!=NULL) q.push(temp->left);
         if(temp->right!=NULL) q.push(temp->right);
         vt.push_back(temp->data);
      }
      ans.push_back(vt);
   }
   return ;
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
  level(ans,root);
  for(auto it:ans)
  {  for(auto it1:it)
       cout<<it1<<" ";
     cout<<endl;
  }
  return 0;
}