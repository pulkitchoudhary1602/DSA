class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int n=nums.size();
        fun(ans,tmp,nums,n,0);
        return ans;
    }
    void fun(vector<vector<int>>&ans, vector<int>&tmp,vector<int>& nums,int n,int i){
        if(tmp.size()==n){
            ans.push_back(tmp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(find(tmp.begin(), tmp.end(), nums[j]) != tmp.end()){
                continue;
            }
                tmp.push_back(nums[j]);
                fun(ans,tmp,nums,n,j);
                tmp.pop_back();
            
        }
    }
};