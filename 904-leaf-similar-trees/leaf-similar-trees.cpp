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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes1;
        vector<int> nodes2;
        function1(root1,nodes1);
        function2(root2,nodes2);
        int n1=nodes1.size();
        int n2=nodes2.size();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            if(nodes1[i]!=nodes2[i]) return false;
        }
        return true;
    }
    void function1(TreeNode* root1,vector<int>&nodes1){
        if(root1==NULL) return;
        if(root1->left==NULL && root1->right==NULL){
            nodes1.push_back(root1->val);
            return;
        }
        function1(root1->left,nodes1);
        function1(root1->right,nodes1);
    }
    void function2(TreeNode* root2,vector<int>&nodes2){
        if(root2==NULL) return;
        if(root2->left==NULL && root2->right==NULL){
            nodes2.push_back(root2->val);
            return;
        }
        function2(root2->left,nodes2);
        function2(root2->right,nodes2);
    }
};