class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1),hash(n);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(fun(words[i],words[prev]) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
    bool fun(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<s1.size()){
            if(j<s2.size()&&s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        else return false;
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
};