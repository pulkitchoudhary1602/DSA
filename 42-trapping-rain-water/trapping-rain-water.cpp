class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>rightmax(n);
        int maxi=arr[0];
        rightmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(arr[i],rightmax[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            if(arr[i]<maxi && arr[i]<rightmax[i]){
                ans+=min(maxi,rightmax[i])-arr[i];
            }
        }
        return ans;
    }
};