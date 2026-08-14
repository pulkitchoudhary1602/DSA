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
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        function(root,arr);
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            if(arr[left]+arr[right]==k) return true;
            else if(arr[left]+arr[right]<k) left++;
            else right--;
        }
        return false;
    }
    void function(TreeNode* root,vector<int>&arr){
        if(root==NULL) return;
        function(root->left,arr);
        arr.push_back(root->val);
        function(root->right,arr);
    }
};