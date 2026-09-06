/*
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
       int n=arr.size();
       vector<int>nse(n);
       vector<int>pse(n);
       fnse(arr,nse,n);
       fpse(arr,pse,n);
       int maxi=0;
       for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]*(nse[i]-pse[i]-1));
       }
       return maxi; 
    }
    void fnse(vector<int>& arr,vector<int>& nse,int n){
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
    void fpse(vector<int>& arr,vector<int>& pse,int n){
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
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int num=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,(arr[num]*(i-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int num=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(arr[num]*(n-pse-1),maxi);
        }
        return maxi;
    }
};