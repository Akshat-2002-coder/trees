//to construct a binary tree from the given inorder and preorder.
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left, *right;
};
struct node* solve(vector<int> &preorder,int prestart,int preend,
                                                vector<int> &inorder,int instart,int inend,map<int,int> &mp){
    if(prestart>preend || instart>inend) return NULL;
    struct node *temp=new node;
    temp->data=preorder[prestart];
    int inroot=mp[preorder[prestart]]; // mp[temp->data];
    int numsleft=inroot-instart;
    temp->left=solve(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mp);
    temp->right=solve(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mp);
    return temp;
}
struct node* constbinarytree(vector<int> &preorder,int prestart,int preend,
                                                vector<int> &inorder,int instart,int inend){
    map<int,int> mp;
    for(int i=0 ; i<=inend ; i++)
        mp[inorder[i]]=i;
    struct node *root=solve(preorder,prestart,preend,inorder,instart,inend,mp);
    return root;
}
int main(){
    vector<int> preorder={3,9,15,20,7},inorder={9,3,15,20,7};
    int prestart=0,preend=preorder.size()-1,instart=0,inend=inorder.size();
    struct node* root=constbinarytree(preorder,prestart,preend,inorder,instart,inend);
}