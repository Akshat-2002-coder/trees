//print all nodes at a distance of k from a gove node.
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
void markparents(node* root,unordered_map<node*,node*> &parent_track,node* target){
    queue<node*> queue;
    queue.push(root);
    while(!queue.empty()){
        node* current=queue.front();
        queue.pop();
        if(current->left){
            parent_track[current->left]=current;
            queue.push(current->left);
        }
        if(current->right){
            parent_track[current->right]=current;
            queue.push(current->right);
        }
    }
}
vector<int> distancek(node* root,node* target, int k){
    unordered_map<node*,bool> visited;
    queue<node*> queue;
    queue.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!queue.empty()){
        int size=queue.size();
        if(curr_level++ == k) break;
        for(int i=0 ; i<size ; i++){
            node* current=queue.front();
            queue.pop();
            if(current->left && !visited[current->left]){
                queue.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right]){
                queue.push(current->right);
                visited[current->right]=true;
            }
        }
    }
    vector<int> res;
    while(!queue.empty()){
        node* current=queue.front();
        queue.pop();
        res.push_back(current->data);
    }
    return res;
}
int main()
{   struct node* root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);
    root->left->right=newnode(50);
    root->right->left=newnode(60);
    root->right->right=newnode(70);
    
    return 0;
} 