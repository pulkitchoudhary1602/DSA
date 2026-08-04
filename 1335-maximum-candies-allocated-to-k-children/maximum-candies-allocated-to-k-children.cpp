class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(candies, k, mid)) {
                ans = mid;
                low = mid + 1;      // try a larger size
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool possible(vector<int>& candies, long long k, int mid) {
        long long cnt = 0;

        for (int pile : candies) {
            cnt += pile / mid;
        }

        return cnt >= k;
    }
};