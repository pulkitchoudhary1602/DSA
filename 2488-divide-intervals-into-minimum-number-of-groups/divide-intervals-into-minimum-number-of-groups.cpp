class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int>a,d;
        for(int i=0;i<n;i++){
            a.push_back(arr[i][0]);
            d.push_back(arr[i][1]);
        }
        sort(a.begin(),a.end());
        sort(d.begin(),d.end());
        int cnt=0;
        int maxi=0;
        int ar=0;
        int dp=0;
        while(ar<n){
            if(a[ar]<=d[dp]){
                cnt++;
                maxi=max(cnt,maxi);
                ar++;
            }
            else{
                cnt--;
                dp++;
            }
        }
        return maxi;
    }
};