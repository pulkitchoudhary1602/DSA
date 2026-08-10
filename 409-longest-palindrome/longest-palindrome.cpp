class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(52,0);
        bool flag=false;
        int ans=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z')
                freq[s[i]-'a']++;
            else
                freq[s[i]-'A'+26]++;
        }

        for(int i=0;i<52;i++){
            if(freq[i]%2==1){
                flag=true;
                ans=ans+freq[i]-1;
            }
            else{
                ans=ans+freq[i];
            }
        }

        if(flag) return ans+1;
        else return ans;
    }
};