// to find the minimum fl taken to burn the given binary tree from the given node.

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
int burn(map<node*,node*> &mpp,struct node* start){
    queue<node*> q;
    q.push(start);
    map<node*,int> vis;
    vis[start]=1;
    int maxi=0;
    while(!q.empty()){
        int sz=q.size();
        int fl=0;
        for(int i=0 ; i<sz ; i++){
            struct node* temp=q.front();
            q.pop();
            if(temp->left && !vis[temp->left]){
                fl=1;
                vis[temp->left]=1;
                q.push(temp->left);
            }
            if(temp->right && !vis[temp->right]){
                fl=1;
                vis[temp->right]=1;
                q.push(temp->right);
            }
            if(mpp[temp] && !vis[mpp[temp]]){
                fl=1;
                vis[mpp[temp]]=1;
                q.push(mpp[temp]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;
}
struct node* bfstomarkparents(struct node* root,map<node*,node*> &mpp,int start){
    queue<node*> q;
    q.push(root);
    struct node* res;
    while(!q.empty()){
        struct node* temp=q.front();
        q.pop();
        if(temp->left){
            mpp[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            mpp[temp->right]=temp;
            q.push(temp->right);
        }
        if(temp->data==start) res=temp;
    }
    return res;
}
int fltakentoburntree(node* root,int start){
    map<node*,node*> mpp;
    struct node* target=bfstomarkparents(root,mpp,start);
    int maxi=burn(mpp,target);
    return maxi;
}
int main()
{  struct node* root=newnode(10);
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   int time=fltakentoburntree(root,10);
   cout<<time;
   return 0;
}