// to const the given tree using its inorder and postorder 
//to construct a binary tree from the given inorder and postorder.
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left, *right;
};
struct node* solve(vector<int> &postorder,int poststart,int postend,
                                                vector<int> &inorder,int instart,int inend,map<int,int> &mp){
    if(poststart>postend || instart>inend) return NULL;
    struct node *temp=new node;
    temp->data=postorder[postend];
    int inroot=mp[postorder[postend]]; // mp[temp->data];
    int numsleft=inroot-instart;
    temp->left=solve(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mp);
    temp->right=solve(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mp);
    return temp;
}
struct node* constbinarytree(vector<int> &postorder,int poststart,int postend,
                                                vector<int> &inorder,int instart,int inend){
    map<int,int> mp;
    for(int i=0 ; i<=inend ; i++)
        mp[inorder[i]]=i;
    struct node *root=solve(postorder,poststart,postend,inorder,instart,inend,mp);
    return root;
}
int main(){
    vector<int> postorder={3,9,15,20,7},inorder={9,3,15,20,7};
    int poststart=0,postend=postorder.size()-1,instart=0,inend=inorder.size();
    struct node* root=constbinarytree(postorder,poststart,postend,inorder,instart,inend);
}