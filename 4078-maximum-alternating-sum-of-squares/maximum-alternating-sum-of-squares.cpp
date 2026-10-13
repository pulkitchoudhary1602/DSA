class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>sq;
        for(int x:nums){
            sq.push_back(x*x);
        }
        sort(sq.begin(),sq.end(),greater<int>());
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<(n+1)/2){
                ans+=1ll*sq[i];
            }
            else{
                ans-=1ll*sq[i];
            }
        }
        return ans;
    }
};