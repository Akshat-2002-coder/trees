//to count nodes in a complete bonary tree.
// inoder preorder postorder traversal using recursion
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
int findleftheight(struct node* root){
    int height=0;
    while(root){
        height++;
        root=root->left;
    }
    return height;
}
int findrightheight(struct node* root){
    int height=0;
    while(root){
        height++;
        root=root->right;
    }
    return height;
}
int countnodes(node* root){
    if(root==NULL) return 0;
    int lh=findleftheight(root);
    int rh=findrightheight(root);
   
    if(lh==rh) return (1<<lh) -1;
    return 1+countnodes(root->left)+countnodes(root->right);
}

int main()
{  struct node* root=newnode(10);
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   cout<<countnodes(root);
   return 0;
}