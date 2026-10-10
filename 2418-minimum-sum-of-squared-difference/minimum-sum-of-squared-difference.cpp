/*
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>arr(1e5+1,0);
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            arr[diff]++;
        }
        int k=k1+k2;
        for(int i=1e5;i>0;i--){
            int cnt=min(k,arr[i]);
            arr[i]-=cnt;
            arr[i-1]+=cnt;
            k-=cnt;
        }
        long long ans=0;
        for(long long i=0;i<=1e5;i++){
            ans+=i*i*arr[i];
        }
        return ans;
    }
};
*/
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>diff(n,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            maxi=max(maxi,diff[i]);
        }
        vector<int>arr(maxi+1,0);
        for(int i=0;i<n;i++){
            arr[diff[i]]++;
        }
        int k=k1+k2;
        for(int i=maxi;i>0;i--){
            if(arr[i]==0) continue;
            int countops=min(arr[i],k);
            arr[i]-=countops;
            arr[i-1]+=countops;
            k-=countops;
            if(k==0) break;
        }
        long long ans=0;
        for(long long i=0;i<=maxi;i++){
            ans+=i*i*arr[i];
        }
        return ans;
    }
};