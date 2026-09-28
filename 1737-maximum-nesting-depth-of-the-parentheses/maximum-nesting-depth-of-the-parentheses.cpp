class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int maxi=0;
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
                maxi=max(open,maxi);
            }
            else if(s[i]==')'){
                open--;
            }
        }
        return maxi;
    }
};