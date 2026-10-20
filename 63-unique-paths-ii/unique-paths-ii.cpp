/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(arr,n,m,n-1,m-1,dp);
    }
    int fun(vector<vector<int>>& arr,int n,int m,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(arr[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=fun(arr,n,m,i-1,j,dp);
        int left=fun(arr,n,m,i,j-1,dp);
        return dp[i][j]=up+left;
    }
};
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(arr[0][0]==1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int right=0;
                    int down=0;
                    if(j>0) right=dp[i][j-1];
                    if(i>0) down=dp[i-1][j];
                    dp[i][j]=right+down;
                }
            }
        }
        return dp[n-1][m-1];
    }
};