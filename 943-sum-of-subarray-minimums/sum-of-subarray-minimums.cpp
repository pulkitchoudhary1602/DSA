class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n);
        vector<int>pse(n);
        nsee(arr,nse,n);
        psee(arr,pse,n);
         int total=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            total=(total+(1ll*(nse[i]-i)*(i-pse[i])*arr[i])%mod)%mod;
        }
        return total;
    }
    void nsee(vector<int>&arr,vector<int>&nse,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
    }
    void psee(vector<int>&arr,vector<int>&pse,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
    }
};