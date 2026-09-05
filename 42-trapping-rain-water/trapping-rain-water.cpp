class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        leftmax[0]=arr[0];
        rightmax[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            leftmax[i]=max(arr[i],leftmax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(arr[i],rightmax[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]<leftmax[i] && arr[i]<rightmax[i]){
                ans+=min(leftmax[i],rightmax[i])-arr[i];
            }
        }
        return ans;
    }
};