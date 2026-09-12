// 


class Solution {
public:

    struct Node {
        long long score = 0;
        vector<int> idx;
    };

    vector<vector<Node>> dp;
    vector<vector<bool>> vis;

    Node fun(int i, int cnt,
             vector<vector<int>>& a,
             vector<int>& nextindex,
             int n) {

        // Base case
        if (i >= n || cnt == 4) {
            return {0, {}};
        }

        // Already calculated
        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = true;

        // -------------------
        // Skip
        // -------------------
        Node skip = fun(i + 1, cnt,
                        a, nextindex, n);

        // -------------------
        // Take
        // -------------------
        Node take = fun(nextindex[i], cnt + 1,
                        a, nextindex, n);

        take.score += a[i][2];

        // Keep indices sorted
        auto it = lower_bound(
            take.idx.begin(),
            take.idx.end(),
            a[i][3]
        );

        take.idx.insert(it, a[i][3]);

        // -------------------
        // Choose better
        // -------------------

        if (take.score > skip.score)
            return dp[i][cnt] = take;

        if (skip.score > take.score)
            return dp[i][cnt] = skip;

        // Same score
        if (take.idx < skip.idx)
            return dp[i][cnt] = take;

        return dp[i][cnt] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Step 1: Enumerate
        vector<vector<int>> a = intervals;

        for (int i = 0; i < n; i++) {
            a[i].push_back(i);
        }

        // Step 2: Sort
        sort(a.begin(), a.end(),
             [](const vector<int>& x,
                const vector<int>& y) {

                if (x[0] != y[0])
                    return x[0] < y[0];

                return x[3] < y[3];
             });

        // Step 3: Find next valid interval
        vector<int> nextindex(n, n);

        for (int i = 0; i < n; i++) {

            int low = i + 1;
            int high = n - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (a[mid][0] > a[i][1]) {
                    nextindex[i] = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        // DP table
        dp.assign(n + 1, vector<Node>(5));
        vis.assign(n + 1, vector<bool>(5, false));

        // Step 4: DP + Recursion
        Node result = fun(0, 0, a, nextindex, n);

        return result.idx;
    }
};