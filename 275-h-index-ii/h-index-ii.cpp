class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0;
        int ans=-1;
        int high=citations[n-1];
        while(low<=high){
            int h=(low+high)/2;
            if(function(citations,h,n)){
                low=h+1;
                ans=h;
            }
            else{
                high=h-1;
            }
        }
        return ans;
    }
    bool function(vector<int>& citations,int h,int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(citations[i]<h) cnt++;
            else break;
        }
        if((n-cnt)>=h) return true;
        else return false;
    }
};