class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";
        vector<string>ans;
        string tmp="";
        int n=digits.size();
        fun(f,ans,tmp,digits,n,0);
        return ans;
    }
    void fun(unordered_map<char,string>&f,vector<string>&ans,string &tmp,string digits,int n,int i){
        if(i==n){
            ans.push_back(tmp);
            return;
        }
        string choice=f[digits[i]];
        for(int j=0;j<choice.size();j++){
            tmp.push_back(choice[j]);
            fun(f,ans,tmp,digits,n,i+1);
            tmp.pop_back();
        }
    }
};