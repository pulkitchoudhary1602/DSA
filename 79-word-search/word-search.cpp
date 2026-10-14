class Solution {
public:
    bool exist(vector<vector<char>>& arr, string s) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==s[0]){
                    if(dfs(0,i,j,n,m,arr,s)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int idx,int r,int c,int n,int m,vector<vector<char>>& arr, string &s){
        if(idx==s.size()){
            return true;
        }
        if(r<0 || r>=n || c<0 || c>=m ||arr[r][c]!=s[idx]){
            return false;
        }
        char temp=arr[r][c];
        arr[r][c]='#';
        bool found=
        (dfs(idx+1,r,c-1,n,m,arr,s)||
        dfs(idx+1,r-1,c,n,m,arr,s)||
        dfs(idx+1,r,c+1,n,m,arr,s)||
        dfs(idx+1,r+1,c,n,m,arr,s));
        arr[r][c]=temp;
        return found;
    }
};