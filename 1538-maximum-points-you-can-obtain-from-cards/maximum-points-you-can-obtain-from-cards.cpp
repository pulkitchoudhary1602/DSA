class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum=0;
        int rsum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            lsum+=arr[i];
        }
        maxi=max(maxi,lsum+rsum);
        int n=arr.size();
        int j=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=arr[i];
            rsum+=arr[j];
            maxi=max(maxi,lsum+rsum);
            j--;
        }
        return maxi;
    }
};