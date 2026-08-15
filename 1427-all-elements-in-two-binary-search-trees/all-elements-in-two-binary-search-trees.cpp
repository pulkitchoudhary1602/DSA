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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        stack<TreeNode*>s1,s2;
        TreeNode* curr1=root1;
        TreeNode* curr2=root2;
        while(curr1!=NULL || curr2!=NULL || !s1.empty() || !s2.empty()){
            while(curr1!=NULL){
                s1.push(curr1);
                curr1=curr1->left;
            }
            while(curr2!=NULL){
                s2.push(curr2);
                curr2=curr2->left;
            }
            if(s2.empty() || (!s1.empty() && s1.top()->val<=s2.top()->val)){
                ans.push_back(s1.top()->val);
                curr1=s1.top()->right;
                s1.pop();
            }
            else{
                ans.push_back(s2.top()->val);
                curr2=s2.top()->right;
                s2.pop();
            }
        }
        return ans;
    }
};