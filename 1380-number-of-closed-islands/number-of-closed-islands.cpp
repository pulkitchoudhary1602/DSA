class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0) {
                    bool ans = true;
                    dfs(grid, vis, dx, dy, i, j, n, m, ans);
                    if (ans) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
             int dx[], int dy[], int i, int j,
             int n, int m, bool &closed) {

        vis[i][j] = 1;

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            closed = false;
        }

        for (int k = 0; k < 4; k++) {
            int nrow = dx[k] + i;
            int ncol = dy[k] + j;

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0) {

                dfs(grid, vis, dx, dy, nrow, ncol, n, m, closed);
            }
        }
    }
};
