class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int>mpp;//sum,freq;
        int n=nums.size();
        int i=0;
        int j=1;
        while(j<n){
            int sum=nums[i]+nums[j];
            if(mpp.find(sum)==mpp.end()){
                    mpp[sum]++;
                }
                else{
                    mpp[sum]++;
                    if(mpp[sum]==2){
                        return true;
                    }
                }
                i++;
                j++;
            }
        return false;
    }
};