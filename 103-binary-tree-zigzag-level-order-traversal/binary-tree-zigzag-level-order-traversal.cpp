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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans; 
       bool lefttoright=true;
 
        if (root == NULL) 
            return ans; 
 
        queue<TreeNode*> q; 
 
        q.push(root); 
 
        while (!q.empty()) { 
 
            int size = q.size(); 
 
            vector<int> level(size,0); 
            int first=0;
            int last=size-1;
 
            for (int i = 0; i < size; i++) { 
 
                TreeNode* node = q.front(); 
 
                q.pop(); 
 
                if(lefttoright){
                    level[first]=node->val;
                    first++;
                }
                else{
                    level[last]=node->val;
                    last--;
                }
 
                if (node->left != NULL) 
                    q.push(node->left); 
 
                if (node->right != NULL) 
                    q.push(node->right); 
            } 
            lefttoright=!lefttoright;
            ans.push_back(level); 
        } 
 
        return ans;  
    }
};