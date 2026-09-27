class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string w = "";
        for (char c : s) {
            if (c == '(') {
                st.push(w);
                w = "";
            }
            else if (c == ')') {
                reverse(w.begin(), w.end());
                w = st.top() + w;
                st.pop();
            }
            else {
                w += c;
            }
        }
        return w;
    }
};