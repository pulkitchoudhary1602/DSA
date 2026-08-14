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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        function(root,targetSum,ans,temp,0);
        return ans;
    }
    void function(TreeNode*root,int target,vector<vector<int>>&ans,vector<int>&temp,int sum){
        if(root==NULL) return;
        sum=sum+root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        function(root->left,target,ans,temp,sum);
        function(root->right,target,ans,temp,sum);
        temp.pop_back();
    }
};