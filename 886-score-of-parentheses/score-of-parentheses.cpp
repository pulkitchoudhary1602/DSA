class Solution {
public:
    int scoreOfParentheses(string s) {
         stack<int>st;
         st.push(0);
         int n=s.size();
         for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int first=st.top();
                st.pop();
                int score;
                if(first==0){
                    score=1;
                }
                else{
                    score=2*first;
                }
                st.top()+=score;
            }
         }
         return st.top();
    }
};