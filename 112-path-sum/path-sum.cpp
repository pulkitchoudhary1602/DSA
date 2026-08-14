class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return function(root, 0, targetSum);
    }

    bool function(TreeNode* root, int sum, int target) {

        if(root == NULL)
            return false;

        sum = sum + root->val;

        if(root->left == NULL && root->right == NULL) {
            if(sum == target)
                return true;

            return false;
        }

        return function(root->left, sum, target) ||
               function(root->right, sum, target);
    }
};