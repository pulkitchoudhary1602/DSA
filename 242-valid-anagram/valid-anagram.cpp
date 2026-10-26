class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            freq[t[i]-'a']--;
        }
        for(auto it:freq){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};