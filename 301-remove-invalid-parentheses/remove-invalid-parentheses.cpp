class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int index, int leftRemove, int rightRemove,
             int balance, string curr) {
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        if (ch == '(') {

            // Remove 
            if (leftRemove > 0) {
                dfs(s, index + 1, leftRemove - 1, rightRemove,
                    balance, curr);
            }

            // Keep 
            dfs(s, index + 1, leftRemove, rightRemove,
                balance + 1, curr + ch);
        }

        else if (ch == ')') {

            // Remove 
            if (rightRemove > 0) {
                dfs(s, index + 1, leftRemove, rightRemove - 1,
                    balance, curr);
            }

            // Keep 
            if (balance > 0) {
                dfs(s, index + 1, leftRemove, rightRemove,
                    balance - 1, curr + ch);
            }
        }

        else {
            dfs(s, index + 1, leftRemove, rightRemove,
                balance, curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int leftRemove = 0;
        int rightRemove = 0;
        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {

                if (balance > 0) {
                    balance--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        leftRemove = balance;

        dfs(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};