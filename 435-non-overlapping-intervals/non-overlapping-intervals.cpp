class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int  n=arr.size();
        int cnt=0;
        int second=arr[0][1];
        for(int i=1;i<n;i++){
            int first=arr[i][0];
            if(second>first){
                cnt++;
                second=min(second,arr[i][1]);
            }
            else{
                second=arr[i][1];
            }
        }
        return cnt;
    }
};