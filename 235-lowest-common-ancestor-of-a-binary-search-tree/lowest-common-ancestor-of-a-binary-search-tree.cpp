/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        if(p->val <q->val) function(root,p,q,ans);
        else function(root,q,p,ans);
        return ans;
    }
    void function(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(root==NULL) return;
        if(root==p || root==q){
            ans=root;
            return;
        }
        if(root->val<p->val){
            function(root->right,p,q,ans);
        }
        else if(root->val>q->val){
            function(root->left,p,q,ans);
        }
        else{
            ans=root;
            return;
        }
    }
};