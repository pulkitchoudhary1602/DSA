class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0, high = row - 1;
        int frow = -1;

        // Find the candidate row
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid][0] <= target) {
                frow = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (frow == -1)
            return false;

        // Binary search in that row
        int newlow = 0, newhigh = col - 1;

        while (newlow <= newhigh) {
            int mid = newlow + (newhigh - newlow) / 2;

            if (matrix[frow][mid] == target)
                return true;
            else if (matrix[frow][mid] > target)
                newhigh = mid - 1;
            else
                newlow = mid + 1;
        }

        return false;
    }
};