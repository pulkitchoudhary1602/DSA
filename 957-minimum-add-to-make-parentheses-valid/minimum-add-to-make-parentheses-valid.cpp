class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    ans++;
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
    }
};