class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        string fh="";
        string sh="";
        string mp="";
        for(int i=0;i<26;i++){
            char ch='a'+i;
            fh=fh+string(freq[i]/2,ch);

            if(freq[i]%2==1) mp=ch;
        }
        sh=fh;
        reverse(sh.begin(),sh.end());
        return fh+mp+sh;
    }
};