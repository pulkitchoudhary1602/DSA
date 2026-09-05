class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>pse(n);
        vector<int>nse(n);
        int ans=0;
        funnse(arr,nse,n);
        funpse(arr,pse,n);
        int mod=(int)(1e9+7);
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ans=(ans+(right*left*1ll*arr[i])%mod)%mod;
        }
        return ans;
    }
    void funnse(vector<int>&arr,vector<int>&nse,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }

    }
    void funpse(vector<int>&arr,vector<int>&pse,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }
};