class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;//rem,count
        int n=nums.size();
        freq[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=(sum%k+k)%k;
            if(freq.find(rem)!=freq.end()){
                ans+=freq[rem];
            }
            freq[rem]++;
        }
        return  ans;
    }
};