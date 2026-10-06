class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=-1,right=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                left=i;
                break;
            }
        }
        if(left==-1) return 0;
        for(int i=n-1;i>0;i--){
            if(arr[i]<arr[i-1]){
                right=i;
                break;
            }
        }
        int ans=min(n-left-1,right); //remove everything after prefix or remove everything before sufix
        int i=0;
        int j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};