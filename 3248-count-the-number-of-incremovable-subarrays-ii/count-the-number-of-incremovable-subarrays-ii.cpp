class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& arr) {
        int left=-1,right=-1;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]>=arr[i+1]){
                left=i;
                break;
            }
        }
        if(left==-1){
            return 1LL*n*(n+1)/2;
        }
        for(int i=n-1;i>0;i--){
            if(arr[i]<=arr[i-1]){
                right=i;
                break;
            }
        }
        long long ans=1;
        ans+=left+1;
        ans+=n-right;
        int i=0;
        int j=right;
        while(i<=left && j<n){
            if(arr[i]<arr[j]){
                ans+=n-j;
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};