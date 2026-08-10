class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        for(auto it:ransomNote)mp[it]++;
        
        for(auto it:magazine)mp1[it]++;
        
        for(auto it:mp){
            if(it.second>mp1[it.first])return false;
        }
        return true;
    }
};