class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mpp(26,0);
        int len=0,maxfreq=0,l=0,r=0;
        int n=s.size();
        int maxi=0;
        while(r<n){
            mpp[s[r]-'A']++;
            len=r-l+1;
            maxfreq=max(maxfreq,mpp[s[r]-'A']);
            while(len-maxfreq>k){
                mpp[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,mpp[i]);
                }
                l++;
                len=r-l+1;
            }
            if(len-maxfreq<=k){
                maxi=max(maxi,len);
            }
            r++;
        }
        return maxi;
    }
};