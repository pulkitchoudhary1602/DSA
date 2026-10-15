class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               st.insert(nums[j]);
               cnt+=st.size()*st.size();
            }
            st.clear();
        }
        return cnt;
    }
};