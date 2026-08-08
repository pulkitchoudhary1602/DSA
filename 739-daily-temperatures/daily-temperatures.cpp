class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        ans[n-1]=0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.empty()==false && arr[i]>=arr[st.top()]){
                st.pop();
            }
            if(st.empty()==false){
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};