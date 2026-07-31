class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        int cnt=0;
        int mul=1;
        int ans=0;
        for(char ch:word){   //o(n)
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            else{
                if(cnt<8){
                    cnt++;
                    ans=ans+freq[i]*mul;
                }
                else{
                    mul=mul+1;
                    ans=ans+freq[i]*mul;
                    cnt=1;
                }
            }
        }
        return ans;
    }
};