/*
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int min=0;
        int max=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(max<0) return false;
            if(min<0) min=0;
        }
        return min==0;
    }
};
*/
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1)); //idx,cnt
        return fun(s,0,0,n,dp);
    }
    bool fun(string &s,int idx,int cnt,int n,vector<vector<int>>&dp){
        if(cnt<0) return false;
        if(idx==n){
            return cnt==0;
        }
        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        if(s[idx]=='('){
            return dp[idx][cnt]=fun(s,idx+1,cnt+1,n,dp);
        }
        else if(s[idx]==')'){
            return dp[idx][cnt]=fun(s,idx+1,cnt-1,n,dp);
        }
        else{
            return dp[idx][cnt]= (fun(s,idx+1,cnt+1,n,dp)||fun(s,idx+1,cnt-1,n,dp)||fun(s,idx+1,cnt,n,dp));
        }
    }
};