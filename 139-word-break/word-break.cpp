class Solution {
public:
    bool wordBreak(string s, vector<string>& arr) {
        vector<int>dp(s.size(),-1);
        return fun(arr,s,0,dp);
    }
    bool fun(vector<string>&arr,string &s,int idx,vector<int>&dp){
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        for(string word:arr){
            int len=word.size();
            if(s.substr(idx,len)==word){
                if(fun(arr,s,idx+len,dp)){
                    return dp[idx]= true;
                }
            }
        }
        return dp[idx]= false;
    }
};