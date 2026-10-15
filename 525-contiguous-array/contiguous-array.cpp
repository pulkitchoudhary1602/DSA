class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int sum=0;
        unordered_map<int,int>mpp;//sum,cnt
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1) sum+=1;
            else sum-=1;
            if(mpp.find(sum)!=mpp.end()){
                cnt=max(cnt,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return cnt;
    }
};