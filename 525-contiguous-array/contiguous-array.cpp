class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),zero=0,one=0,res=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            else one++;
            int diff=zero-one;
            if(diff==0){
                res=max(res,i+1);
            }
            if(mpp.find(diff)==mpp.end()){
                mpp[diff]=i;
            }
            else{
                res=max(res,i-mpp[diff]);
            }
        }
        return res;
    }
};