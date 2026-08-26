class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string temp="",ans="";
        int one=0;
        int l=0,r=0,n=s.size();
        while(r<n){
            if(s[r]=='1') one++;
            while(one==k){
                temp=s.substr(l,r-l+1);
                if(ans.size()==0){
                    ans=temp;
                }
                else{
                    if(temp.size()<ans.size() || temp.size()==ans.size() && temp<ans){
                        ans=temp;
                    }
                }
                if(s[l]=='1') one--;
                l++;
                }
                r++;
            }
        return ans;
    }
};