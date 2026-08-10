class Solution {
public:
    bool canConstruct(string s1, string s2) {

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int n1 = s1.size();
        int n2 = s2.size();

        int l = 0;
        int r = 0;

        while (l < n1 && r < n2) {

            if (s1[l] == s2[r]) {
                l++;
                r++;
            }
            else {
                r++;
            }
        }

        return l == n1;
    }
};