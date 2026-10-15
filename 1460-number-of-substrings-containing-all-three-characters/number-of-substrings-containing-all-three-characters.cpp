class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int a=-1,b=-1,c=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            if(a!=-1 && b!=-1 && c!=-1){
                ans+=min({a,b,c})+1;
            }
        }
        return ans;
    }
};