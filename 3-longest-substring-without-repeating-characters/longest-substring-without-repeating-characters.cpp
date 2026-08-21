class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int l=0,r=0,maxlen=0;
        while(r<n){
           mpp[s[r]]++;
           while(mpp[s[r]]>1){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
            l++;
           }
           if(mpp[s[r]]==1){
            maxlen=max(maxlen,r-l+1);
           }
           r++; 
        }
        return maxlen;
    }
};