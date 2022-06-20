//to serealize and deserealize a given binary tree.

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
string serealize(struct node* temp)
{  if(!temp)
     return "";
   queue<node*> q;
   q.push(temp);
   string str="";
   while(!q.empty())
   {  struct node* curr=q.front();
      q.pop();
      if(curr==NULL) str.append("#,");
      else str.append(to_string(curr->data)+",");
      if(curr!=NULL){
        q.push(curr->left);
        q.push(curr->right);
      }
   }
   return str;
} 
struct node* deserealize(string data)
{  if(data.size()==0) return NULL;
   stringstream s(data);
   string str;
   getline(s,str,',');
   struct node* root=new node();
   root->data=stoi(str);
   queue<node*> q;
   q.push(root);
   while(q.empty()){
       struct node* temp=q.front();
       q.pop();
       getline(s,str,',');
       if(str=="#") temp->left=NULL;
       else{
          struct node* leftnode=new node;
          leftnode->data=stoi(str);
          q.push(leftnode);
       }
       getline(s,str,',');
       if(str=="#") temp->left=NULL;
       else{
          struct node* rightnode=new node;
          rightnode->data=stoi(str);
          q.push(rightnode);
       }
   }
   return root;
}
int main()
{  struct node* root=newnode(10);
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
   string str=serealize(root);
   struct node* base=deserealize(str);
   return 0;
}