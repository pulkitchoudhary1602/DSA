/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            mini=min(mini,fun(arr,n,n-1,i,dp));
        }
        return mini;
    }
    int fun(vector<vector<int>>& arr,int n,int i,int j,vector<vector<int>>&dp){
        if(j<0 || j>=n) return 1e9;
        if(i==0) return arr[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=fun(arr,n,i-1,j,dp);
        int ul=fun(arr,n,i-1,j-1,dp);
        int ur=fun(arr,n,i-1,j+1,dp);
        return dp[i][j]= arr[i][j]+min({up,ul,ur});
    }
};
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=arr[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int d=dp[i-1][j];
                int dl=INT_MAX;
                int dr=INT_MAX;
               if(j-1>=0)  dl=dp[i-1][j-1];
                if(j+1<n)  dr=dp[i-1][j+1];
                dp[i][j]=arr[i][j]+min({d,dl,dr});
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};