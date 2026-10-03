class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        vector<pair<char,int>>v;
        for(auto it:freq){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string ans;
        for(auto it:v){
            ans.append(it.second,it.first);
        }
        return ans;
    }
};