class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            long long prod=1;
            long long l=1;
            long long g=0;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                if(prod>25200) break;
                g=gcd(g,(long long)nums[j]);
                l=lcm(l,(long long)nums[j]);
                if(prod==g*l){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};