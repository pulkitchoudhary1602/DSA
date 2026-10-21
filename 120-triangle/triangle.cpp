/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(arr,n,0,0,dp);
    }
    int fun(vector<vector<int>>& arr,int n,int i,int j,vector<vector<int>>&dp){
        if(i==n-1){
            return arr[n-1][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int d=arr[i][j]+fun(arr,n,i+1,j,dp);
        int dr=arr[i][j]+fun(arr,n,i+1,j+1,dp);
        return dp[i][j]=min(d,dr);
    }
};
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n =arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=arr[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=arr[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};