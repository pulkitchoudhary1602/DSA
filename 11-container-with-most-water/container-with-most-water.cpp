class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r){
            int h=min(arr[l],arr[r]);
            int w=r-l;
            ans=max(ans,w*h);
            if(arr[l]<arr[r]) l++;
            else r--;
        }
    return ans;
    }
};