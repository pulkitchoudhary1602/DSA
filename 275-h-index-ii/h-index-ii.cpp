class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=n-mid){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return n-low;
    }
};