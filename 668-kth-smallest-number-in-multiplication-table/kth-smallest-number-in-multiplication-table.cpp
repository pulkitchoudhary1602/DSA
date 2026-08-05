class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int ans = high;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            int count = 0;
            for (int i = 1; i <= m; i++) {
                count += min(n, guess / i);
            }

            if (count >= k) {
                ans = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }

        return ans;
    }
};