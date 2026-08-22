class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size(),l=0,r=0;
        unordered_set<int>st;
        while(r<n){
            if(r-l>k){
                st.erase(nums[l]);
                l++;
            }
            if(st.find(nums[r])!=st.end()){
                return true;
            }
            st.insert(nums[r]);
            r++;
        }
        return false;
    }
};