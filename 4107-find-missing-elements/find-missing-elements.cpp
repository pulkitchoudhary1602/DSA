class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int curr=nums[0];
        int last=nums[nums.size()-1];
        int i=1;
        vector<int>ans;
        while(curr<last){
            if(curr+1!=nums[i]){
                ans.push_back(curr+1);
                curr=curr+1;
            }
            else{
                curr=curr+1;
                i=i+1;
            }
        }
        return ans;
    }
};