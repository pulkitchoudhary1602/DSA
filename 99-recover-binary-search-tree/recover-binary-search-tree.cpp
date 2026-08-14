/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        function(root,prev,first,second);
        swap(first->val,second->val);
    }
    void function(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &second){
        if(root==NULL) return;
        function(root->left,prev,first,second);
        if(prev!=NULL && root->val<=prev->val){
            if(first==NULL) first=prev;
            second=root;
        }
        prev=root;
        function(root->right,prev,first,second);
    }
};