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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>q;
        bool check=false;
        q.push(root);
        while(q.empty()==false){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                check=true;
            }
            else{
                if(check) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};