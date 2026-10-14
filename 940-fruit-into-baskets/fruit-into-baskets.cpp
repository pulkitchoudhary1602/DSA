class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int n=arr.size();
        int l=0,r=0,maxi=0;
        while(r<n){
            mpp[arr[r]]++;
            if(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            if(mpp.size()<=2){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};