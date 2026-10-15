class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last=INT_MIN;
        int cnt=0;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]-1==last){
                cnt++;
                last=nums[i];
            }
            else if(nums[i]==last){
                continue;
            }
            else{
                cnt=1;
                last=nums[i];
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};