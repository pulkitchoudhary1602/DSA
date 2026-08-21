class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mpp(26,0);
        int l=0,r=0,maxlen=0,maxfreq=0,n=s.size();
        while(r<n){
            mpp[s[r]-'A']++;
            maxfreq=max(maxfreq,mpp[s[r]-'A']);
            if(r-l+1-maxfreq>k){
                mpp[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};