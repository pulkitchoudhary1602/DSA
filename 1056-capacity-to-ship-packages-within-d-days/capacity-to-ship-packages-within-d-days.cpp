class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=0;
        int high=0;
        int ans=0;
        for(int i=0;i<n;i++){
            low=max(low,weights[i]);
            high=high+weights[i];
        }
        while(low<=high){
            int limit=(low+high)/2;
            if(function(weights,days,limit,n)){
                high=limit-1;
                ans=limit;
            }
            else{
                low=limit+1;
            }
        }
        return ans;
    }
    bool function(vector<int>& weights, int days,int limit,int n){
        int cnt=1;
        int miniw=0;
        for(int i=0;i<n;i++){
            if(miniw+weights[i]<=limit){
                miniw=miniw+weights[i];
            }
            else{
                cnt++;
                miniw=weights[i];
                if(cnt>days) return false;
            }
        }
        return true;
    }
};