//to do the boundary order traverssal in anti clock direction
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
};
struct node* newnode(int key)
{   struct node *temp= new node;
    temp->data=key;
    temp->right=temp->left=NULL;
    return temp;
}
bool isleaf(struct node *temp)
{   if(temp->left== NULL && temp->right==NULL) 
      return true;
    return false;
}
void addleft(vector<int> &ans,struct node *ptr)
{   struct node *temp=ptr->left;
    while(temp!=NULL){
        if(isleaf(temp)==false) ans.push_back(temp->data);
        if(temp->left==NULL) temp=temp->right;
        else temp=temp->left;
    }
}
void addright(vector<int> &ans,struct node *ptr)
{   struct node *temp=ptr->right;
    stack<int>st;
    while(temp!=NULL){
        if(isleaf(temp)==false) st.push(temp->data);
        if(temp->right==NULL) temp=temp->left;
        else temp=temp->right;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
void addleaf(vector<int> &ans,struct node *ptr)
{   if(isleaf(ptr)){
      ans.push_back(ptr->data);
      return ;
    }
    if(ptr->left) addleaf(ans,ptr->left);
    if(ptr->right) addleaf(ans,ptr->right);
}
void boundary_traversal(struct node *root)
{   vector<int> ans;
    if(!isleaf(root)) ans.push_back(root->data);
    addleft(ans,root);
    addleaf(ans,root);
    addright(ans,root);
    for(auto it:ans)
        cout<<it<<" ";
}
int main()
{   struct node* root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);
    root->left->right=newnode(50);
    root->right->left=newnode(60);
    root->right->right=newnode(70);
    boundary_traversal(root);
    return 0;
} 