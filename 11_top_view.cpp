// to see the top view of the bonary tree.
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
vector<int> verticaltraveral(node* root){
    map<int,int> mp;
    queue<pair<int,node*>> q;
    q.push({0,root});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        int line=temp.first;
        node *val=temp.second;
        if(mp.find(line)==mp.end())
            mp[line]=val->data;
        if(val->left) q.push({line-1,val->left});
        if(val->right) q.push({line+1,val->right});
    }
    vector<int> ans;
    for(auto it:mp)
        ans.push_back(it.second);
    return ans;
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
  ans=verticaltraveral(root);
  for(auto it:ans)
     cout<<it<<" ";
  return 0;
}