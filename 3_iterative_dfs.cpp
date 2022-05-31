// inorder preorder postorder using iterative method(stack)
#include<bits/stdc++.h>
using namespace std;
struct node
{  int data;
   struct node *left,*right;
};
struct node* newnode(int key)
{  struct node* temp= new node;
   temp->data=key;
   temp->right=temp->left=NULL;
   return temp;
}
void preorder(struct node* temp)
{  if(!temp)
     return ;
   stack<node*> st;
   st.push(temp);
   while(!st.empty())
   {  struct node* ptr=st.top();
      st.pop();
      cout<<ptr->data<<" ";
      if(ptr->right!=NULL) st.push(ptr->right);
      if(ptr->left!=NULL) st.push(ptr->left);
   }
}
void inorder(struct node *temp)
{  if(!temp)
     return ;
   stack<node*> st;
   struct node* ptr=temp,*ptr1;
   st.push(ptr);
   while(!st.empty())
   {  if(ptr!=NULL){
        ptr=ptr->left;
        st.push(ptr);
      }
      else{
        st.pop();
        ptr=st.top();
        cout<<ptr->data<<" ";
        st.pop();
        ptr=ptr->right;
        st.push(ptr);
      }
    }
}
//using 2 stacks
void postorder(struct node *temp)
{  stack<node*> st1,st2;
   st1.push(temp);
   while(st1.empty()==0)
   {  struct node *root=st1.top();
      st1.pop();
      st2.push(root);
      if(root->left!=NULL) st1.push(root->left);
      if(root->right!=NULL) st1.push(root->right);
   }
   while(st2.empty()==0)
   {  int data=st2.top()->data;
      cout<<data<<" ";
      st2.pop();
   }
}
int main()
{  struct node* root=newnode(10);
   root->left=newnode(20);
   root->right=newnode(30);
   root->left->left=newnode(40);
   root->left->right=newnode(50);
   root->right->left=newnode(60);
   root->right->right=newnode(70);
  
   cout<<"preorder traversal:- ";
   preorder(root);
   cout<<endl;
   cout<<"postorder traversal(2 stack):- ";
   postorder(root);
   cout<<endl;
   cout<<"inorder traversal:- ";
   inorder(root);
  
   
   return 0;
}