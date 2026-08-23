class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int bemax=arr[0],bemin=arr[0],totalsum=arr[0],ansmax=arr[0],ansmin=arr[0],n=arr.size();
        for(int i=1;i<n;i++){
            totalsum+=arr[i];
            int v1=arr[i];
            int v2=arr[i]+bemax;
            int v3=arr[i]+bemin;
            bemax=max(v1,v2);
            bemin=min(v1,v3);
            ansmax=max(ansmax,bemax);
            ansmin=min(ansmin,bemin);
        }
        if (ansmax<0) return ansmax;
        return max(ansmax,totalsum-ansmin);
    }
};