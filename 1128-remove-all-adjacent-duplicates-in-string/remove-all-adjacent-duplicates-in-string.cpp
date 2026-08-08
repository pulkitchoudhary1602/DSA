class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        for(auto ch:s){
            if(st.empty() || st.top()!=ch){
                st.push(ch);
                ans.push_back(ch);
            }
            else{
                st.pop();
                ans.pop_back();
            }
        }
        return ans;
    }
};