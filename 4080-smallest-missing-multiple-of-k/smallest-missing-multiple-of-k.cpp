/*
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                s.insert(nums[i]);
            }
        }
        int multiple=k;
        while(true){
            if(s.find(multiple)==s.end()){
                return multiple;
            }
            multiple=multiple+k;
        }
    }
};
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> check(n+2,0);
        for(int i=0;i<n;i++){
            if(nums[i]%k==0 && nums[i]/k<=n+1){
                check[nums[i]/k]=1;
            }
        }
        for(int i=1;i<=n+1;i++){
            if(check[i]==0){
                return i*k;
            }
        }
        return -1;
    }
};