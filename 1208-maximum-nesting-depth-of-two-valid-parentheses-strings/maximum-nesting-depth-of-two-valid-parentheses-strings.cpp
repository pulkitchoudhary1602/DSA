class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int d=0;
        int n=s.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ans[i]=d%2;
                d++;
            }
            else{
                d--;
                ans[i]=d%2;
            }
        }
        return ans;
    }
};