class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        // First column and last column
        for(int i = 0; i < n; i++) {

            if(board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }

            if(board[i][m-1] == 'O') {
                board[i][m-1] = '#';
                q.push({i, m-1});
            }
        }

        // First row and last row
        for(int j = 0; j < m; j++) {

            if(board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }

            if(board[n-1][j] == 'O') {
                board[n-1][j] = '#';
                q.push({n-1, j});
            }
        }

        // BFS
        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   board[nrow][ncol] == 'O') {

                    board[nrow][ncol] = '#';
                    q.push({nrow, ncol});
                }
            }
        }

        // Flip surrounded O's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};