class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int low=arr[0];
        int high=arr[0];
        int n=arr.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            low=min(low,arr[i]);
            high=max(high,arr[i]);
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(function(arr,m,k,n,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool function(vector<int>& arr, int m, int k,int n,int time){
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(time>=arr[i]){
                cnt++;
            }
            else{
                ans=ans+cnt/k;
                cnt=0;
            }
        }
        ans=ans+cnt/k;
        if(ans>=m) return true;
        else return false;
    }
};