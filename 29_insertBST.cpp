//insert node in BST

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root==nullptr) return new TreeNode(val);
        TreeNode *temp=root,*prev=nullptr;
        bool left=true;
        while(temp){
            if(temp->val<val){
                prev=temp;
                temp=temp->right;
                left=false;
            }
            else if(temp->val>val){
                prev=temp;
                temp=temp->left;
                left=true;
            }
        }
        if(left==true)
            prev->left=new TreeNode(val);
        else
            prev->right=new TreeNode(val);
        return root;
    }
};