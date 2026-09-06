class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>prefixsum(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='0') sum=0;
                else sum++;
                prefixsum[i][j]=sum;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,fun(prefixsum[i],m));
        }
        return maxi;
    }
    int fun(vector<int>arr,int n){
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int index=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,arr[index]*(i-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int index=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,arr[index]*(n-pse-1));
        }
        return maxi;
    }
};