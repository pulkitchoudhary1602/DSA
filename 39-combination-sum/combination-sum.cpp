class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int n=candidates.size();
        fun(ans,tmp,candidates,target,0,n);
        return ans;
    }
    void fun(vector<vector<int>>&ans,vector<int>&tmp,vector<int>& candidates, int target,int idx,int n){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        if(idx==n || target<0){
            return;
        }
        tmp.push_back(candidates[idx]);
        fun(ans,tmp,candidates,target-candidates[idx],idx,n);
        tmp.pop_back();
        fun(ans,tmp,candidates,target,idx+1,n);
    }
};